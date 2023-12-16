#include <stdio.h> 

int main() {
	int n; 
	int m; 
	printf("Enter the number of processes"); puts(""); 
	scanf("%d", &n); 
	printf("Enter the number of resources"); puts("");
	scanf("%d", &m);  
	int allocated[n][m]; 
	printf("Enter the number of allocated resources for each of the process"); 
	puts(""); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &allocated[i][j]); 
		}
	}
	int max[n][m]; 
	printf("Enter the number of allocated resources for each of the process"); 
	puts(""); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &max[i][j]); 
		}
	}
	printf("Enter the number of avaiable resources"); puts(""); 
	int available[m]; 
	for (int i =0 ; i < m; i++) {
		scanf("%d", &available[i]); 
	}
	int need[n][m]; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			need[i][j] = max[i][j] - allocated[i][j]; 
		} 
	} 
	int f[n], ans[n], idx = 0; 
	for (int i = 0; i < n; i++) {
		f[i] = -1; 
	}
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			if (f[i] == -1) {
				bool flag = false; 
				for (int j = 0; j < m; j++) {
					if (need[i][j] > available[j]) {
						flag = true; 
						break; 
					}
				}
				if (flag == false) {
					ans[idx++] = i; 
					for (int a = 0; a < m; a++) {
						available[a] += allocated[i][a];
					}
					f[i] = 1; 
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (f[i] == -1) {
			printf("The sequence is not safe"); 
			puts("");
			return 0; 
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]); 
	}
	puts(""); 
	return 0; 
}
