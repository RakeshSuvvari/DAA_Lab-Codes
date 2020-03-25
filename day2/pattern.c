#include<stdio.h>
int main()
{
 int n;
 printf("enter integer n:\n");
 scanf("%d",&n);
  
 //pattern1
 
 printf("P1:\n"); 
 
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n-i+1;j++)
  {
   printf("%d ",j);
  }
  printf("\n");
 }
 printf("\n");
 
 //pattern2
 
 printf("P2:\n"); 
 
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   if(j>=i)
    printf("%d ",j);
   else
    printf("  ");
  }
  printf("\n");
 }
 printf("\n");
 
 //pattern3
 
 printf("P3:\n"); 
 
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   if(j<=i)
    printf("%d ",j);
  }
  printf("\n");
 }
 printf("\n");
 
 //pattern4
 
 printf("P4:\n"); 
 
 for(int i=n;i>=1;i--)
 {
  for(int j=1;j<=n;j++)
  {
   if(j<i)
    printf("  ");
   else
    printf("%d ",j);
  }
  printf("\n");
 }
 printf("\n");
 
 //pattern5
 
 printf("P5:\n"); 
 
 for(int i=1;i<=(n+1)/2;i++)//for first half pattern
 {
  for(int j=1;j<=n-i+1;j++)
  {
   if(j<i)
    printf("  ");
   else if(j>=i)
    printf("%d ",j);
  }
  printf("\n");
 }
  int mid=(n+1)/2;
 for(int i=1;i<=(n+1)/2;i++)//for below pattern
 {
   for(int j=1;j<=n;j++)
   {
    if(n%2==0)//if n is even
    {
     if(j>(mid-i) && j<=(mid+i))
     {
       printf("%d ",j);
     }
     else
     {
     printf("  ");
     }
    }
   else//if n is odd
   {
     if(j>(mid-i) && j<(mid+i))
     {
      printf("%d ",j);
     }
     else
     {
      printf("  ");
     }
   }
  }
  printf("\n");
 }
 
 return 0;
}













