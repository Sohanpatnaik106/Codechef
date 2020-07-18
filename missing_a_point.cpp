#include"bits/stdc++.h"
using namespace std;

bool sort_by_sec(const pair<long long int, long long int> &a, const pair<long long int, long long int> &b) {
    return a.second < b.second;
} 

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    int n;
    while(t--) {
        cin >> n;
        int no_of_points = (4 * n) - 1;

        vector<pair<long long int, long long int>> P;
        long long int x, y;

        for(int i = 0; i < no_of_points; i++) {
            cin >> x >> y;
            P.push_back(make_pair(x, y));
        }

        sort(P.begin(), P.end());
        
        int x_equal_no = 1;

        for(int i = 0; i < no_of_points; i++) {
            if(i == no_of_points - 1) {
                if(x_equal_no % 2 != 0) {
                    x = P[i].first;
                }
                break;
            }

            if(P[i].first == P[i+1].first) {
                x_equal_no++;
            }
            else {
                if(x_equal_no % 2 != 0) {
                    x = P[i].first;
                    break;
                }
                else {
                    x_equal_no = 1;
                }
            }

        }
    
        sort(P.begin(), P.end(), sort_by_sec);

        int y_equal_no = 1;

       for(int i = 0; i < no_of_points; i++) {
           if(i == no_of_points - 1) {
               if(y_equal_no % 2 != 0) {
                   y = P[i].second;
               }
               break;
           }

           if(P[i].second == P[i+1].second) {
               y_equal_no++;
           }
           else {
               if(y_equal_no % 2 != 0) {
                   y = P[i].second;
                   break;
               }
               else {
                   y_equal_no = 1;
               }
           }
        }

        cout << x << " " << y << "\n";
    }

    return 0;
}