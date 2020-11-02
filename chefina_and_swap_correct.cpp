#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long t;
    cin >> t;

    while(t--) {
        unsigned long long n;
        cin >> n;

        unsigned long long ans = 0;
        unsigned long long sum = (n * (n+1)) / 2;
        unsigned long long temp_sum = ((n/2) * ((n/2) + 1)) / 2;

        if(n % 4 == 1 || n % 4 == 2) {
            ans = 0;
        }       
        else {
            unsigned long long m = n/2;
            
            while(temp_sum + n - 1 < sum/2) {
                m++;
                temp_sum = temp_sum + m;
            }

            long long diff = sum/2 - temp_sum;
            while(diff > 0) {
                if(diff <= n-m) {
                    ans = ans + diff;
                    m++;
                    diff = diff - m;
                }
                else {
                    if(m < diff) {
                        ans = ans + n - diff;
                    }
                    else {
                        ans = ans + n - m;
                    }
                    m++;
                    diff = diff - m;
                } 
            }

            if(diff == 0 && n != 3) {
                ans = ans + ((m * (m - 1)) / 2) + (((n - m) * (n - m - 1)) / 2);
            }    
        } 
        cout << ans << "\n";
    }
    return 0;
}