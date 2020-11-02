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
        
        vector<vector<int>> a;
        vector<int> temp;
        int x;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
            temp.clear();
        }
        
        int flag = 0, no_of_operations = 0;
        for(int i = n-1; i > 0; i--) {
            if(flag == 0) {
                if(a[0][i] != i+1) {
                    no_of_operations++;
                    flag = 1;
                }
            }
            else if(flag == 1) {
                if(a[i][0] != i+1) {
                    no_of_operations++;
                    flag = 0;
                }
            }
        }
        
        cout << no_of_operations << "\n";
    }
    return 0;
}