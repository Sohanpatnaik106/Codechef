#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int l, r, m;
        cin >> l >> r >> m;

        bool got_ans = false;
        int diff;
        int a, b, c;
        for(int i = max(m + l - r, 1); i <= (m + r - l); i++) {
            for(int j = l; j <= r; j++) {
                if(i % j == 0) {
                    diff = i - m;
                    got_ans = true;
                    a = j;
                    break;
                }
            }
            if(got_ans) {
                break;
            }
        }
        if(diff < 0) {
            b = r;
            c = b + diff;
        }
        else {
            b = l;
            c = b + diff;
        }
        
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}