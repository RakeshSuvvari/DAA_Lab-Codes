#include<stdio.h>
//ternary array contains only 0s,1s and 2s
int main()
{
 int a[1000],b[1000],n;
 
 printf("enter the array size\n");
 scanf("%d",&n);
 
 printf("enter elements:\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 int k=-1;
 for(int i=0;i<n;i++)// linerly arranging of 0s
 {
  if(a[i]==0)
  {
   k++;
   b[k]=a[i];
  }
 }
 
 for(int i=0;i<n;i++)// linerly arranging of 1s
 {
  if(a[i]==1)
  {
   k++;
   b[k]=a[i];
  }
 }
 
 for(int i=0;i<n;i++)// linerly arranging of 2s
 {
  if(a[i]==2)
  {
   k++;
   b[k]=a[i];
  }
 }
 

 for(int i=0;i<n;i++)
 {
  printf("%d ",b[i]);
 }
 
}





