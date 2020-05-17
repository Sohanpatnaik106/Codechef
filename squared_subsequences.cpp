#include"bits/stdc++.h"
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		long long int A[n];
		for(int i = 0; i < n; i++)
			cin >> A[i];
		int c = 0, d = 0;
		long long int prod = 1;
		for(int i = 0; i < n; i++)
		{
			if(A[i] % 2 != 0 || A[i] % 4 == 0)
				c++;
			prod = prod * A[i];		
			for(int j = i+1; j<n; j++)
			{
				prod = prod * A[j];
			 	if(prod % 2 != 0 || prod % 4 == 0)
					d++;
			}
			prod = 1;
		}	
		cout << c+d << "\n";
	}
}
