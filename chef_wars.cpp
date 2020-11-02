#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int h, p;
    while(t--) {
        cin >> h >> p;
        int flag = 0;
        while(p > 0) {
            h = h - p;
            p = p/2;
            if(h <= 0) {
                flag = 1;
                break;
            }
        }
        cout << flag << "\n";
    }
    return 0;
}