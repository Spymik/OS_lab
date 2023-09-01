#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


int calculateUnitDigit(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * n) % 10;
    }
    return result;
}

int main() {
    int n;
    
 
    printf("Enter n (1e7 < n < 1e8): ");
    scanf("%d", &n);

    if (n < 1e7 || n >= 1e8) {
        printf("Invalid input. n must be in the range 1e7 < n < 1e8.\n");
        return 1;
    }

   
    clock_t startTime;

    
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) { 
        
        int unitDigit = calculateUnitDigit(n);
        printf("Child process: Unit's digit of %d^%d is %d\n", n, n, unitDigit);
    } else { 
        
        startTime = clock();
        
        wait(NULL);

        
        clock_t endTime = clock();
        double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf("Parent process: Time taken by the child process: %.6f seconds\n", elapsedTime);
    }

    return 0;
}
