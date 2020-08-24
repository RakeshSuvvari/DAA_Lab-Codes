#include <stdio.h> 
  
//towers of hanoi
void towersofhanoi(int n, char from_rod, char to_rod, char inter_rod);

int main() 
{ 
    int n;
    printf("enter no. disks:\n");
    scanf("%d",&n);
    
    towersofhanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    
    return 0; 
} 

void towersofhanoi(int n, char from_rod, char to_rod, char inter_rod) 
{ 
    
    if (n == 1) 
    {	
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod); 
        return;
    } 
    
    towersofhanoi(n-1, from_rod, inter_rod, to_rod);
    
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    towersofhanoi(n-1, inter_rod, to_rod, from_rod);
    
} 
  

