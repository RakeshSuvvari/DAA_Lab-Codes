//program for 2-way Merge Sort 

#include<stdio.h> 

// Merges two subarrays of arr[]. 

void merge(int a[],int l,int m,int r) 
{ 
	int i,j,k; 
	int n1 = m-l+1; 
	int n2 = r-m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = a[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = a[m + 1+ j]; 

	
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	
	/* Merge the temp arrays back into arr[l..r]*/
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			a[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			a[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		a[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		a[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int a[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(a, l, m); 
		
		mergeSort(a, m+1, r); 

		merge(a, l, m, r); 
	} 
} 


// print an array 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 


int main() 
{ 
	int a[1000],n;
	printf("enter the array size:\n");
	scanf("%d",&n);
	printf("enter the numbers:\n");
	for(int i=0;i<n;i++)
	{
	 scanf("%d",&a[i]);
	}

	mergeSort(a, 0,n- 1);

	printf("Sorted array is:\n"); 
	printArray(a,n); 
	return 0; 
} 

