#include"bits/stdc++.h"
using namespace std;

void find_binary(int a, vector<vector<int>> &store_binary, int index) {
    int i;
    for(i = 0; i < 30; i++) {
        if(index == 0 && a != 0) {
            if(a % 2 == 0) {
                store_binary[i][index] = 1;
                a = a/2;
                continue;
            }
            else {
                a = a / 2;
                continue;
            }
        }
        else if(index != 0 && a != 0) {
            if(a % 2 == 0) {
                store_binary[i][index] = store_binary[i][index - 1] + 1;
                a = a / 2;
                continue;
            }
            else {
                store_binary[i][index] = store_binary[i][index - 1];
                a = a/2;
                continue;
            }
        }
        if(a == 0) {
            if(index == 0) { 
                store_binary[i][index] = 1;
            }
            else {
                store_binary[i][index] = store_binary[i][index-1] + 1;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> store_binary(30, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        find_binary(a[i], store_binary, i);
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l = l - 1;
        r = r - 1;
        int and_val = a[l];
        for(int i = l + 1; i <= r; i++) {
            and_val = (and_val & a[i]);
        }
        int min_add;
        if(and_val != 0) {
            min_add = 0;
        }
        else {
            unsigned long long temp = INT64_MAX;
            if(l != 0) {
                unsigned long long x;
                for(int i = 0; i < 30; i++) {
                    x = (store_binary[i][r] - store_binary[i][l-1]) * ((unsigned long long)pow(2, i));
                    temp = min(temp, x);
                }
            }
            else {
                unsigned long long x;
                unsigned long long y = 1;
                for(int i = 0; i < 30; i++) {
                    x = store_binary[i][r] * y;
                    y = y * 2;
                    temp = min(temp, x);
                }
            }
            min_add = temp;
        }
        cout << min_add << "\n";
    } 
    return 0;
}