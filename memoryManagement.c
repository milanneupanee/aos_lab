//Memory Management fixed partitiong technique
#include<stdio.h>
#include<conio.h>
int main(){
	int ms,bs,nob,ef,n ,mp[10],tif=0,i,p=0;
	//clrscr();
	printf("Enter the total memory available in Bytes--");
	scanf("%d",&ms);
	printf("Enter the block size in butes--");
	scanf("%d",&bs);
	nob=ms/bs;
	ef=ms-nob*bs;
	printf("Enter the number of processes--");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("Enter memory required for the process %d--",i+1);
		scanf("%d",&mp[i]);
	}
	printf("\nNo. of Blocks available in memory --%d",nob);
	printf("\nPROCESS\t MEMORYREQUIRED\tALLOCATED\tINTERNALFRAGMENTATION");
	for (i=0;i&&p<nob;i++){
		printf("\n%d\t\t%d",i+1,mp[i]);
		if(mp[i]>bs)
		printf("\t\tNO\t\t--");
		else{
			printf("\t\tYES\t%d",bs-mp[i]);
			tif=tif+bs-mp[i];
			p++;
		}
	}
	if(i<n)
	printf("\nMemory is full,Remaining processes cannot be accomodated");
	printf("\nTotal Internal Fragmantation is %d",tif);
	printf("\nTotal External Fragmantation is %d",ef);
	getch();
	
	return 0;
}
