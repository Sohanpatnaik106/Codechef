#include"bits/stdc++.h"
#include"string"
#define ll long long
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        ll x;
        cin >> x;

        ll n = s.size();
        ll l, r;
        
        string w;
        w = s;
        for(int i = 0; i < n; i++) {
            w[i] = '1';
        }

        for(int i = 0; i < n; i++) {
            l = i-x, r = i+x;
            if(l < 0 && r < n) {
                if(s[i] == '0') {
                    w[r] = '0';
                } 
            }
            else if(l >= 0 && r >= n) {
                if(s[i] == '0') {
                    w[l] = '0';
                }
            }
            else if(l >= 0 && r < n) {
                if(s[i] == '0') {
                    w[l] = '0';
                    w[r] = '0';
                }
            }
        }

        string str = w;
        for(int i = 0; i < n; i++) {
            l = i-x, r = i+x;
            if(l < 0 && r < n) {
                if(w[r] == '1') {
                    str[i] = '1';
                }
                else {
                    str[i] = '0';
                }
            }
            else if(l >= 0 && r > n-1) {
                if(w[l] == '1') {
                    str[i] = '1';
                }
                else {
                    str[i] = '0';
                }
            } 
            else if(l >= 0 && r < n) {
                if(w[l] == '1' || w[r] == '1') {
                    str[i] = '1';
                }
                else {
                    str[i] = '0';
                }
            }
            else {
                str[i] = '0';
            }
        }

        if(str == s) {
            cout << w;
        }
        else {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}