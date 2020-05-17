#include"bits/stdc++.h"
using namespace std;

int large(int *ar, int n)
{
	int lar = ar[0];
	for(int i = 1; i < n; i++)
	{
		if(ar[i] > lar)
			lar = ar[i];
	}
	return lar;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while(t--)
	{
		cin >> n;
		int A[n], B[n];
		for(int i = 0; i < n; i++)
			cin >> A[i];
		for(int i = 0; i < n; i++)
			cin >> B[i];

		int large_a = large(A, n);
		int large_b = large(B, n);
		
		if(large_a != large_b)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;	
}
