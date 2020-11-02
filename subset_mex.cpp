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

        vector<int> a(n);
        vector<int> store_count(101, 0);
        int max_val = INT32_MIN;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            store_count[a[i]]++;
        }
    
        int index;
        int max_mex = 0;
        bool flag = false;
        bool found_1st = false;
        bool found_2nd = false;
        for(int i = 0; i < 101; i++) {
            if(store_count[i] == 0) {
                max_mex = max_mex + i;
                flag = true;
                found_1st = true;
                break;
            }
            else if(store_count[i] == 1) {
                max_mex = max_mex + i;
                index = i;
                found_1st = true;   
                break;
            }
        }

        if(!found_1st) {
            max_mex = 202;
        }
        else {
            if(flag) {
                max_mex = max_mex * 2;
                found_2nd = true;
            }
            else {
                for(int i = index+1; i < 101; i++) {
                    if(store_count[i] == 0) {
                        found_2nd = true;
                        max_mex = max_mex + i;
                        break;
                    }
                }
            }
            if(!found_2nd) {
                max_mex = max_mex + 101;
            }
        }

        cout << max_mex << "\n";
    }
}