#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, p, i, j;
	cin >> n >> m >> p;
	vector <vector <int>> vect[n];
	for(i = 0; i < n; i++)
	{
		vect[i] = vector <int> (m);
		for(j = 0; j < m; j++)
			vect[i][j] = j+1;
	}
	
	for(int t = 0; t < p; t++)
	{
		cin >> i >> j;
		vect[i-1][j-1]++;
	}

	int ans[n];
	for(int i = 0; i < n; i++)
		ans[i] = 0;
	
	for(i = 0; i < n; i++)
	{
		for(j = m-1; j > 0; j--)
		{
			if(vect[i][j] >= vect[i][j-1])
				ans[i] = ans[i] + vect[i][j] - vect[i][j-1];
			else 
				ans[i] = -1;
		}
	}
	
	for(i = 0; i < n; i++)
		cout << ans[i] << " ";

	cout << endl;
	return 0;
}
