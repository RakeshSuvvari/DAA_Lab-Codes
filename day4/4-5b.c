#include<stdio.h>
//program for 3-way Merge Sort 
void mergesort (int a[], int l, int r);
void merge (int a[], int l, int m, int r);
int min(int x, int y, int z);
int main ()
{
	printf ("Enter the size of the array: ");
	int n;
    	scanf ("%d", &n);
	int a[n];
    	printf ("Enter the elements of the array:\n");
	for (int i = 0; i < n; i++)
      	{
		printf ("Enter %dth element:", i);
		scanf ("%d", &a[i]);
      	}
      	mergesort(a,0,n-1);
}


void mergesort (int a[], int l, int r)
{
    	if (l < r)
      	{	
		int m = (l+r+1)/3;
		mergesort (a, l, m-1);
		mergesort (a, m, 2*m-1);
		mergesort (a, 2*m, r);
		merge (a, l, m, r);
      	}
}

// Merges three subarrays of arr[]. 
void merge (int a[], int l, int m, int r)
{
    	int n1 = m;
    	int n2 = m; 
    	int n3 = r-2 * m+1;
    	
    	/* create temp arrays */
	int a1[n1], a2[n2], a3[n3];
	int i, j, k, t;
	
	/* Copy data to temp arrays a1[] and a2[] and a3[] */
	for (i = l; i <= m - 1; i++)
      		a1[i-l] = a[i];
	for (j = m; j <= 2 * m-1; j++)
		a2[j - m] = a[j];
	for (k = 2 * m; k <= r; k++)
		a3[k - 2 * m] = a3[k];

    	i = j = k = 0; // Initial index of subarray 
    	t = l;  // Initial index of merged subarray 
	
	/* Merge the temp arrays back into a[l..r]*/
    	while (i < n1 && j < n2 && k < n3)
      	{
		int p = min(a1[i], a2[j], a3[k]);
		printf("%d\n",p);
		a[t] = p;

		if (a1[i] == p)
	 		i++;
		else if (a2[j] == p)
			j++;
		else
		{
			k++;
		}
			t++;
      	}
      	
      	/* Copy the remaining elements of a1[], if there 
	are any */
	while (i < n1) 
	{ 
		a[t] = a1[i];
		i++; 
		t++; 
	} 

	/* Copy the remaining elements of a2[], if there 
	are any */
	while (j < n2) 
	{ 
		a[t] = a2[j];
		j++; 
		t++; 
	} 
	
	/* Copy the remaining elements of a3[], if there 
	are any */
	while (k < n3) 
	{ 
		a[t] = a3[k];
		k++; 
		t++; 
	}
}

int min(int x, int y, int z)
{

	if (x < y && x < z)
		return x;
	
	 if (y < x && y < z)
		return y;
	
	 if (z < x && z < y)
		return z;



}

