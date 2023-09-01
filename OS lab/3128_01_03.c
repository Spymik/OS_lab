#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n;

    
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);

   
    __pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) { 
        printf("First prime number after m: ");
        while (!isPrime(m)) {
            m++;
        }
        printf("%d\n", m);

        printf("Consecutive primes:\n");
        for (int i = 0; i < n; i++) {
            do {
                m++;
            } while (!isPrime(m));
            printf("%d ", m);
        }
        printf("\n");
    } else { 
        wait(NULL); 
    }

    return 0;
}
