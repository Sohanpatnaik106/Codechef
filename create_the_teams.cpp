#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int no_of_teams = 0, cur = 1;
        for(int i = 0; i < n; i++) {
            if((a[i] * cur) >= x) {
                no_of_teams++;
                cur = 0;
            }
            cur++;
        }
        cout << no_of_teams << "\n";
    }
    return 0;
}