#include"bits/stdc++.h"
#define ll long long
using namespace std;

ll power(ll x, ll y, ll p) {
    ll res = 1;  
  
    x = x % p; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
  
        y = y >> 1;  
        x = (x * x) % p; 
    } 
    return res;
}

ll ncr(ll n, ll r, ll p) {
    vector<ll> fact(n+1);
    fact[0] = 1;
    for(ll i = 1; i < n+1; i++) {
        fact[i] = (fact[i-1] * i) % p;
    }

    return ((((fact[n] % p) * (power(fact[r], p-2, p) % p) % p) * (power(fact[n-r], p-2, p) % p) % p) + p) % p ;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll p = 1000000007;

    ll k;
    cin >> k;

    vector<ll> c(k);
    vector<int> n(k, 0);
    for(ll i = 0; i < k; i++) {
        cin >> c[i];
        if(i != 0) {
            n[i] = n[i-1] + c[i];
        }
        else {
            n[i] = c[i];
        }
    }

    vector<ll> count(k);

    for(ll i = 0; i < k; i++) {
        if(i != 0) {
            count[i] = (((ncr(n[i] - 1, c[i] - 1, p) * count[i-1]) % p) + p) % p;
        }
        else {
            count[i] = 1;
        }
    }

    cout << count[k-1] << "\n";

    return 0;
}