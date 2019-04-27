#include<stdio.h>
#include<time.h>
void quicksort(int number[1000],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, n, number[1000],f_r=0;
   FILE *fp, *fw;
    printf("\nPrinting UnSorted Numbers\n");

    fp=fopen("input.txt", "w");

     printf("Enter number of elements limit: \n");
               scanf("%d", &n);


               printf("\nbefore sorting: \n");
                srand(time(0));



             for (i = 0; i < n; i++){
                number[i]=rand();
             }

                for (i = 0; i < n; i++){
                    fprintf(fp,"%d\n", number[i]);
                    printf("%d\n",number[i]);
                }



    fclose(fp);

    for (i=0; i < f_r; i++)
    {
        printf("%d\n", number[i]);
    }
     clock_t t;
    t = clock ();

    quicksort(number,0,n-1);

     t = clock()  ;
    double  time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n***** QUIC sort took %f seconds to execute ******\n\n", time_taken);



   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf("\n%d",number[i]);
      printf("\n");


       fw=fopen("output.txt", "w");
    f_r=0;

        while(f_r!=n)
            {
                fprintf(fw, "%d\n", number[f_r]);
                ++f_r;
            }

    fclose(fw);



   return 0;
}
