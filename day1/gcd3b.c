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

int gcd(int a,int b)
{
 if(a==0 && b==0)
  return 0;
 else if(a==0 && b!=0)
   return b;
  else if(a!=0 && b==0)
   return a;
 else
 {
  while(a!=b)//iterative
  {	     //subtract small number from big number and so on till both are equal
   if(a>b)
    a=a-b;
   else
    b=b-a;
  }
 }
}


