#include <stdio.h> 
#include <unistd.h> 
#include <math.h> 

typedef struct fcfs {
	int process; 
	int burst; 
	int arrival;
	int tat; 
	int wt; 
	int ct;  
}fcfs; 

void sort(fcfs *a, int n) 	{
	for(int i = 0; i < n - 1; i++) { 
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j].arrival > a[j + 1].arrival) {
				fcfs k = a[j]; 
				a[j] = a[j + 1]; 
				a[j + 1] = k; 
			}
		}
	}
	return; 
}
int main() {
	int n; 
	printf("Enter the number of processes"); 
	puts(""); 
	scanf("%d", &n); 
	fcfs a[n]; 
	for(int i = 0; i < n; i++) {
		a[i].process = i + 1;
		printf("Enter the cpu burst time "); 
		scanf("%d", &(a[i].burst)); 
		printf("Enter the arrival time "); 
		scanf("%d", &(a[i].arrival)); 
	}
	sort(a, n); 
	for(int i =0 ; i < n; i++) {
		printf("%d %d %d", a[i].process, a[i].burst, a[i].arrival); 
		puts("");  
	}
	printf("Process\tArrival time\t Burst time\t Completiton Time\tturn around time\t waiting time");
	puts(""); 
	int current_time = 0; 
	double average_tat = 0; 
	double average_wt = 0;
	for(int i = 0; i < n; i++) {
		current_time += a[i].burst; 
		a[i].ct = current_time; 
		a[i].tat = a[i].ct - a[i].arrival; 
		a[i].wt = a[i].tat - a[i].burst; 
		average_tat += a[i].tat; 
		average_wt += a[i].wt; 
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d", a[i].process, a[i].arrival, a[i].burst, a[i].ct, a[i].tat, a[i].wt); 
		puts(""); 
	}
	printf("The average waiting time is : %lf and the average turn around time is : %lf", average_wt / (double)n, average_tat / (double)n); 
	puts("");
	return 0; 
}
