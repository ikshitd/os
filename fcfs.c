#include <stdio.h> 
typedef struct Process {
	int id; 
	int ct; 
	int arrival; 
	int burst;
	int tat; 
	int wt;
}P;
int main() {
	int n; 
	printf("Enter the number of processes"); 
	puts(""); 
	scanf("%d", &n); 
	P a[n]; 
	int temp[n]; 
	for(int i = 0; i < n; i++) {
		printf("Enter the arrival and the burst time of the %d process: ", i + 1); 
		a[i].id = i + 1; 
		scanf("%d%d", &(a[i].arrival), &(a[i].burst)); 
		temp[i] = a[i].burst; 
		puts(""); 
	}
	int done = 0;
	int at = -1; 
	while(done != n) {
		int p = -1;  // stores the index of the process to be executed at
		int tempat = 1e9 + 7;
		for(int i =0 ; i < n; i++) {
			if(a[i].arrival <= at && temp[i]) {
				if(a[i].arrival < tempat) {
					p = i; 
					tempat = a[i].arrival; 
				}
			}
		}
		if(p == -1) at++; 
		else {
			at += temp[p]; 
			temp[p] = 0; 
			a[p].ct = at; 
			done++; 
		}
	}
printf("Process\tArrival time\t Burst time\t Completiton Time\tturn around time\t waiting time");
	puts(""); 
	double average_tat = 0; 
	double average_wt = 0;
	for(int i = 0; i < n; i++) {
		a[i].tat = a[i].ct - a[i].arrival; 
		a[i].wt = a[i].tat - a[i].burst; 
		average_tat += a[i].tat; 
		average_wt += a[i].wt; 
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", a[i].id, a[i].arrival, a[i].burst, a[i].ct, a[i].tat, a[i].wt); 
		puts(""); 
	}
	printf("The average waiting time is : %lf and the average turn around time is : %lf", average_wt / (double)n, average_tat / (double)n); 
	puts("");
	return 0; 
}
