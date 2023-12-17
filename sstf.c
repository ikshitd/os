#include <stdio.h> 
#include <math.h> 
#include <stdbool.h>

int main() {
	puts("Enter the number of disks"); 
	int n; 
	scanf("%d", &n); 
	printf("Enter the head of the sequence"); 
	puts(""); 
	int current; 
	scanf("%d", &current);
	int a[n]; 
	puts("Enter the sequence"); 
	for (int i =0 ; i < n; i++){
		scanf("%d", &a[i]); 
	} 
	int f[n];
	int ans[n]; 
	for (int i =0 ; i < n; i++) {
		f[i] = -1;
		ans[i] = -1;  
	}
	int idx = 0; 
	for (int k = 0; k < n; k++) {
		int mi = 1e9 + 7; 
		int min = -1; 
		for (int i = 0; i < n; i++) {
			if (f[i] == -1) {
				int dist = fabs(current - a[i]); 
				if (dist < mi) {
					mi = dist; 
					min = i; 
				}
			} 
		}
		f[min] = 1; 
		ans[idx++] = a[min]; 
		current = a[min]; 
	}
	printf("The sequence is : "); puts(""); 
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]); 
	}
	puts(""); 
	return 0; 
}
