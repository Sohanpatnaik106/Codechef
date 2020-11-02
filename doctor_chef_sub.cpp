#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t;
    cin >> t;

    while(t--) {
        long long int n, x;
        cin >> n >> x;

        long long int k;
        int A[n];
        for(long long int i = 0; i < n; i++) {
            cin >> A[i];
        }
        long long int no_of_days = 0;

        if(x >= A[0]) {
            no_of_days = n;
        }
        else {
            while(x < ((double)A[0])/2) {
                no_of_days++;
                x = 2 * x;
            }
            no_of_days = no_of_days + n + 1;
        }

        cout << no_of_days << "\n";
    }
    return 0;
}