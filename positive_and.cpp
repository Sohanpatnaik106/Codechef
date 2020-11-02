#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n+1, 0);
        for(int i = 1; i < n+1; i++) {
            p[i] = i;
        }

        bool possible = true;

        if(n == 1) {
            p[1] = 1;
        }
        else if(n == 2) {
            possible = false;
        }
        else if(n == 3) {
            p[1] = 2;
            p[2] = 3;
            p[3] = 1;
        }
        else if(n == 4) {
            possible = false;
        }
        else if(n == 5) {
            p[1] = 2;
            p[2] = 3;
            p[3] = 1;
            p[4] = 5;
            p[5] = 4;
        }
        else {
            p[1] = 2;
            p[2] = 3;
            p[3] = 1;
            p[4] = 5;
            p[5] = 4;
            int y = 4;
            while(y * 2 <= n) {
                y = y * 2;
                if(y == n) {
                    possible = false;
                }
                else {
                    p[y] = y+1;
                    p[y+1] = y;
                }
            }
        }

        if(possible) {
            for(int i = 1; i < n+1; i++) {
                cout << p[i] << " ";
            }
        }
        else {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}