#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>   

int dice()
{
    srand(time(NULL)^(getpid()<<16));
    return (rand()%6)+1;
}
int snakeladder(int pos)
{
    switch (pos)
    {
    case 19: return 56;
    case 34: return 94;
    case 65: return 79;
    case 78: return 97;
    case 35: return 6;
    case 95: return 15;
    case 60: return 42;
    case 98: return 50;
    default: return pos;
    }
}
int main()
{
    int p1=0;
    int p2=0;
    pid_t pid;
    pid=fork();
    while(p1<100 && p2<100)
    {
        if(pid<0)
        {
            printf("fork failed");
        }
        else if(pid==0)
        {
            int d=dice();
            p1=snakeladder(p1+d);
            if(p1>=100){
            p1=100;}
            printf("P1 roll %d\n",d);
            printf("P1 position %d\n",p1);
            sleep(2);
        }
        else{
            int d=dice();
            p2=snakeladder(p2+d);
            if(p2>100){
                p2=100;
            }
            printf("P2 roll %d\n",d);
            printf("P2 position %d\n",p2);
            sleep(2);
        }
    }
}

    
