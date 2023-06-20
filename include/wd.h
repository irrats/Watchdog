#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

#include <stddef.h> /* size_t */
#include <time.h>  /* time_t */

typedef enum status
{
    WD_SUCCESS,
    WD_FORK_FAILURE,
    WD_EXEC_FAILURE,
    WD_PTHREAD_CREATE_FAILURE
}wd_status_t;

/* NB: SIGUSR1 & SIGUSR2 signals are reserved for the watchdog exclusively and are not to be used by the client program */

/*
 * Description: The function runs the watchdog to keep the program running. 
 * The function reserves SIGUSR1 signal for itself. The program will be restarted in case @threshold is reached.
 * Parameters: @argc - the number of command line arguments passed in
 * @argv - the actual command line arguments
 * @interval - time interval in seconds between signals being sent to the watchdog
 * @threshold - the maximum number of missed signals allowed before program restart
 * Return: @status_t - the status of the watchdog. Function returns SUCCESS only in case the watchdog is active.
*/
wd_status_t KeepMeAlive(int argc, const char *argv[], time_t interval, size_t threshold);


/*
 * Description: The function disactivates the watchdog. Function returns only when the watchdog is disabled.
 * Parameters: none
 * Return: none
*/
void DoNotResuscitate();


#endif /* __WATCHDOG__ */