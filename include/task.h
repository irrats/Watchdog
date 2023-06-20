#ifndef __TASK_H__
#define __TASK_H__

#include <time.h> /* time_t */

#include "ilrd_uid.h" /* ilrd_uid_t */

typedef struct task task_t;

/*
struct task
{
    int (*task_func)(void *params);
    void *params;
    ilrd_uid_t uid;
    time_t interval;
    time_t exec_time;
    int is_repeated;
};
*/

/*
 * Description: The function creates a new Task 
 * Parameters: @uid is an unique id for task,
 *             @is_repeated is a boolean identifier for whether or not the task is to be repeated 
 *             @interval is an interval in seconds through which task will be executed (or repeated if @is_repeated is 1)
 *             @task_func is a function to be executed
 *             @params is a parameters for @task_func
 * Return: @task_t* is a pointer to the created Task or NULL if failed
 * Time complexity: O(1)
*/
task_t *TaskCreate(ilrd_uid_t uid, time_t interval, int is_repeating, int (*task_func)(void *params), void *params);

/*
 * Description: The function destroys a task 
 * Parameters: @task - the task to be destroyed
 * Return: nothing
 * Time complexity: O(1)
*/
void TaskDestroy(task_t *task);

/*
 * Description: The function invokes the function within the task
 * Parameters: @task - the task to be executed
 * Return: @int is a status with which task was executed
 * Time complexity: O(1)
*/
int TaskExecute(task_t *task);

/*
 * Description: The function returns the execution time of a given task
 * Parameters: @task - the task
 * Return: @time_t - execution time of task
 * Time complexity: O(1)
*/
time_t TaskGetTime(task_t *task);

/*
 * Description: sets new time for repeated tasks
 * Parameters: @task - the task for which new time is calculated
 * Return: nothing
 * Time complexity: O(1)
*/
void TaskCalculateNewTime(task_t *task);

/*
 * Description: checks whether a task is repeated
 * Parameters: @task - the task to be checked
 * Return: 1 on true, 0 on false
 * Time complexity: O(1)
*/
int TaskIsRepeating(task_t *task);

/*
 * Description: The function returns uid of a given task
 * Parameters: @task - the task
 * Return: @ilrd_uid_t - uid of task
 * Time complexity: O(1)
*/
ilrd_uid_t TaskGetUID(task_t *task);

/**************************************************************************************************/

/*
 * Description: The function returns interval of a given task
 * Parameters: @task - the task
 * Return: @ilrd_uid_t - interval of task
 * Time complexity: O(1)
*/
time_t TaskGetInterval(task_t *task);

/*
 * Description: The function set new interval of a given task
 * Parameters: @task - the task, new interval(sec).
 * Return: @ilrd_uid_t - new interval of task
 * Time complexity: O(1)
*/
time_t TaskSetInterval(task_t *task, time_t new_interval);

/*
 * Description: The function set is_repeated param to 1
 * Parameters: @task - the task
 * Return: 
 * Time complexity: O(1)
*/

void TaskSetONRepeat(task_t *task);

/*
 * Description: The function set is_repeated param to 0
 * Parameters: @task - the task
 * Return: 
 * Time complexity: O(1)
*/

void TaskSetOFFRepeat(task_t *task);

/*
 * Description: The function return lap param from the task
 * Parameters: @task - the task
 * Return: size_t 
 * Time complexity: O(1)
*/
size_t TaskGetLap(task_t *task);





#endif /* __TASK_H__ */

