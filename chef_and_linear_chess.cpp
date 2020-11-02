#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n, k;
    while(t--) {
        cin >> n >> k;
        vector<int> P(n);
        for(int i = 0; i < n; i++) {
            cin >> P[i];
        }

        int min_moves = INT32_MAX;
        int flag = -1;
        for(int i = 0; i < n; i++) {
            if(k % P[i] == 0) {
                if((k/P[i]) < min_moves) {
                    flag = P[i];
                    min_moves = k/P[i];
                }
            }
        }
        cout << flag << "\n";
    }
}