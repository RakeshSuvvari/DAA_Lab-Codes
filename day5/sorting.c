#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int start, int middle, int end);
void mergesort(int start , int end, int a[]);
void insertionsort(int start, int end, int a[]);


int main()
{
  //initilize thr random array
 int a[1000000];
 int i;
 srand(time(0));
 for(i=0;i<1000000;i++)
   a[i]= rand();

 mergesort(0,999999,a);

 for(i =0;i<1000000; i++)
   printf("%d ", a[i]);


}

void mergesort(int start , int end, int a[])
{
 if( (end-start)/100000 == 0 )
  insertionsort(start,end,a);
 else
 {
  int middle = (start+end)/2;
  mergesort(start,middle, a);
  mergesort(middle+1,end,a);
  merge(a,start,middle,end);
 }
}



void insertionsort(int start, int end, int a[])
{
 for(int i=start ; i<=end ; i++)
 {
  for(int j = i; j>=start ; j--)
  {
   if(a[i+1]>=a[j])
    break;

   else
   {
    if(j==start)
     {
      //shift right and insert a[i+1] at jth position
      int temp = a[i+1];
      for(int k = i ; k>=j ; k-- )
        a[k+1]= a[k];

      a[j]= temp;
      break;

      }

     else if (a[i+1]>a[j-1])
     {
      //shift right and insert a[i+1] at jth position
      int temp = a[i+1];
      for(int k = i ; k>=j ; k-- )
        a[k+1]= a[k];

       a[j]= temp;
       break;
      }

    }
   }
 }
}

void merge(int a[], int start, int middle, int end)
{
  //make two temp arrays and copy the sorted data into appropriate array
  int s1 = middle - start  +1;
  int s2 = end - middle;

  int a1[s1], a2[s2];

  int i,j,k;

  for (i = start; i <=middle; i++)
        a1[i-start] = a[i];
  for(j=middle+1; j<=end ; j++)
  a2[j-(middle+1)] = a[j];
  //compare corresponding elements of the temp arrays
  i=j=0;
  k= start;
  while(i<s1 && j<s2)
  {
   if(a1[i]>=a2[j])
   {
    a[k] = a2[j];
    j++;
   }
   else
    {
     a[k] = a1[i];
     i++;
    }
     k++;
   }

 //copy remaining elements of a1, if any
 while(i<s1)
 {
   a[k]= a1[i];
   i++;
   k++;
 }

 //same for a2
 while(j<s2)
 {
  a[k]= a2[j];
  k++;
  j++;
 }
}



