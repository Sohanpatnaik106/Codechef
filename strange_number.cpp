#include"bits/stdc++.h"
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int t, x, k;
	cin >> t;
	while(t--)
	{
		cin >> x;
		cin >> k;
		int ctr = 0;
		while(x % 2 == 0)
		{
			ctr++;
			x = x/2;
		}

		for(int i = 3; i*i <= x; i+=2)
		{
			while(x % i == 0)
			{
				ctr++;
				x = x/i;
			} 
		}

		if(x > 2)	
			ctr++;
	
		if(ctr < k)
			cout << "0\n";
		else
			cout << "1\n";				
	}
	return 0;
}
