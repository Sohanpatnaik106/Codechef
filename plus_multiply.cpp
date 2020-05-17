#include"bits/stdc++.h"
using namespace std;

int factorial(int a)
{
	int fact = 1;
	for(int i = 2; i <= a; i++)
		fact = fact * i;

	return fact;
}
int combination(int n, int r)
{
	return factorial(n)/(factorial(r) * factorial(n-r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int A[n];
		int ctr = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			if(A[i] == 2)
				ctr++;
		}
		
		if(ctr == 0 || ctr == 1)
			cout << "0" << endl;
		else
			cout << combination(ctr, 2) << endl;
	}	

	return 0;
}
