#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, y, z, l, r, f, max;
	cin >> t;

	while(t--) {
		cin >> x >> y >> l >> r;
		if(x != 0 && y != 0) {
			z = x|y;
		}
		else {
			z = 0;
		}
		cout << z << "\n";
	}
	return 0;
}