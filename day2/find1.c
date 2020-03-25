#include<stdio.h>

// to find no. of combinations which is equal to given number(p=q+r)
int find(int a[],int p,int n);
int main()
{
 int a[100],n,p;
 printf("enter the array size\n");
 scanf("%d",&n);
 printf("enter numbers\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 
 printf("give number\n");
 scanf("%d",&p);
 
 int k=find(a,p,n);
 printf("no of combinations of given number:%d\n",k);
return 0;
}

int find(int a[],int p,int n)
{ 
 int count=0;
 for(int i=0;i<n-1;i++)
 {
  for(int j=i;j<n;j++)
  {
   if(a[i]+a[j+1]==p)// checking 1st element with the rest to get given number
   {
    count++;
   }
  }
 }
return count; 
}
