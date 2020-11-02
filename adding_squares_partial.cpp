#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h, n, m;
    cin >> w >> h >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    set<int, greater<int>> x_len, y_len;

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            x_len.insert(abs(a[j]-a[i]));
        }
    }
}