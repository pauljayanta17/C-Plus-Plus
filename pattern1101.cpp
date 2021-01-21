#include<stdio.h>
main()
{
	int n,j,a,i;
	printf("Enter a number ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<(2*i)+1;j++)
		{
			a=(j+1)%2;
			printf("%d",a);
		}
		printf("\n");
	}
	
	
}
