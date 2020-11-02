#include"bits/stdc++.h"
#define ll long long
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll m;
    cin >> m;
    ll choice;
    vector<ll> normal_sum(n+1, 0), sorted_sum(n+1, 0);
    normal_sum[0] = 0;

    for(ll i = 1; i < n+1; i++) {
        normal_sum[i] = normal_sum[i-1] + v[i-1];
    }

    sort(v.begin(), v.end());
    sorted_sum[0] = 0;

    for(ll i = 1; i < n+1; i++) {
        sorted_sum[i] = sorted_sum[i-1] + v[i-1];
    }

    ll l, r;
    while(m--) {
        cin >> choice >> l >> r;
        if(choice == 1) {
            cout << normal_sum[r] - normal_sum[l-1] << "\n";
        }
        else if(choice == 2) {
            cout << sorted_sum[r] - sorted_sum[l-1] << "\n";
        }
    }
    return 0;
}