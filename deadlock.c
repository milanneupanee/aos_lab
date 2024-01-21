#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// Global mutex locks
pthread_mutex_t first_mutex;  
pthread_mutex_t second_mutex;

// Function declarations
void *function1();
void *function2();

int main() {
    // Initialize the mutex locks
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    // Declare thread identifiers
    pthread_t one, two;

    // Create threads and specify the functions they will run
    pthread_create(&one, NULL, function1, NULL);
    pthread_create(&two, NULL, function2, NULL);

    // Wait for threads to finish execution
    pthread_join(one, NULL);
    pthread_join(two, NULL);

    // Display a message indicating that the threads have joined
    printf("Threads joined\n");

    // Cleanup: Destroy mutex locks
    pthread_mutex_destroy(&first_mutex);
    pthread_mutex_destroy(&second_mutex);

    return 0;
}

// Function executed by the first thread
void *function1() {
    // Acquire the first mutex lock
    pthread_mutex_lock(&first_mutex);
    printf("Thread ONE acquired first_mutex\n");

    // Sleep for 1 second to simulate some work
    sleep(1);

    // Acquire the second mutex lock
    pthread_mutex_lock(&second_mutex);
   printf("Thread ONE acquired second_mutex\n");

    // Release the second mutex lock
    pthread_mutex_unlock(&second_mutex);
    printf("Thread ONE released second_mutex\n");

    // Release the first mutex lock
    pthread_mutex_unlock(&first_mutex);
    printf("Thread ONE released first_mutex\n");
	return 0;
    // The thread implicitly returns NULL
}

// Function executed by the second thread
void *function2() {
    // Acquire the second mutex lock
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO acquired second_mutex\n");

    // Sleep for 1 second to simulate some work
    sleep(1);

    // Acquire the first mutex lock
    pthread_mutex_lock(&first_mutex);
    printf("Thread TWO acquired first_mutex\n");

    // Release the first mutex lock
    pthread_mutex_unlock(&first_mutex);
    printf("Thread TWO released first_mutex\n");

    // Release the second mutex lock
    pthread_mutex_unlock(&second_mutex);
    printf("Thread TWO released second_mutex\n");
	return 0;
    // The thread implicitly returns NULL
}

