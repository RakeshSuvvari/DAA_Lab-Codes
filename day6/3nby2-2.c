#include<stdio.h> 
struct pair 
{ 
int min; 
int max; 
}; 

struct pair getMinMax(int arr[], int n) 
{ 
struct pair minmax;	 
int i; 
if (n%2 == 0) 
{		 
	if (arr[0] > arr[1])	 
	{ 
	minmax.max = arr[0]; 
	minmax.min = arr[1]; 
	} 
	else
	{ 
	minmax.min = arr[0]; 
	minmax.max = arr[1]; 
	} 
	i = 2; //leave elements in the first pair
} 
else
{ 
	minmax.min = arr[0]; 
	minmax.max = arr[0]; //no.of elements in the array are odd
	i = 1; //leave the first element
} 
	
	
while (i < n-1) //in the loop compare the other pair with min and  max pair
{		 
	if (arr[i] > arr[i+1])		 
	{ 
	if(arr[i] > minmax.max)		 
		minmax.max = arr[i]; 
	if(arr[i+1] < minmax.min)		 
		minmax.min = arr[i+1];		 
	} 
	else		
	{ 
	if (arr[i+1] > minmax.max)		 
		minmax.max = arr[i+1]; 
	if (arr[i] < minmax.min)		 
		minmax.min = arr[i];		 
	}		 
	i += 2; 
}			 

return minmax; 
}	 

int main() 
{ 
int arr[10000],arr_size,i;
printf("enter the sizer of array\n");
scanf("%d",&arr_size);
printf("enter the elements of the array\n");
for(i=0;i<arr_size;i++)
{
scanf("%d",&arr[i]);
} 
struct pair minmax = getMinMax (arr, arr_size); 
printf("\nMinimum element is %d", minmax.min); 
printf("\nMaximum element is %d", minmax.max); 
getchar(); 
} 

