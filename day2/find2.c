#include<stdio.h>

// to find no. of combinations which is equal to given number(p=q+r)
void BubbleSort(int a[],int n);
int check(int a[],int p,int n);
int main()
{
int a[100],n,p;
printf("enter size:\n");
scanf("%d",&n);

printf("enter numbers\n");
for(int i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}

printf("give number\n");
 scanf("%d",&p);
 
BubbleSort(a,n);// firstly sort the given array

 int k=check(a,p,n);
 
 printf("truth value:%d\n",k);

return 0;
}

void BubbleSort(int a[],int n)
{
 int temp;
for(int i=0;i<n-1;i++)
{ 
  for(int j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
}
}

int check(int a[],int p,int n)
{
 int l=0,r=n-1,flag=0;
  while(l!=r)
  {
   if(a[l]+a[r]==p)
   {
    flag=1;
    break;
   }
   else if(p>a[l]+a[r])//if given number is greater than sum of first element and last element
    l=l+1;             //then move to next element from begining
   
   
   else   //if it is less then move to next element from the end
    r=r-1;
  }
 return flag;
}

