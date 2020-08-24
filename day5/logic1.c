#include<stdio.h>
int main()
{
int k,i,j,n,s[200],sum ,p,b[200],c[200],swap;
int a[200][200];
//prompt for number of arrays
printf("How many sorted arrays do you want?:\n");
scanf("%d",&k);
for(i=1;i<=k;i++)		
{	
//prompt for the sizes of the arrays
 printf("enter the size of the array %d=",i);
 scanf("%d",&n);
 s[i]=n;
  //prompt for the elements of the arrays
 printf("enter the elements of array %d:\n",i);		
 for(j=1;j<=n;j++)
 {
  scanf("%d",&a[i][j]);
 }		
}
	
for(j = 1; j<=s[1]; j++)
  {
    c[j]=a[1][j];
  }
	
int n1=s[1];
 for(i= 1 ; i < n1; i++)
 {
   for(j = 1 ; j < n1-1+1; j++)
  {
    if(c[j] > c[j+1])//if the element is greater than the next element,then swap both
     {
       swap   = c[j];//sorting if not sorted
       c[j]   = c[j+1];
       c[j+1] = swap;
     }
   }
  }
		 	
	
for(i=1;i<k;i++)
{
	
 int n2=s[i+1];
 for (int c= 1 ; c < n2;c++)
  {
    for (int d = 1 ; d<n2 ; d++)
    {
      if (a[i+1][d] > a[i+1][d+1]) 
      	{
         swap   = a[i+1][d]; //sorting if not sorted
         a[i+1][d]   = a[i+1][d+1];
         a[i+1][d+1] = swap;
     	}
    }		
  }
     		 
 for(j= 1,p = 1, n = 1; j<= n1 && p <= n2; n++)
 {
  if(c[j] <= a[i+1][p])
   {
    b[n] = c[j];
    j++;
   }
  else
   {
    b[n] = a[i+1][p];
    p++;
   }
 }

 while(j<= n1)    
    b[n++] = c[j++];
    
 while(p <= n2)   
    b[n++] = a[i+1][p++];
		
 for(j = 1; j<n; j++)
  {
   c[j]=b[j];
  }
   n1=n-1;
}
   	
  for(i=1;i<n;i++)
   printf("%d ",c[i]);
printf("\n");
return 0;
}









