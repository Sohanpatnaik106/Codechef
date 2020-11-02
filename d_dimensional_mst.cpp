#include"bits/stdc++.h"
//typedef pair<int, int> pair<int, int>;
using namespace std;

struct Graph {
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST(int n);
};

struct DisjointSets {
    int *parent, *rank;
    int n;

    DisjointSets(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for(int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
        if(rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

int Graph :: kruskalMST(int n) {
    int mst_wt = 0;
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    DisjointSets ds(V);

    vector<pair<int, pair<int, int>>> :: iterator it;
    int no_of_edges = 0;
    for(it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            mst_wt = mst_wt + it->first;
            ds.merge(set_u, set_v);
            no_of_edges++;
        }

        if(no_of_edges == n-1) {
            break;
        }
    }
    return mst_wt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<vector<int>> point_coordinates(n+1, vector<int> (d+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= d; j++) {
            cin >> point_coordinates[i][j];
        }
    }

    Graph g(n, (n * (n-1)) / 2);
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int cost = 0;
            for(int k = 1; k <= d; k++) {
                cost = cost + abs(point_coordinates[i][k] - point_coordinates[j][k]);
            }
            g.addEdge(i, j, cost);
        }
    }

    int mst_wt = g.kruskalMST(n);

    cout << mst_wt << "\n";
    
    return 0;
}