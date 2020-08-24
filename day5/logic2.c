#include<stdio.h>
#include<stdlib.h>
int *merge(int *arr1,int *arr2, int size1, int size2, int result[]);
int *dc_merge(int start, int end, int* arrays[], int sizes[], int result[]);
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

    int result[size];

     int *merged = dc_merge(0,k-1,arrays,sizes, result) ;

    for(i=0;i<size;i++)
    {
    printf("%d ", merged[i]);

    }

    printf("\n");
}


//merges two arrays at a time
int  *merge(int *arr1,int *arr2, int size1, int size2, int result[])
{
 int i,j,k;
  //compare corresponding elements
    i=j=0;
    k= 0;
    while(i<size1 && j<size2)
    {
        if(*arr1>=*arr2)
        {
        result[k] = *arr2;
        arr2++;
        j++;
        }
        else
        {
            result[k] = *arr1;
            arr1++;
            i++;
        }
        k++;
    }

    //copy remaining elements of arr1, if any
    while(i<size1)
    {
        result[k]= *arr1;
        arr1++;
        i++;
        k++;
    }



    //same for arr2
    while(j<size2)
    {
        result[k]= *arr2;
        k++;
        arr2++;
        j++;
    }
     return result;
}


//divide and conquer on mergeing
int *dc_merge(int start, int end, int* arrays[], int sizes[], int result[])
{

       if(start==end)
    return arrays[start];  //only 1 array is given

    else if(end== start+1)
    {

    return(merge(arrays[end],arrays[start],sizes[end],sizes[start], result));  //merge the given two arrays
    }



    int mid = (start+end)/2;

    int size1=0; //size of left half
    int size2=0; //size of right half

    int i;
    for( i=0;i<=mid;i++)
    size1 = size1 + sizes[i];

    for(i=mid+1;i<=end;i++)
    size2 = size2 + sizes[i];


    int result1[size1]; //for left half
    int result2[size2]; //for right half



    //merge left half
    int *lefthalf = dc_merge(start,mid,arrays,sizes,result1);
    //merge right half
    int * righthalf= dc_merge(mid+1,end,arrays,sizes,result2);




    //merge left  half and rigt half
    int *final= merge(lefthalf,righthalf,size1,size2,result);
    return final;
}
