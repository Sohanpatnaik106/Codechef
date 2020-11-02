#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    int x;
    for(int i = 1; i < n; i++) {
        cin >> x;
        a[x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}