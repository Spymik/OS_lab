#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Before 1st fork(): Process ID: %d, Message: Hello from parent\n", getpid());

    pid_t first_child = fork();

    if (first_child == 0) { 
        printf("After 1st fork(): Process ID: %d, Message: Hello from first child\n", getpid());
    } else { // 
        printf("Between forks(): Process ID: %d, Message: Hello from parent\n", getpid());
        pid_t second_child = fork();

        if (second_child == 0) { 
            printf("After 2nd fork(): Process ID: %d, Message: Hello from second child\n", getpid());
        }
    }

    return 0;
}
