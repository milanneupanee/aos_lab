//deadlock
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *function1();
void *function2();
pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;
int main(){
	pthread_mutex_init(&first_mutex,NULL);
	pthread_mutex_init(&second_mutex,NULL);
	pthread_t one,two;
	pthread_create(&one,NULL,function1,NULL);
	pthread_create(&two,NULL,function2,NULL);
	pthread_join(one,NULL);
	pthread_join(two,NULL);
	printf("Thread joined\n")
}
void *function1(){
	pthread_mutex_lock(&first_mutex);
	printf("Thread one acquire first_mutex\n");
	sleep(1);
	
	pthread_muitex_unlock(&first_mutex);
	printf("Yhread one released first_mutex\n");
	pthread_mutex_lock(&second_mutex);
	printf("Thread one acquired second mutex");
	pthread_mutex_unlock(&second_mutex):
	Printf("Thread one released second_mutex");
}
void *function2(){
	pthread_mutex_lock(&second_mutex);
	printf("Thread two acquire second_mutex\n");
	sleep(1);
	
	pthread_muitex_unlock(&second_mutex);
	printf("Yhread two released second_mutex\n");
	pthread_mutex_lock(&first_mutex);
	printf("Thread two acquired first mutex");
	pthread_mutex_unlock(&first_mutex):
	Printf("Thread two released first_mutex");
}
