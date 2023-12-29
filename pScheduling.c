#include<stdio.h>
int main(){
	int i,n,j,temp;
	float avg_wt, avg_tat,twt,ttat;
	int bt[20],wt[20],tat[20],p[20];
	printf("Enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf ("Enter the burst time of processes %d",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(bt[i]>bt[j]){
			temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			
		}
	
	}
	}
	wt[0]=0;
	tat[-1]=0;
	tat[0]=bt[0];
	
	for(i=0;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		twt+=wt[i];
		tat[i]=tat[i-1]+bt[i];
		ttat+=tat[i];
	}
	printf("process\tbursttime\twatingtime\tturnaroundtime\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time:%.2f\n",twt/n);
	printf("Average turnarounnd time:%.2f\n",(ttat+tat[0])/n);
	return 0;
}
