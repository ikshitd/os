#include <stdio.h> 
typedef struct Process {
	int id; 
	int arrival; 
	int burst;
	int ct; 
	int wt; 
	int tat; 
}P; 
int main() {
	int n; 
	printf("Enter the number of processes"); puts(""); 
	scanf("%d", &n); 
	P a[n]; 
	int temp[n]; 
	for (int i = 0; i < n; i++) {
		printf("Enter the arrival time and the burst time"); 
		puts(""); 
		scanf("%d%d", &a[i].arrival, &a[i].burst);
		a[i].id = i+1; 
		temp[i] = a[i].burst; 
	}
	int quant; 
	printf("Enter the time quantum for the process"); puts(""); 
	scanf("%d", &quant); 
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j].arrival > a[j+1].arrival) {
				P t = a[j]; 
				a[j] = a[j+1]; 
				a[j+1] = t; 
				int m = temp[j];
				temp[j] = temp[j+1]; 
				temp[j+1] = m; 
			}
		}
	}
	int done = n; 
	bool flag = false; 
	for (int s = 0, i = 0; done != 0; ) {
		if (temp[i] <= quant && temp[i] > 0) {
			s = s + temp[i]; 
			temp[i] = 0; 
			flag = true; 
		} else if (temp[i] > 0) {
			temp[i] -= quant; 
			s += quant; 
		}
		if (temp[i] == 0 && flag == true) {
			done -= 1; 
			a[i].ct = s;
			flag = false; 
		}
		if (i != n - 1 &&  a[i].arrival <= s) {
			i += 1; 
		} else {
			i = 0; 
		}
	}
	float total_tat = 0; 
	float total_wt = 0; 
	for (int i = 0; i < n; i++) {
		a[i].tat = a[i].ct - a[i].arrival; 
		a[i].wt = a[i].tat - a[i].burst;
		total_tat += a[i].tat; 
		total_wt += a[i].wt;  
		printf("%d %d %d %d %d %d", a[i].id, a[i].arrival, a[i].burst, a[i].ct, a[i].tat, a[i].wt); 
		puts(""); 
	}
	printf("The avg turn around time is %f and the avg wt is %f", total_tat / n, total_wt / n); 
	puts(""); 
	return 0; 
}	
