#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        long long int A[n], B[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i] >> B[i];
        }

        int sum_a = 0, sum_b = 0;
        int points_a = 0, points_b = 0;

        for(int i = 0; i < n; i++) {
            sum_a = 0;
            sum_b = 0;
            
            while(A[i] > 0) {
                sum_a = sum_a + (A[i] % 10);
                A[i] = A[i] / 10;
            }
            while(B[i] > 0) {
                sum_b = sum_b + (B[i] % 10);
                B[i] = B[i] / 10;
            }

            if(sum_a > sum_b) {
                points_a++;
            }
            else if(sum_b > sum_a) {
                points_b++;
            }
            else {
                points_a++;
                points_b++;
            }
        }
        
        if(points_a > points_b) {
            cout << "0 " << points_a << "\n";
        }
        else if(points_b > points_a) {
            cout << "1 " << points_b << "\n";
        }
        else {
            cout << "2 " << points_a << "\n";
        }
    }
    return 0;
}