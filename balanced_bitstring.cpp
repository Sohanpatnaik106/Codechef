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
        string s;
        cin >> s;

        vector<char> info(k);
        bool ans = true;
        for(int i = 0; i < k; i++) {
            bool flag = false;
            for(int j = i; j < n; j+=k) {
                if(s[j] != '?') {
                    info[i] = s[j];
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                info[i] = '?';
            }
            if(flag) {
                for(int j = i; j < n; j+=k) {
                    if(s[j] != info[i] && s[j] != '?') {
                        ans = false;
                        break;
                    }
                }
            }
            if(!ans) {
                break;
            }
        }
        if(ans) {
            for(int i = 0; i < k; i++) {
                for(int j = i; j < n; j+=k) {
                    if(info[i] != '?' ) {
                        s[j] = info[i];
                    }
                }
            }
        }
        int no_1 = 0, no_0 = 0, no_q = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == '0') {
                no_0++;
            }
            else if(s[i] == '1') {
                no_1++;
            }
            else {
                no_q++;
            }
        }
    
        if(no_1 > k/2 || no_0 > k/2) {
            ans = false;
        }

        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}