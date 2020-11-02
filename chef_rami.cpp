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

        vector<long long int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long int cost = 0, i = 0;
        vector<long long int> :: iterator it = a.begin();
        while(it != a.end()) {
            if(it == a.begin()) {
                if(*it < x) {
                    *(it+1) = *(it+1) + (*it);
                    cost = cost + (*it);
                    a.erase(it);                    
                }
            }
            else if((it + 1) == a.end()) {
                if(*it < x) {
                    *(it-1) = *(it-1) + (*it);
                    cost = cost + (*it);
                    a.erase(it);
                }
            }
            else {
                if(*it < x) {
                    if(*(it-1) < *(it+1)) {
                        *(it-1) = *(it-1) + *(it);
                        cost = cost + *(it);
                        a.erase(it);
                        it = it-1;
                    }
                    else {
                        *(it+1) = *(it+1) + *(it);
                        cost = cost + *(it);
                        a.erase(it);
                    }
                }
            }
            it++;
        }

        for(it = a.begin(); it != a.end(); it++) {
            cost = cost + x;
        }

        cout << cost << "\n";
    }
    return 0;
}