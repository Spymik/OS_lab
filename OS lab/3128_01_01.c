#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    __pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) { 
        printf("Child Process: Next even number: %d\n", (n % 2 == 0) ? n + 2 : n + 1);
    } else { 
        printf("Parent Process: Next odd number: %d\n", (n % 2 == 0) ? n + 1 : n + 2);
    }

    return 0;
}
