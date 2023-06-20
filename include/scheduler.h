#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__


#include <stddef.h> /* size_t */
#include <time.h>  /* time_t */

#include "ilrd_uid.h" /* ilrd_uid_t */



typedef struct scheduler sched_t;

/*
struct scheduler
{
    pq_t *tasks;
    int is_running;
    maybe smth else 
};
*/

/*
 * Description: The function creates a new Scheduler 
 * Parameters: none
 * Return: @sched_t* is a pointer to the created Scheduler or NULL if failed
 * Time complexity: O(1)
*/
sched_t *SchedCreate(void);

/*
 * Description: The function destroys the Scheduler
 * Parameters: @sched - pointer to the scheduler
 * Return: nothing
 * Time complexity: O(1)
*/
void SchedDestroy(sched_t *sched);

/*
 * Description: The function adds @task_func to the tasks list.
 * Parameters: @sched - pointer to the scheduler
 *  @interval_in_sec is a time in second after which task should be executed relatively from now (or should be repeated if is_repeating == 1)
 *  @is_repeating is a boolean identifier for whether or not the task is to be repeated
 *  @task_func is a function, that will be executed
 *  @params is a parameters for @task_func.
 * Return: @uid_t is a unique ID for added task,
 * or bad ID if task was not added.
 * Time complexity: O(n)
*/
ilrd_uid_t SchedAddTask(sched_t *sched, time_t interval_in_sec, int is_repeating, int (*task_func)(void *params), void *params);

/*
 * Description: The function removes a task from the scheduler
 * Parameters: 
 *  @sched - pointer to the scheduler
 *  @uid - uid of the task to be removed
 * Return: nothing
 * Time complexity: O(n)
*/
void SchedRemoveTask(sched_t *sched, ilrd_uid_t uid);

/*
 * Description: The function starts the scheduling
 * Parameters: @sched - a pointer to the scheduler to be run
 * Return: nothing
 * Time complexity: O(∞)
 */
int SchedRun(sched_t *sched);

/*
 * Description: The function stops execution of the tasks in scheduler
 * Parameters: @sched - a pointer to the scheduler to be stopped
 * Return: 
 * Time complexity: O(1)
*/
void SchedStop(sched_t *sched);

/*
 * Description: The function counts the number of tasks in a scheduler
 * Parameters: @sched - a pointer to the scheduler
 * Return: @size_t - the size of the scheduler
 * Time complexity: O(1)
*/
size_t SchedSize(const sched_t *sched);

/*
 * Description: The function checks if the Scheduler is empty
 * Parameters: @sched - a pointer to the scheduler
 * Return: @int - boolean value 1 if it is empty, 0 if it is not empty
 * Time complexity: O(1)
*/
int SchedIsEmpty(const sched_t *sched);

/*
 * Description: The function clears the Scheduler
 * Parameters: @sched - pointer to the Scheduler to be cleared
 * Return: nothing
 * Time complexity: O(n)
*/
void SchedClear(sched_t *sched);


#endif /* __SCHEDULER_H__ */
