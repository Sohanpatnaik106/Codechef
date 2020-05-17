#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, q;
	unsigned int c;
	cin >> t;

	while(t--) {
		cin >> n >> q;
		string s;
		cin >> s;
		vector<char> v(s.begin(), s.end());
		vector<int> hash_val(26, 0);
		
		for(int i = 0; i < s.size(); i++) {
			char ch = v[i];
			int index = (int)(ch - 'a');
			hash_val[index]++;
		}

		for(int i = 0; i < q; i++) {
			cin >> c;
			unsigned int pending_queue = 0;
			for(int i = 0; i < 26; i++) {
				if(hash_val[i] > c) {
					pending_queue = pending_queue + hash_val[i] - c;
				}
			}
			cout << pending_queue << "\n";
		}
	}
	return 0;
}