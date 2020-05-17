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
		int A[n], P[n];
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			P[i] = no_of_two(A[i]);
		}	

		int no_of_seq = 0, i = 0;
		while(i < n)
		{
			v = P[i];
			if(v > 1)
			{
				no_of_seq = no_of_seq + n - i;
				i++;
			}
			else if(v == 1)
			{
				int k = i + 1;
				while(k < n)
				{
					if(P[k] > 0)
					{
						no_of_seq = no_of_seq + n - k;
						i++;
						break;
					}
					else
					{
						k++;
					}
				}
			}
			else
			{
				
			}
		}
	}
}
