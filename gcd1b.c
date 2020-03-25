#include<stdio.h>
int min(int a,int b);
int gcd(int a,int b);
int m=0;
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
  
 m=min(a,b);
 sol=gcd(a,b);
  
 printf("GCD is:%d ",sol);
}

int min(int a,int b)//gcd is lessthan or equal to min of both the numbers
{
 if(a==0 || b==0)
  return 1;
 else if(a<b)
  return a;
 else
  return b;
}

int gcd(int a,int b)//recursive
{
 if(a==0 && b==0)
  return 0;
 else if(a==0 && b!=0)
  return b;
 else if(a!=0 && b==0)
  return a;
  
 if(a%m==0 && b%m==0)
 return m;
 m--;
 gcd(a,b);
 
}


