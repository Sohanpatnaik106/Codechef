#include"bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b, c, d, n, p, q, y;
	cin >> t;
	while(t--)
	{
		cin >> n >> a >> b >> c >> d >> p >> q >> y;
		int x[n+1];
		for(int i = 1; i < n+1; i++)
			cin >> x[i];

		if(p < q)
		{
			cout << abs(x[a]-x[b]) * p;
			continue;
		}
		else 
		{
			int walk_time = 0, train_time = 0;
			walk_time = abs(x[a] - x[b]) * p;

			train_time = abs(x[a] - x[c]) * p;
			if(train_time < y)
				train_time = y;
			else
			{
				cout << walk_time << endl;
				continue;
			}
			train_time = train_time + (abs(x[c]-x[d]) * q) + (abs(x[b]-x[d]) * p);

			if(walk_time < train_time)
				cout << walk_time << endl;
			else
				cout << train_time << endl;
		}
	}
	
	return 0;
}
