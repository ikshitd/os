
#include <stdio.h> 
#include <math.h> 


int main() {
	int n; 
	puts("Enter the number of disk"); 
	scanf("%d", &n); 
	int a[n]; 
	printf("Enter the disk sequences"); 
	puts(""); 
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	}
	int seek_count = 0; 
	printf("Enter the initial head of the sequence"); 
	puts(""); 
	int current; 
	scanf("%d", &current);
	printf("The sequence is : %d", current); 
	for (int i = 0; i < n; i++) {
		int distance = fabs(current - a[i]); 
		seek_count += distance; 
		current = a[i]; 
		printf("%d ", currenvt); 
	}
	printf("The total numner of seek operations are : %d", seek_count); 
	puts(""); 
	return 0; 
}
