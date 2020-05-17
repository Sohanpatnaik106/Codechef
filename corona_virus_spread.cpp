#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, best_scene, worst_scene;
	cin >> t;

	while(t--) {
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++) {
			cin >> A[i];
		}

		best_scene = 10;
		worst_scene = 1;
		int ctr = 1;
		for(int i = 1; i < n; i++) {
			if(A[i] - A[i-1] <= 2) {
				ctr++;
			}
			else {
				if(ctr > worst_scene) {
					worst_scene = ctr;
				}
				if(ctr < best_scene) {
					best_scene = ctr;
				}
				ctr = 1;
			}
		} 
		if(ctr > worst_scene) {
			worst_scene = ctr;
		}
		if(ctr < best_scene) {
			best_scene = ctr;
		}
		
		cout << best_scene << " " << worst_scene << "\n";
	}
	return 0;
}