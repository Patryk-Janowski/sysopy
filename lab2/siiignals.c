#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("received SIGINT\n");
    else if (signo == SIGKILL)
        printf("received SIGKILL\n");
    else if (signo == SIGQUIT)
        printf("received SIGQUIT\n");
    else if (signo == SIGABRT)
        printf("received SIGABRT\n");    
    else if (signo == SIGTERM)
        printf("received SIGTERM\n");
    else if (signo == SIGHUP)
        printf("received SIGHUP\n");
    else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}


int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    if (signal(SIGQUIT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGQUIT\n");
    if (signal(SIGHUP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGHUP\n");
    if (signal(SIGABRT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGABRT\n");
    if (signal(SIGTERM, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGTERM\n");
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    
    //  1       HUP (hang up)
    //  2       INT (interrupt)
    //  3       QUIT (quit)
    //  6       ABRT (abort)
    //  9       KILL (non-catchable, non-ignorable kill)
    while(1) 
        sleep(1);
    return 0;
}

// sudo kill -s INT $(pidof siig)