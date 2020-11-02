#include"bits/stdc++.h"
#define ll long long
using namespace std;

ll compute_cost(vector<ll> a, ll x) {
    ll y = 1;
    ll cost = 0;
    for(ll i = 0; i < a.size(); i++) {
        cost = cost + abs(a[i] - y);
        y = y * x;
    }
    return cost;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll x = 1;

    ll f1 = compute_cost(a, 2);
    ll min_cost = INT64_MAX;
    while(pow(x, n-1) <= a[n-1] + f1) {
        ll k = compute_cost(a, x);
        if(k <= min_cost) {
            min_cost = k;
        }
        x++;
    }

    cout << min_cost << "\n";

    return 0;
}