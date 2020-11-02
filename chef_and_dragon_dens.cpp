#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, q;
    cin >> n >> q;
    long long int a[n], h[n];
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int choice, x1, x2, tastiness;
    
    while(q--) {
        cin >> choice >> x1 >> x2;

        if(choice == 1) {
            a[x1-1] = x2;
        }
        else if(choice == 2) {
            if(x1 < x2) {
                long long int start = x1 - 1, end = x2 - 1;
                tastiness = a[x1-1];
                while(start != end) {
                    long long int index = start + 1, max_height = h[start+1];
                    for(int i = start + 1; i <= end; i++) {
                        if(h[i] >= h[start]) {
                            tastiness = -1;
                            break;
                            index = i;
                            max_height = h[i];
                        }
                        else if(h[i] > max_height && h[i] < h[start]) {
                            index = i;
                            max_height = h[i];
                        } 
                    }
                    if(tastiness != -1) {
                        start = index;
                        tastiness = tastiness + a[index];
                    }
                    else if(tastiness == -1) {
                        break;
                    }
                }
            }
            else {
                long long int start = x1 - 1, end = x2 - 1;
                tastiness = a[x1-1];
                while(start != end) {
                    long long int index = start - 1, max_height = h[start - 1];
                    for(int i = start - 1; i >= end; i--) {
                        if(h[i] >= h[start]) {
                            tastiness = -1;
                            break;
                        }     
                        else if(h[i] > max_height && h[i] < h[start]) {
                            index = i;
                            max_height = h[i];
                        }
                    }
                    if(tastiness != -1) {
                        start = index;
                        tastiness = tastiness + a[index];
                    }
                    else if(tastiness == -1) {
                        break;
                    }
                } 
            }
            cout << tastiness << "\n";
        }
    }
    return 0;
}