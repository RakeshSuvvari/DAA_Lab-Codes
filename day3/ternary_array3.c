#include<stdio.h>
//ternary array contains only 0s,1s and 2s
void selectionsort(int a[], int n);
int main()
{
 int a[1000],n;
 
 printf("enter the size of array\n");
 scanf("%d",&n);
 
 printf("enter the elements\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 
  selectionsort(a,n);
 
 printf("The Required Ternary_Array:\n");
    for(int i=0; i<n; ++i)
      printf("%d ", a[i]);
 return 0;
}

void selectionsort(int a[], int n)// like selection sort
{
   int max, imax, temp;
   
  for(int i=0; i<n-1; ++i)
  {
   max=a[0];
   imax=0;
    for(int j=1; j<n-i; j++)
    {
     if(a[j] >= max)//we made >= to presereve order of apperence as in input
     {
       max=a[j];
       imax=j;
     }
    }
   temp=a[imax];
   a[imax]=a[n-i-1];
   a[n-i-1]=temp;    
  }
}




