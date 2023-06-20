#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200112L
#define  _XOPEN_SOURCE

#include <signal.h>
#include <unistd.h> 
#include <sys/types.h>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <sys/wait.h> 
#include <pthread.h>
#include <scheduler.h>
#include <wd.h>
#include "help.h"

#define COLOR "\033[1;33m" 
#define OFFCOLOR "\033[0m"

char *PATH = NULL;

volatile sig_atomic_t STOPFLAG = 1;
volatile sig_atomic_t ISALIVE = 1;

int Signal(void *data);
int Check(void *data);
int Stop(void *sched);
void Handler_1();
void Handler_2();
int ReviveUser(void *data);

int main(int argc, char *argv[])
{
    int inter = 0;
    int thres = 0;

    sched_t *sched = NULL; 
    struct sigaction user1 = {0};
    struct sigaction user2 = {0};
    
    NO(argc);

    printf("                                   DOG ID: %d  USER ID: %d\n", getpid(), getppid());
    PATH = argv[0];

    user1.sa_handler = Handler_1;
    user1.sa_flags = 0;
    sigemptyset(&user1.sa_mask);
    sigaction(SIGUSR1, &user1, NULL);

    user1.sa_handler = Handler_2;
    user1.sa_flags = 0;
    sigemptyset(&user2.sa_mask);
    sigaction(SIGUSR2, &user2, NULL);

    inter = atoi(getenv("INTERVAL"));
    thres = atoi(getenv("THRESHOLD")) * inter;

    sched = SchedCreate();
    if(NULL == sched)
    {
        return 1;
    }

    SchedAddTask(sched, inter, 1, Signal, NULL);
    SchedAddTask(sched, thres, 1, Check, argv);
    SchedAddTask(sched, 1, 1, Stop, sched);

    SchedRun(sched);
    SchedDestroy(sched);
    puts("Sched dog destroy!");

    return 0;
}

/*********************TASKS************************************/

int Signal(void *data)
{
    puts(COLOR"Send Signal from Dog"OFFCOLOR);
    NO(data);
    kill(getppid(), SIGUSR1); 
    return 0;
}

int Check(void *data)
{
    puts("Check Signal from Dog");
    if(ISALIVE == 1)
    {
        ISALIVE = 0;
        return 0;
    }
    return ReviveUser(data);
}

int Stop(void *sched)
{   
    puts("Stop Signal from Dog");
    if(0 == STOPFLAG)
    {
        puts("Dog stopped\n");
        SchedStop((sched_t *)sched);
    }
    return 0;
}
/*******************HANDLERS***************************************/

void Handler_1()
{
    write(1, "HANDLER_1 FROM DOG\n", 19);
    ISALIVE = 1; 
}

void Handler_2()
{
    write(1, "HANDLER_2 FROM DOG\n", 19);
    STOPFLAG = 0; 
}

/****************************************************************/

int ReviveUser(void *data)
{       
    puts("--------------------------------Resurrecting the User");
    execv(PATH,  (char**)data);
    puts("---------------------------------User Resurrection Failed");
    return WD_EXEC_FAILURE;
}
