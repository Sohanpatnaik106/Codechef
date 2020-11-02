#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        unordered_map<int, int> umap;
        int inefficiency = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(k == 1) {
            inefficiency = 1;
            for(int i = 0; i < n; i++) {
                if(umap.find(a[i]) != umap.end()) {
                    inefficiency++;
                    umap.clear();
                    umap.insert(make_pair(a[i], 1));
                }
                else {
                    umap.insert(make_pair(a[i], 1));
                }
            }
        }
        else {
            int group_matrix[n+1][n+1] = {0};
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    group_matrix[i][j] = 0;
                }
            }
            for(int i = 0; i < n; i++) {
                umap.clear();
                for(int j = i; j < n; j++) {
                    group_matrix[i][j] = (j == 0) ? 0 : group_matrix[i][j-1];
                    if(umap.count(a[j])) {
                        if(umap[a[j]] == 1) {
                            group_matrix[i][j]++;
                        }
                        group_matrix[i][j]++;
                    }
                    umap[a[j]]++;
                }
            }
            inefficiency = INT32_MAX;
            int total_tables = 100;
            int inefficiency_matrix[101][1001] = {0};
            for(int i = 0; i <= total_tables; i++) {
                for(int j = 0; j <= total_tables; j++) {
                    inefficiency_matrix[i][j] = 0;
                }
            } 
            for(int i = 1; i < n+1; i++) {
                inefficiency_matrix[1][i] = group_matrix[0][i-1];
            }
            for(int i = 2; i <= total_tables; i++) {
                inefficiency_matrix[i][1] = 0;
            }
            for(int i = 2; i <= total_tables; i++) {
                for(int j = 2; j <= n; j++) {
                    int min_inefficiency = INT32_MAX;
                    for(int p = 1; p < j; p++) {
                        min_inefficiency = min(min_inefficiency, inefficiency_matrix[i-1][p] + group_matrix[p][j-1]);
                    }
                    inefficiency_matrix[i][j] = min_inefficiency;
                }
            }
            for(total_tables = 1; total_tables <= 100; total_tables++) {
                inefficiency = min(total_tables * k + inefficiency_matrix[total_tables][n], inefficiency);
            }
        }
        cout << inefficiency << "\n";
        
    }
    return 0;
}