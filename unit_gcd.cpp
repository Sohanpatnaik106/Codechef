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
		vector<int> P(n);
		for(int i = 0; i < n; i++)
			P[i] = i+1;

		vector<vector<int>> gp;
		vector<int> sub_gp;

		while(P.size() > 0)
		{
			sub_gp.clear();
			for(int j = 0; j < P.size(); j++)
			{
				if(sub_gp.size() == 0)
				{
					sub_gp.push_back(P[j]);
					P.erase(P.begin() + j);
					j--;
				}
				else
				{
					int flag = 0;
					for(vector<int> :: iterator it = sub_gp.begin(); it != sub_gp.end(); ++it)
					{
						if(__gcd(P[j], *it) != 1)
						{
							flag = 1;
							break;
						}
					}
					if(flag == 0)
					{
						sub_gp.push_back(P[j]);
						P.erase(P.begin() + j);
						j--;
					}
				}
			}
			gp.push_back(sub_gp);
		}
		cout << gp.size() << "\n";
		for(vector<vector<int>> :: iterator it1 = gp.begin(); it1 != gp.end(); ++it1)
		{
			cout << (*it1).size() << " ";
			for(vector<int> :: iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
				cout << (*it2) << " ";
			cout << "\n";
		}	
	}
	return 0;
}
