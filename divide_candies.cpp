#include"bits/stdc++.h"
using namespace std;

int main() {
    /*ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); */

    int k;
    cin >> k;

    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        if(k == 1) {
            long long sum = (n * (n+1)) / 2;
            long long half_sum = sum / 2;

            vector<long long> distribution(n+1, 0);
            long long index = n;
            while(half_sum - index >= 0) {
                half_sum = half_sum - index;
                distribution[index] = 1;
                index--;
            }
            if(half_sum != 0) {
                distribution[half_sum] = 1;
            }
            if(n % 4 == 1 || n % 4 == 2) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
            for(long long i = 1; i < n+1; i++) {
                cout << distribution[i];
            }
            cout << "\n";
        }
        else if(k == 2) {
            vector<long long> distribution(n+1, 0);
            long long diff;
            if(n == 1) {
                distribution[1] = 1;
                diff = 1;
            }
            else if(n == 2) {
                distribution[1] = 1;
                diff = 3;
            } 
            else if(n == 3) {
                distribution[1] = 1;
                distribution[2] = 1;
                diff = 4;
            }
            else if(n == 4) {
                distribution[1] = 1;
                distribution[2] = 1;
                distribution[3] = 1;
                diff = 2;
            }
            else if(n == 5) {
                distribution[1] = 1;
                distribution[5] = 1;
                diff = 3;
            }
            else if(n == 6) {
                distribution[3] = 1;
                distribution[6] = 1;
                diff = 1;
            }
            else if(n == 7) {
                distribution[1] = 1;
                distribution[2] = 1;
                distribution[4] = 1;
                distribution[7] = 1;
                diff = 0;
            }
            else if(n == 8) {
                distribution[1] = 1;
                distribution[4] = 1;
                distribution[6] = 1;
                distribution[7] = 1;
                diff = 0;
            }
            else if(n == 9) {
                distribution[5] = 1;
                distribution[6] = 1;
                distribution[9] = 1;
                diff = 1;
            }
            else if(n == 10) {
                distribution[10] = 1;
                distribution[8] = 1;
                distribution[5] = 1;
                distribution[2] = 1;
                diff = 1;
            }
            else if(n == 11) {
                distribution[1] = 1;
                distribution[3] = 1;
                distribution[4] = 1;
                distribution[5] = 1;
                distribution[9] = 1;
                distribution[11] = 1;
                diff = 0;
            }
            else if(n == 12) {
                distribution[9] = 1;
                distribution[10] = 1;
                distribution[12] = 1;
                diff = 0;
            }
            else if(n == 13) {
                distribution[4] = 1;
                distribution[9] = 1;
                distribution[12] = 1;
                distribution[13] = 1;
                diff = 1;
            }
            else if(n == 14) {
                distribution[1] = 1;
                distribution[2] = 1;
                distribution[4] = 1;
                distribution[11] = 1;
                distribution[13] = 1;
                distribution[14] = 1;
                diff = 1;
            }
            else if(n == 15) {
                distribution[6] = 1;
                distribution[7] = 1;
                distribution[8] = 1;
                distribution[9] = 1;
                distribution[10] = 1;
                distribution[11] = 1;
                distribution[13] = 1;
                diff = 0;
            } 
            else if(n == 16){
                distribution[4] = 1;
                distribution[6] = 1;
                distribution[14] = 1;
                distribution[10] = 1;
                distribution[12] = 1;
                distribution[16] = 1;
                diff = 0;
            }
            else if(n/8 > 1 && n % 8 == 1) {
                distribution[5] = 1;
                distribution[6] = 1;
                distribution[9] = 1;
                long long k = n/8;
                long long index = 10;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 1;
                }
            }
            else if(n/8 > 1 && n % 8 == 2) {
                distribution[10] = 1;
                distribution[8] = 1;
                distribution[5] = 1;
                distribution[2] = 1;
                long long k = n/8;
                long long index = 11;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 1;
                }
            }
            else if(n/8 > 1 && n % 8 == 3) {
                distribution[1] = 1;
                distribution[3] = 1;
                distribution[4] = 1;
                distribution[5] = 1;
                distribution[9] = 1;
                distribution[11] = 1;
                long long k = n/8;
                long long index = 12;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 0;
                }
            }
            else if(n/8 > 1 && n % 8 == 4) {
                distribution[9] = 1;
                distribution[10] = 1;
                distribution[12] = 1;
                long long k = n/8;
                long long index = 13;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 0;
                }
            }
            else if(n/8 > 1 && n % 8 == 5) {
                distribution[4] = 1;
                distribution[9] = 1;
                distribution[12] = 1;
                distribution[13] = 1;
                long long k = n/8;
                long long index = 14;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 1;
                }
            }
            else if(n/8 > 1 && n % 8 == 6) {
                distribution[1] = 1;
                distribution[2] = 1;
                distribution[4] = 1;
                distribution[11] = 1;
                distribution[13] = 1;
                distribution[14] = 1;
                long long k = n/8;
                long long index = 15;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 1;
                }
            }
            else if(n/8 > 1 && n % 8 == 7) {
                distribution[6] = 1;
                distribution[7] = 1;
                distribution[8] = 1;
                distribution[9] = 1;
                distribution[10] = 1;
                distribution[11] = 1;
                distribution[13] = 1;
                long long k = n/8;
                long long index = 16;
                while(k > 1) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 0;
                }
            }
            else if(n/8 > 2 && n % 8 == 0) {
                distribution[4] = 1;
                distribution[6] = 1;
                distribution[14] = 1;
                distribution[10] = 1;
                distribution[12] = 1;
                distribution[16] = 1;
                long long k = n/8;
                long long index = 17;
                while(k > 2) {
                    distribution[index] = 1;
                    distribution[index + 1] = 0;
                    distribution[index + 2] = 0;
                    distribution[index + 3] = 1;
                    distribution[index + 4] = 0;
                    distribution[index + 5] = 1;
                    distribution[index + 6] = 1;
                    distribution[index + 7] = 0;
                    index = index + 8;
                    k--;
                    diff = 0;
                }
            } 
            cout << diff << "\n";
            for(int i = 1; i < n+1; i++) {
                cout << distribution[i];
            }
            cout << "\n";
        }
        /*else if(k == 3) {

        }
        else if(k == 4) {

        } */
    }
    return 0;
}