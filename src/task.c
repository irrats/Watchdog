
#include <stdlib.h>
#include <assert.h>

#include "task.h"
#include "utils.h"



struct task
{
    int (*task_func)(void *params);
    void *params;
    size_t lap;
    int is_repeated;
    ilrd_uid_t uid;
    time_t interval;
    time_t exec_time;
};

task_t *TaskCreate(ilrd_uid_t uid, time_t interval, int is_repeating, int (*task_func)(void *params), void *params)
{	
	task_t *new_task = (task_t*)malloc(sizeof(task_t));
	
	assert(NULL != task_func);
	
	
	if(NULL == new_task)
	{
		LOGERROR("SORRY, NO MEMORY FOR YOU(task)");
		return NULL;
	}
	
	new_task -> task_func = task_func;
	new_task -> params = params;
	new_task -> lap = 0;
	new_task -> is_repeated = is_repeating;
	new_task -> uid = uid;
	new_task -> interval = interval;
	new_task -> exec_time = time(NULL) + interval;
	
	return new_task;
}

void TaskDestroy(task_t *task)
{
	free(task); 
}

int TaskExecute(task_t *task)
{
	assert(NULL != task);
	return task->task_func(task->params);
}

int TaskIsRepeating(task_t *task)
{
	assert(NULL != task);
	return task->is_repeated;
}
time_t TaskGetTime(task_t *task)
{
	assert(NULL != task);
	return task->exec_time;
}


ilrd_uid_t TaskGetUID(task_t *task)
{
	assert(NULL != task);
	return task->uid;
}

void TaskCalculateNewTime(task_t *task)
{
	assert(NULL != task);
	task->exec_time = time(NULL) + task->interval;

}
/**********************************************************************************/

time_t TaskGetInterval(task_t *task)
{
	assert(NULL != task);
	return task->interval;
}

time_t TaskSetInterval(task_t *task, time_t new_interval)
{
	assert(NULL != task);
	return task->interval = new_interval;
}

void TaskSetONRepeat(task_t *task)
{
	assert(NULL != task);
	task->is_repeated = 1;
}

void TaskSetOFFRepeat(task_t *task)
{
	assert(NULL != task);
	task->is_repeated = 0;
}

size_t TaskGetLap(task_t *task)
{
	assert(NULL != task);
	return task->lap;
}















