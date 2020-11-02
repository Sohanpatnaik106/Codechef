#include"bits/stdc++.h"
using namespace std;

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

        int skips = 0;

        if(a[0] == 1) {
            skips++;
        }

        for(int i = 1; i < n; i++) {
            if(a[i] == 0) {
                continue;
            }
            int j = i;
            while(j < n && a[j] == 1) {
                j++;
            }
            skips = skips + ((j-i) / 3);
            i = j;
        }


        cout << skips << "\n";
    }
    return 0;
}