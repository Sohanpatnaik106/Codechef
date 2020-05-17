#include"bits/stdc++.h"
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	unsigned long long a, b;
	cin >> t;
	while(t--)
	{
		cin >> a;
		cin >> b;
		int size;
		if((int)log2(a) > (int)log2(b))
			size = (int)log2(a) + 1;
		else
			size = (int)log2(b) + 1; 

		unsigned long long temp_a = a;
		unsigned long long temp_b = b;
		unsigned long long lar = a^b;
		int ctr = 0;
		for(int i = 0; i < size; i++)
		{
			int dropped_lsb = temp_b & 1;
			temp_b = (temp_b >> 1) & (~(1 << (size-1)));
			temp_b = temp_b | (dropped_lsb << (size-1));

			if((temp_a^temp_b) > lar)
			{
				lar = (temp_a^temp_b);
				ctr++;
			}
		}
		cout << ctr << " " << lar << "\n";		
	}
	return 0;	
}
