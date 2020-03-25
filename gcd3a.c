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
 if(a==b)
  return a;
 else
 {
  if(a==0 && b!=0)
   return b;
  else if(a!=0 && b==0)
   return a;
  if(a>b)		//GCD of diff of two numbers to next one and so on recursively till both are equal
   return gcd(a-b,b);
  else
   return gcd(a,b-a);
 }
}


