#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, k, input;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int A[n];
		for(int i = 0; i < n; i++) {
			cin >> input;
			A[i] = input - 1;
		}

		
		int no_of_operations = 0, i1, i2, i3, temp, flag = 0;
		//vector<vector<int>> v1;
		vector<int> v2;

		while(no_of_operations < k) {
			i1 = -1, i3 = -1;
			for(int i = 0; i < n; i++) {
				if(A[i] != i) {
					i1 = i;
					break;
				}
			}
			if(i1 == -1) {
				break;
			}

			i2 = A[i1];
			if(A[i2] == i1) {
				for(int i = i1+1; i < n; i++) {
					if(i == i2) {
						continue;
					}
					if(A[i] != i) {
						i3 = i;
						break;
					}
				}
				if(i3 == -1) {
					flag = 1;
					break;
				}
			}
			else {
				i3 = A[i2];
			}
			temp = A[i3];
			A[i3] = A[i2];
			A[i2] = A[i1];
			A[i1] = temp;
			v2.push_back(i1+1);
			v2.push_back(i2+1);
			v2.push_back(i3+1);
			//v1.push_back(v2);
			//v2.clear();
			no_of_operations++;	
			/*for(int i = 0; i < n; i++) {
				cout << A[i] + 1 << " ";
			}
		cout << endl; */ 	
		}
		
		if(flag == 0) {
			cout << no_of_operations << "\n";
			/*for(int i = 0; i < v1.size(); i++) {
				for(int j = 0; j < v1[i].size(); j++) {
					cout << v1[i][j] << " ";
				}
				cout << "\n";
			} */
			for(int i = 0; i < v2.size(); i+=3) {
				cout << v2[i] << " " << v2[i+1] << " " << v2[i+2] << "\n"; 
			} 
		}
		else {
			cout << "-1\n";
		}
		
		/*for(int i = 0; i < n; i++) {
			cout << A[i] + 1 << " ";
		}
		cout << endl; */
	}
	return 0;
}
