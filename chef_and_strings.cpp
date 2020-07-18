#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    long long int n;
    cin >> t;

    while(t--) {
        cin >> n;
        long long int A[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        long long int no_of_left_strings = 0;
        for(int i = 0; i < n-1; i++) {
            if(A[i+1] < A[i]) {
                no_of_left_strings = no_of_left_strings + A[i] - A[i+1] - 1;
            }
            else {
                no_of_left_strings = no_of_left_strings + A[i+1] - A[i] - 1;
            }
        }
        cout << no_of_left_strings << "\n";
    }
    return 0; 
}