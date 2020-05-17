#include"bits/stdc++.h"
using namespace std;

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m, x, y, s; 
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		cin >> x >> y >> s;
		int row[x], column[y];
		for(int i = 0; i < x; i++)
			cin >> row[i];
		for(int i = 0; i < y; i++)
			cin >> column[i];
		
		int bre[x+1], len[y+1];
		bre[0] = row[0] - 1;
		bre[x] = n - row[x-1];
		for(int i = 1; i < x - 1; i++)
			bre[i] = row[i] - row[i-1] - 1;
		len[0] = column[0] - 1;
		len[0] = m - column[y-1];
		for(int i = 1; i < y - 1; i++)
			len[i] = column[i] - column[i-1]; 
		
		int no_of_houses = 0;
		for(int i = 0; i <= x; i++)
		{
			for(int j = 0; j <= y; j++)
			{
				if(bre[i] > s && len[j] > s)
				{
					no_of_houses = no_of_houses + (bre[i]/s)*(len[j]/s);
				}
				 
			}	
		}

		cout << no_of_houses << endl;		
	}
	return 0;
}	
