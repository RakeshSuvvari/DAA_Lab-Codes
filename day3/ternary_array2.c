#include<stdio.h>
//ternary array contains only 0s,1s and 2s
int main()
{
 int n,a[1000];
 printf("enter the array size\n");
 scanf("%d",&n);
 
 printf("enter elements\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 
 for(int i=0;i<n-1;i++)//bubble sort
 {
  for(int j=0;j<n-i-1;j++)
  {
   int temp;
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 
 for(int i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
}
