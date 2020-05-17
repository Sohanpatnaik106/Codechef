#include"bits/stdc++.h"
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int P[n];
		for(int i = 0; i < n; i++)
			cin >> P[i];
		sort(P, P+n, greater<int>());
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if(P[i] - i > 0)
			{
				sum = (sum + P[i] - i) % 1000000007;
			}
			else
			{
				break;
			}
		}
		cout << sum << "\n";
		fflush(stdout);
	}
	return 0;
}
