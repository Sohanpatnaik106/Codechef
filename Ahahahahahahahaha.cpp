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
        vector<int> equal_arr_one, equal_arr_zero;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) {
                equal_arr_one.push_back(a[i]);
            }
            else {
                equal_arr_zero.push_back(a[i]);
            }
        }

        bool choose_arr;
        if(equal_arr_one.size() % 2 == 0) {
            if(equal_arr_one.size() >= equal_arr_zero.size()) {
                choose_arr = true;
            }
            else {
                choose_arr = false;
            }
        }
        else {
            if(equal_arr_one.size() > equal_arr_zero.size()) {
                equal_arr_one.pop_back();
                choose_arr = true;
            }
            else if(equal_arr_zero.size() > equal_arr_one.size()) {
                equal_arr_zero.pop_back();
                choose_arr = false;
            }
            else {
                choose_arr = false;
            }
        }

        if(choose_arr) {
            if(equal_arr_one.size() > 0) {
                cout << equal_arr_one.size() << "\n";
                for(int i = 0; i < equal_arr_one.size(); i++) {
                    cout << equal_arr_one[i] << " ";
                }
                cout << "\n";
            }
            else {
                cout << equal_arr_zero.size() << "\n";
                for(int i = 0; i < equal_arr_zero.size(); i++) {
                    cout << equal_arr_zero[i] << " ";
                }
                cout << "\n";
            }
        }       
        else {
            cout << equal_arr_zero.size() << "\n";
            for(int i = 0; i < equal_arr_zero.size(); i++) {
                cout << equal_arr_zero[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}