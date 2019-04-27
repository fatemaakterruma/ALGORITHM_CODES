#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
    int num[100000], i, j, k,c,n,f, step=1, key, f_r=0;
    FILE *fp, *fw;


    printf("\nPrinting UnSorted Numbers\n");

    fp=fopen("input.txt", "w");

     printf("Enter number of elements limit: \n");
               scanf("%d", &n);


               printf("before sorting: \n");
                srand(time(0));



             for (c = 0; c < n; c++){
                num[c]=rand();
             }

                for (c = 0; c < n; c++){
                    fprintf(fp,"%d\n", num[c]);
                    printf("%d\n",num[c]);
                }



    fclose(fp);



    for (i=0; i < f_r; i++)
    {
        printf("%d\n", num[i]);
    }

    clock_t t;
    t = clock ();

/* Sorting Routine Begins */

    for(j=1; j!=n; j++)
        {
            key=num[j];
            i=j-1;
                while(i>=0 && num[i]>key)
                    {
                        num[i+1]=num[i];
                        i=i-1;
                        num[i+1]=key;
                        step++;
                    }

        }

        t = clock()  ;
    double  time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds to execute \n", time_taken);


/* Sorted Output */



        printf("\nAfter Sorting Numbers\n");

    for (k=0; k!=n; k++)
    {
        printf("%d\n", num[k]);

    }

/* Printing Output to File */

    fw=fopen("output.txt", "w");
    f_r=0;

            for (i = 0; i < n ; i++){
         fprintf (fw, "%d\n", num[i]);
     }

    fclose(fw);


    return 0;
}
