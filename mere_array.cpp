#include"bits/stdc++.h"
#define ll long long
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), sorted_a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
            sorted_a[i] = a[i];
        }
        sort(sorted_a.begin(), sorted_a.end());

        ll min_val = sorted_a[0];
        ll flag = 1;
        for(ll i = 0; i < n; i++) {
            if((a[i] != sorted_a[i]) && (a[i] % min_val != 0)) {
                flag = 0;
            }
        }
        if(flag == 1) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}