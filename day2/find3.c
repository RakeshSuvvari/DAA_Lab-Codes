#include<stdio.h>

// to find no. of combinations which is equal to given number(p=q+r)
int main()
{
 int n,a[10000],Hash[10000]={0},p,q;
 printf("enter array size\n");
 scanf("%d",&n);
 
 printf("enter the numbers\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
  Hash[a[i]]++; //Use Hash and store the input
 }
 
 printf("give number:\n");
 scanf("%d",&p);
 
 for(int i=0;i<n;i++)
 {
  q=a[i];
  int find=Hash[p-q];// find whether (given number - each number in the hash list) produces 
  if(find>0)         //other number which is in the list
   {
    printf("Pair exist:%d = %d + %d ",p,q,p-q);
    return 0;
   }
 }
 printf("Pair does not exist\n");
 return 0;
}
