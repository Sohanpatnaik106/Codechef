#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;
    cin >> t;
    
    while(t--) {
        cin >> k;

        int row = (k-1) / 8;
        int col = (k-1) % 8;

        int A[8][8];
        int ctr = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(ctr < k) {
                    A[i][j] = 1;
                }
                else {
                    A[i][j] = 0;
                }
                ctr++;
            }
        }

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(i == 0 && j == 0) {
                    cout << "O";
                } 
                else {
                    if(A[i][j] == 1) {
                        cout << ".";
                    }
                    else if(A[i][j] == 0) {
                        cout << "X";
                    }
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}