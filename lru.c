#include <stdio.h> 

int main() {
	printf("Enter the number of pages"); 
	puts(""); 
	int n; 
	scanf("%d", &n); 
	printf("Enter the page sequence"); puts("");
	int pages[n];  
	for (int i = 0; i < n; i++) {
		scanf("%d", &pages[i]); 
	}
	int m; 
	printf("Enter the number of frames"); puts(""); 
	scanf("%d", &m); 
	int frame[m];
	int distance[n];
	int occupied = 0;
	int pagefault = 0; 
	for (int i = 0; i < m; i++) {
		frame[i] = -1; 
	}
	printf("Page\tframes"); puts(""); 
	for (int i = 0; i < n; i++) {
		int page = pages[i];
		printf("%d\t", page); 
		bool found = false; 
		for (int j = 0; j < occupied; j++) {
			if (page == frame[j]) {
				found = true; 
				break; 
			}
		}
		if (!found) {
			if (occupied < m) {
				frame[occupied] = page; 
				pagefault += 1; 
				occupied += 1; 
			} else  {
				int mx = -1e9;
				int idx; 
				for (int j = 0; j < m; j++) {
					distance[j] = 0; 
					for (int k = i - 1; k >= 0; k--) {
						++distance[j]; 
						if (frame[j] == pages[k]) {
							break; 
						}
					}
					if (distance[j] > mx) {
						mx = distance[j]; 
						idx = j; 
					}
				}	
				frame[idx] = page; 
				pagefault += 1; 
			}
		}
		for (int j = 0; j < m; j++) {
			printf("%d ", frame[j]); 
		}
		puts(""); 
	}
	printf("The total number of pagefaults are : %d", pagefault); 
	puts(""); 
}
