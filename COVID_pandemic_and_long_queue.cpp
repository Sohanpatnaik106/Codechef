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
		int A[n];
		for(int i = 0; i < n; i++)
			cin >> A[i];
		int pos_1 = -1, pos_2 = -1, flag = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] == 1)
			{
				if(pos_1 == -1 && pos_2 == -1)
					pos_1 = i;
				else if(pos_1 != -1 && pos_2 == -1)
					pos_2 = i;
				else
				{
					pos_1 = pos_2;
					pos_2 = i;
				}
			}
			if(pos_1 != -1 && pos_2 != -1)
			{
				if(pos_2 - pos_1 < 6)
				{
					flag = 1;
					cout << "NO" << "\n";
					break;
				}
			}			
		}
		if(flag == 0)
			cout << "YES" << "\n";	
	}
	return 0;
}
