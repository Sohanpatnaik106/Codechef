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
        vector<int> a(n);
        int min_val = INT32_MAX;
        int index;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < min_val) {
                min_val = a[i];
                index = i;
            }
        }
        int max_operations = 0;
        for(int i = 0; i < n; i++) {
            if(i != index) {
                max_operations = max_operations + ((k - a[i]) / min_val);
            }
        }
        cout << max_operations << "\n";
    }
    return 0;
}