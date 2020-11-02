#include"bits/stdc++.h"
using namespace std;

/*int recursive_count(vector<vector<float>> &position, int count, int index, int n) {
    for(int i = index; i < n; i++) {
        if(position[index][i] > 0) {
            count++;
            count = recursive_count(position, count, i, n);
        }
    }
    return count;
} */

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n; 

        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> affect_count(n);
        for(int i = 0; i < n; i++) {
            affect_count[i] = 1;
        }

        vector<bool> affected_status(n);

        for(int i = 0; i < n; i++) {
            affected_status[i] = false;
        }

        for(int i = 0; i < n; i++) {
            affected_status[i] = true;
            for(int j = i+1; j < n; j++) {
                if(v[i] > v[j] && affected_status[j] == false) {
                    affect_count[i]++;
                    affected_status[j] = true;
                }
            }
            for(int j = 0; j < i; j++) {
                if(v[j] > v[i]) {
                    affect_count[i]++;
                    affected_status[j] = true;
                    for(int k = i+1; k < n; k++) {
                        if(v[j] > v[k] && affected_status[k] == false) {
                            affect_count[i]++;
                            affected_status[k] = true;
                        }
                    }
                }
                else {
                    for(int k = i+1; k < n; k++) {
                        if(v[j] > v[k]) {
                            affect_count[i]++;
                            affected_status[j] = true;
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < n; j++) {
                affected_status[j] = false;
            }
        }

        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << position[i][j] << " ";
            }
            cout << "\n";
        } */

        cout << *min_element(affect_count.begin(), affect_count.end()) << " " << *max_element(affect_count.begin(), affect_count.end()) << "\n";
    }
    return 0;
}