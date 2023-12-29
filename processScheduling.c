#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int burst_time[n],waiting_time[n],turn_around_time[n];
	float total_waiting_time=0,total_turnaround_time=0;
	for (i=0;i<n;i++){
		printf("Enter the burst time of process %d:",i+1);
		scanf("%d",&burst_time[i]);
	}
	for (i=0;i<n;i++){
		printf("Enter the waiting time of process %d:",i+1);
		scanf("%d",&waiting_time[i]);
	}
	waiting_time[0]=0;
	for (i=1;i<n;i++){
		waiting_time[i]=waiting_time[0]+burst_time[i];
		total_waiting_time += waiting_time[i];
	 	}
	 for(i=0;i<n;i++){
	 	turn_around_time[i]=waiting_time[i]+burst_time[i];
	 	total_turnaround_time+=turn_around_time[i];
	 }
	 printf("Process \tbrust time\t waiting time\t turnaround_time\n");
	 for(i=0;i<n;i++){
	 printf("%d\t%d\t%d\t%d\n",i+1,burst_time[i],waiting_time[i],turn_around_time[i]);
	 }
	 printf("Average waiting time:%.2f\n",total_waiting_time/n);
	 printf("Average turnaround time:%.2f\n",total_turnaround_time/n);
	 return 0;
}

