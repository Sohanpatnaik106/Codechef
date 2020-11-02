#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, x, p, k;
        cin >> n >> x >> p >> k;
        p = p-1;
        k = k-1;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> :: iterator it = find(a.begin(), a.end(), x);
        int min_operations = 0;
        bool possible = true;
        if(it == a.end()) {
            int index = -1;
            bool found_index = false;
            for(int i = 0; i < n-1; i++) {
                if(a[i] < x && a[i+1] > x) {
                    index = i;
                    found_index = true;
                    break;
                }
            }
            if(found_index == false) {
                if(a[0] < x) {
                    index = n-1;
                }
                else {
                    index = -1;
                }
            }

            if(p <= index) {
                if(k > p) {
                    possible = false;
                }
                else {
                    min_operations = index - p + 1;
                }
            }
            else {
                if(k < p) {
                    possible = false;
                }
                else {
                    min_operations = p - index;
                }
            }
        }
        else {
            if(it == a.begin() + p) {
                min_operations = 0;
            }
            else if(it < a.begin() + p) {
                bool flag = false;
                while(true) {
                    if(*(it+1) == *(it)) {
                        it++;
                        if(it - a.begin() == p) {
                            min_operations = 0;
                            flag = true;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
                if(!flag) {
                    if(k < p) {
                        possible = false;
                    }
                    else {
                        min_operations = a.begin() + p - it;
                    }
                }
            }
            else {
                if(k <= p) {
                    min_operations = it - a.begin() - p;
                }
                else {
                    possible = false;
                }
            }
        }

        if(possible) {
            cout << min_operations << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
}