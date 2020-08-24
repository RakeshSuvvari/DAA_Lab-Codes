#include<stdio.h>
// GCD of n numbers
int gcd(int a,int b);
int main()
{
 int a[100],n,sol;
 
 printf("enter size:\n");
 scanf("%d",&n);
 
 printf("enter numbers:\n");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 
 sol=gcd(a[0],a[1]);
 
 for(int i=0;i<n;i++)
 {
 sol=gcd(sol,a[i]);
 }
 
 printf("GCD is: %d ",sol);
 return 0;
}

int gcd(int a,int b)//recursive
{
 if(a<0)
  a=-a;
 if(b<0)
  b=-b;
 
 if(a==0 && b==0)
  return 0;
 else if(a!=0 && b==0)
  return a;
  
 if(a==0)//euclidian method
  return b;
 else
  return gcd(b%a,a);
}



