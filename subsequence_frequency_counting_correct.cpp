#include"bits/stdc++.h"
using namespace std;

vector<vector<int>> ncr_matrix(int n, int p) {
    vector<vector<int>> calc_ncr(n+1, vector<int> (n+1, 0));
    for(int i = 0; i < n; i++) {
        calc_ncr[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            calc_ncr[i][j] = (calc_ncr[i-1][j-1] + calc_ncr[i-1][j]) % p;
        }
    }
    return calc_ncr;
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p = 1000000007;
        vector<vector<int>> calc_ncr = ncr_matrix(n, p);

        unordered_map<int, int> umap;
        for(int i = 1; i <= n; i++) {
            umap.insert(make_pair(i, 0));
        }
        for(int i = 0; i < n; i++) {
            umap[a[i]]++;
        }
        vector<int> store_freq;
        for(int i = 1; i <= n; i++) {
            if(umap.find(i)->second == 0) {
                store_freq.push_back(0);
                continue;
            }
            int freq_count = 0;
            int freq = 1;
            int sum_combi = 0;
            int num_occur = umap.find(i)->second; 
            for(int j = 1; j <= num_occur; j++) {
                freq = 1;
                for(int k = i+1; k <= n; k++) {
                    sum_combi = 0;
                    int alpha = umap.find(k)->second;
                    if(alpha == 0) {
                        continue;
                    }
                    int count = (alpha > j) ? j : alpha;
                    for(int l = 0; l <= count; l++) {
                        sum_combi = (sum_combi + calc_ncr[alpha][l]) % p;
                    }
                    freq = (freq * sum_combi) % p;
                }
                for(int k = 1; k < i; k++) {
                    sum_combi = 0;
                    int alpha = umap.find(k)->second;
                    if(alpha == 0) {
                        continue;
                    }
                    int count = (alpha > j-1) ? j-1 : alpha;
                    for(int l = 0; l <= count; l++) {
                        sum_combi = (sum_combi + calc_ncr[alpha][l]) % p;
                    }
                    freq = (freq * sum_combi) % p;
                }
                freq_count = (freq_count + (calc_ncr[num_occur][j] * freq) % p) % p;
            }
            store_freq.push_back(freq_count);
        }

        for(int i = 0; i < n; i++) {
            cout << store_freq[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}