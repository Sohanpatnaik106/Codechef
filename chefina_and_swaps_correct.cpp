#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long  t;
    cin >> t;

    while(t--) {
        long long  n;
        cin >> n;

        long long  a[n], b[n];
        unordered_map<long long , long long > mp, mp1, mp2;
        long long  min_val = INT_MAX;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            min_val = min(a[i], min_val);
            mp[a[i]]++;
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
            min_val = min(b[i], min_val);
            mp[b[i]]++;
        }

        long long  flag = 0;
        for(auto u : mp) {
            if(u.second % 2 == 1) {
                flag =1;
                break;
            }
            else {
                mp1[u.first] = u.second/2;
            }
        }

        if(flag) {
            cout << "-1\n";
            continue;
        }
        else {
            mp2 = mp1;
            vector<long long > v1, v2;
            for(int i = 0; i < n; i++) {
                if(mp1[a[i]]) {
                    mp1[a[i]]--;
                }
                else {
                    v1.push_back(a[i]);
                }
            }
            for(int i = 0; i < n; i++) {
                if(mp2[b[i]]) {
                    mp2[b[i]]--;
                }
                else {
                    v2.push_back(b[i]);
                }
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end(), greater<long long >());

            long long  y = v1.size(); 
            
            if(y == 0) {
                cout << "0\n";
            }
            else {
                long long  cost = 0;
                for(int i = 0; i < y; i++) {
                    cost = cost + min(2*min_val, min(v1[i], v2[i]));
                }
                cout << cost << "\n"; 
            }
        }
    }
    return 0;
}