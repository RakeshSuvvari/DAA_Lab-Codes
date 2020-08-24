#include<stdio.h>
#include<stdlib.h>

int min(int * a[], int size, int sizes[], int *arrays[]);

int main()
{
    //prompt for number of arrays
   printf("How many sorted arrays do you want?: ");
   int k;
   scanf("%d",&k);

   int* arrays[k];  //pointers to k-arrays
   int sizes[k];   //sizes of the arrays

    //prompt for the sizes of the arrays
   int i;
   for(i=0;i<k;i++)
   {
       printf("Enter the size of %dth array:", i+1);
       scanf("%d",&sizes[i]);
   }

   //prompt for the elements of the arrays
   for(  i =0; i< k ; i++)
   {
       printf("Enter the elements of arr%d\n",i+1);

       int *index=NULL;
       //malloc space for it
       arrays[i] = (int *)malloc(sizes[i]);
       index = arrays[i];
       for(int j=0; j<sizes[i] ;j++)
        {
            printf("Enter %dth elementh: ",j);
            scanf("%d",index);
            index++;

        }
   }

   //calculate totalsize
   int size=0;
   for(i=0;i<k;i++)
    size = size + sizes[i];

    int arr[size];

    //initilizing k pointers
    int *kpointers[k];
    for( i=0;i<k;i++)
        kpointers[i] = arrays[i];


    //find min out of k pointers and increment the appropriate pointer till the entire array is filled
    for(i=0;i<size;i++)
    {
        int tempmin= min(kpointers,k,sizes,arrays);
        arr[i] = tempmin;
        printf("%d ", tempmin);
    }
    printf("\n");





}

int min(int * a[], int size, int sizes[], int *arrays[])
{
    int i =0;
    //initilizing the minimum
    int minimum;
    while(i<size)
    {

        if(a[i]-arrays[i]<=sizes[i]-1)
        break;
        else
        i++;
    }

    minimum = *a[i];
    a[i]++;

    int index= i; //for keeping track of miimum index

    for(int j=i+1;j<size;j++)
    {
        if(a[j] - arrays[j]<=sizes[j]-1)
        {
            if(*a[j]<minimum)
            {
            minimum = *a[j];
            a[j]++;
            a[index]--;
            index = j;
            }

        }
        else
        j++;

    }

    return minimum;

}
