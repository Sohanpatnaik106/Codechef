#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t, n, m, p;
	scanf("%d", &t);

	while(t--)	
	{
		scanf("%d %d", &n, &m);
		int *f = (int *)malloc(n * sizeof(int));
		int *ans =(int *)calloc(m, sizeof(int), -1); 
		for(int i = 0; i < m; i++)
			printf("%d", ans[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &p);
			if(ans[f[i]-1] == -1)
				ans[f[i]-1] = ans[f[i]-1] + p + 1;
			else
				ans[f[i]-1] = ans[f[i]-1] + p;
		}

		int min = ans[f[0]];

		for(int i = 0; i < m; i++)
			printf("%d ", ans[i]);

		printf("\n");
		for(int i = 0; i < m; i++)
		{
			if(ans[i] < min && ans[i] != -1)
				min = ans[i];
		}

		printf("%d\n", min);
	}

	return 0;
}
