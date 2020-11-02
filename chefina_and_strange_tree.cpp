#include"bits/stdc++.h"
using namespace std;

void euler_tree(vector<int> &vis, int u, int v, vector<vector<int>> &adjacency_list, vector<int> &B, vector<int> &A, vector<int> &D, int index) {
    if(B[v] == 0) {
        goto label;
    }

    if(vis[v] != 1) {
        B[v] = B[v] - min(B[v], A[u]);
        vis[v] = 1;
    }

    if(B[v] == 0) {
        D[v] = index;
    }

    label :
    for(int i = 0; i < adjacency_list[v].size(); i++) {
        if(!vis[adjacency_list[v][i]]) {
            euler_tree(vis, u, adjacency_list[v][i], adjacency_list, B, A, D, index);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int u, v;
        vector<vector<int>> adjacency_list(n+1);
        for(int i = 0; i < n-1; i++) {
            cin >> u >> v;
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
        }
        vector<int> P(n+1), A(n+1), B(n+1);
        for(int i = 1; i < P.size(); i++) {
            cin >> P[i];
        }
        for(int i = 1; i < A.size(); i++) {
            cin >> A[i];
        }
        for(int i = 1; i < B.size(); i++) {
            cin >> B[i];
        }

        vector<int> D(n+1, -1);
        for(int i = 1; i < P.size(); i++) {
            vector<int> vis(n+1, 0);
            euler_tree(vis, P[i], P[i], adjacency_list, B, A, D, i);
            for(int j = 0; j < adjacency_list[P[i]].size(); j++) {
                adjacency_list[adjacency_list[P[i]][j]].erase(find(adjacency_list[adjacency_list[P[i]][j]].begin(), adjacency_list[adjacency_list[P[i]][j]].end(), P[i]));
            }
            adjacency_list[P[i]].clear();
        }
        for(int i = 1; i < D.size(); i++) {
            cout << D[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}