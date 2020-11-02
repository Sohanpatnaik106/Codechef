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

        vector<int> a;
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }

        set<int> count(a.begin(), a.end());
        if(count.find(0) != count.end()) {
            cout << count.size() - 1 << "\n";
        }
        else {
            cout << count.size() << "\n";
        }
    }
    return 0;
}