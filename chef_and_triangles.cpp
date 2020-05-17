#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6+7;
const int M = 2007;

int f1[N], f2[N], f3[N], ps1[N], ps2[N], ps3[N], s[N];
vector<int> y11, y2, y3;
int s1, s2, s3;

main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;

	while(t--)
	{
		y11.clear();
		y2.clear();
		y3.clear();

		for(int i = 0; i < N; i++)
		{
			f1[i] = f2[i] = f3[i] = ps1[i] = ps2[i] = ps3[i] = s[i] = 0;
		}
		s1 = s2 = s3 = 0;

		int n;
		cin >> n;
		int xi, yi;
		for(int i = 0; i < n; i++)
		{
			cin >> xi >> yi;
			if(xi == 1)
			{
				f1[yi]++;
				y11.push_back(yi);
			}
			else if(xi == 2) 
			{
				f2[yi]++;
				y2.push_back(yi);
			}
			else 
			{
				f3[yi]++;
				y3.push_back(yi);
			}
		}

		ps1[0] = f1[0];
		ps2[0] = f2[0];
		ps3[0] = f3[0];
		for(int i = 1; i < N; i++)
		{
			ps1[i] = ps1[i-1] + f1[i];
			ps2[i] = ps2[i-1] + f2[i];
			ps3[i] = ps3[i-1] + f3[i];
		}

		s[0] = 0;
		for(int i = 1; i < N; i++)
		{
			s[i] = s[i-1] + f2[i]*i;
		}

		for(int i = 1; i < N; i++)
		{
			s1 = s1 + f1[i]*i*(-(ps1[N-1]-ps1[i]) + (ps1[i-1]));
			s2 = s2 + f2[i]*i*(-(ps2[N-1]-ps2[i]) + (ps2[i-1]));
			s3 = s3 + f3[i]*i*(-(ps3[N-1]-ps3[i]) + (ps3[i-1]));
		}
	
		long double res = 0;
		res = res + 0.5*s1*ps2[N-1] + s1*ps3[N-1];
		res = res + 0.5*s2*ps1[N-1] + 0.5*s2*ps3[N-1];
		res = res + s3*ps1[N-1] + 0.5*s3*ps2[N-1];
	
		for(int i = 0; i < y11.size(); i++)
		{
			for(int j = 0; j < y3.size(); j++)
			{
				int y11i = y11[i];
				int y3i = y3[j];
				double ym = 0.5 * (y11i+y3i);
				int ymi = (y11i+y3i) / 2;
				int sl = s[ymi];
				int sg = s[N-1] - s[ymi];
				res + res + ym*ps2[ymi] - sl;
				res = res + sg - ym * (ps2[N-1]-ps2[ymi]);
			}
		}
		cout << setprecision(30) << res << endl;
	}	
}
