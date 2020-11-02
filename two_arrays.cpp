#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, T;
        cin >> n >> T;

        vector<int> a(n), p(n);
        int count = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(2 * a[i] < T) {
                p[i] = 0;
            }
            else if(2 * a[i] > T) {
                p[i] = 1;
            }
            else {
                count++;
            }
        }

        int temp_count = 1;
        for(int i = 0; i < n; i++) {
            if(2 * a[i] == T && 2 * temp_count <= count) {
                p[i] = 1;
                temp_count++;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}