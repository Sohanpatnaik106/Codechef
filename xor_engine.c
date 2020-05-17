#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
	while(a != b)
    	{
        	if(a > b)
            		a -= b;
        	else
            		b -= a;
    	}

	return a;
}

int main()
{
	int t, n, q, ctr;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &q);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		int p;
		for(int i = 0; i < q; i++)
		{
			scanf("%d", &p);
			ctr = 0;
			for(int j = 0; j < n; j++)
			{
				if(gcd(a[j], p) != 1)
					ctr++;
			}
			printf("%d %d\n", ctr, n - ctr);
		}
	}

	return 0;
}
