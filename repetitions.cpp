#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int max_len = 1;
    int ctr = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) {
            ctr++;
        }
        else {
            if(ctr > max_len) {
                max_len = ctr;
            }
            ctr = 1;
        }
    }

    if(ctr > max_len) {
        max_len = ctr;
    }

    cout << max_len << "\n";
    return 0;
}