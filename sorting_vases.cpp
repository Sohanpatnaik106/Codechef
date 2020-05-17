#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, x, y, input;
	cin >> t;

	while(t--) {
		cin >> n >> m;
		vector<int> P;
		for(int i = 0; i < n; i++) {
			cin >> input;
			P.push_back(input);
		}
		vector<pair<int, int>> robot;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			robot.push_back(make_pair(x-1, y-1));
		}
		int no_of_minutes = 0;
		int ctr = 0;
		vector<int> A;
		for(int i = 0; i < n; i++) {
			A.push_back(i+1);
		}
		for(int j = 0; j < n - 1; j++) {
			for(int i = j; i < n; i++) {
				if(A[i] != P[i]) {
					vector<int> :: iterator it = find(A.begin(), A.end(), P[i]);
					int temp = *it;
					*it = A[i];
					A[i] = temp; 
					int index = distance(A.begin(), it);
					if((find(robot.begin(), robot.end(), make_pair(index, i)) != robot.end()) || (find(robot.begin(), robot.end(), make_pair(i, index)) != robot.end())) {
						break;
					}
					else {
						no_of_minutes++;
						break;
					}
				}
			}
		}
		cout << no_of_minutes << "\n";
	}
	return 0;
}