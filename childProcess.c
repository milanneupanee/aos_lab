#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        // Error handling if fork fails
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
    // Code executed by the child process
        printf("Hello, I am the  child process! My PID is %d.\n", getpid());
    child_pid = fork();

    if (child_pid == -1) {
        // Error handling if fork fails
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // Code executed by the child process
        printf("Hello, I am the grand child process! My PID is %d.\n", getpid());
    } else {
        // Code executed by the parent process
        printf("Hello, I am the child process! My PID is %d, and my child's PID is %d.\n", getpid(), child_pid);
    }
    } else {
        // Code executed by the parent process
        printf("Hello, I am the parent process! My PID is %d, and my child's PID is %d.\n", getpid(), child_pid);
    }

    return 0;
}


