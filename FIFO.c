#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	int i=0,j=0,k=0,i1=0,m,n,rs[30],flag=1,p[30];
	system("clear");
	printf("FIFO page replacememt algorithm..\n");
	printf("Enter the np. of frames:");
	scanf("%d",&n);
	printf("Enter the refrence string:");
	while(1){
		scanf("%d",&rs[i]);
		if (rs[i]==0)
		break;
		i++;
	}
	m=i;
	for(j=0;j<n;j++)
	p[j]=0;
	for(i=0;i<m;i++){
		flag=1;
		for(j=0;j<n;j++)
		if(p[j]==rs[i]){
			printf("Data already in page...\n");
			flag=0;
			break;
		}
		if(flag==1){
			p[i]=rs[i];
			i1++;
			k++;
			if(i1==n)
			i1=0;
			for(j=0;j<n;j++){
				printf("\nPage%d:%d",j+1,p[j]);
				if(p[j]==rs[i])
				printf
				4("*");
			}
			printf("\n\n");
		}
	}
	printf("Total no page faults=%d",k);
	return 0;
}
