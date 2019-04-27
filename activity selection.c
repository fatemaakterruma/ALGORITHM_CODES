#include<stdio.h>

int main()

{
    int i,n,a[1000],b[1000],j;
    printf("Enter 1st & 2nd array limit:\n");
    scanf("%d",&n);

    printf(" Enter the 1st array Element are:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }


    printf(" Enter the 2nd array Element are:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
        for(i=1;i<=n;i++)


    printf("Before Selection Activities are\n:");{
    for(i=1;i<=n;i++)
            {

                printf("\nA[%d]= [%d,%d]",i,a[i],b[i]);
            }
    }

printf("\n after activity selection\n:");
i=1;
printf("A[%d]=[%d,%d]\n",i,a[i],b[i]);
for (j = 1; j<=n; j++)

	{

		if (a[j] >= b[i] && b[j]>=b[i])

		{
			printf ("A[%d]=[%d,%d]\n",j,a[j],b[j]);

			i = j;

		}

	}
	printf("\n");


}
