#include<stdio.h>
int gcd(int a,int b);
int main()
{
 int a,b,sol;
 
 printf("enter two numbers:\n");
 scanf("%d",&a);
 scanf("%d",&b);
 
 if(a<0)
  a=-a;
 if(b<0)
  b=-b;
  
 sol=gcd(a,b);
 
 printf("GCD is:%d ",sol);
 return 0;
}

int gcd(int a,int b)//recursive
{
 if(a==0 && b==0)
  return 0;
 else if(a!=0 && b==0)
  return a;
  
 if(a==0)//euclidian method
  return b;
 else
  return gcd(b%a,a);
}
