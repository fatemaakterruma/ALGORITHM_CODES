#include<stdio.h>
#include<conio.h>
#include<time.h>

void merge_sort(int, int);
void merge_array(int, int, int, int);

int arr_sort[1000];

int main() {
  int i,n,f_r=0;
  FILE *fp, *fw;

   printf("\nPrinting UnSorted Numbers\n");

    fp=fopen("input.txt", "w");

     printf("Enter number of elements limit: \n");
               scanf("%d", &n);

               printf("\nbefore sorting: \n");
                srand(time(0));

  for (i = 0; i <n; i++)
  {
      arr_sort[i]=rand();
  }
  for (i = 0; i <n; i++)
  {
    fprintf(fp,"%d\n", arr_sort[i]);

    printf("%d\n",arr_sort[i]);

  }

  fclose(fp);

  for (i=0; i < f_r; i++)
    {
        printf("%d\n", arr_sort[i]);
    }


     clock_t time;
    time = clock ();


  merge_sort(0, n - 1);
  time = clock()  ;
  double  time_taken = ((double)time)/CLOCKS_PER_SEC;
    printf("***** Merge sort took %f seconds to execute ******\n", time_taken);

  printf("\n\nSorted Data :");
  for (i = 0; i < n; i++) {
    printf("\n%d", arr_sort[i]);
  }

  fw=fopen("output.txt", "w");
    f_r=0;

        while(f_r!=n)
            {
                fprintf(fw, "%d\n", arr_sort[f_r]);
                ++f_r;
            }

    fclose(fw);

}

void merge_sort(int i, int j) {
  int m;

  if (i < j) {
    m = (i + j) / 2;
    merge_sort(i, m);
    merge_sort(m + 1, j);
    // Merging two arrays
    merge_array(i, m, m + 1, j);
  }
}

void merge_array(int a, int b, int c, int d) {
  int t[50];
  int i = a, j = c, k = 0;


  while (i <= b && j <= d) {
    if (arr_sort[i] < arr_sort[j])
      t[k++] = arr_sort[i++];
    else
      t[k++] = arr_sort[j++];
  }

  //collect remaining elements
  while (i <= b)
    t[k++] = arr_sort[i++];

  while (j <= d)
    t[k++] = arr_sort[j++];

  for (i = a, j = 0; i <= d; i++, j++){
    arr_sort[i] = t[j];
    }

}

