#ifndef __ILRD_UID_H__
#define __ILRD_UID_H__

#include <stddef.h> /* size_t */
#include <sys/types.h> /* pid_t, time_t */


typedef struct ilrd_uid ilrd_uid_t;

struct ilrd_uid
{
    size_t counter;
    pid_t pid;
    time_t created_time;
};

/*
 * Description: The function returns a new unique id
 * Parameters: nothing
 * Return: @ilrd_uid_t - new unique id
 * Time complexity: O(1)
*/
ilrd_uid_t UIDCreate(void);

/*
 * Description: The function compares two UID's
 * Parameters: @uid1, @uid2 are unique ID's to compare
 * Return: bool, 1 - true, 0 - false
 * Time complexity: O(1)
*/
int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2);

/*
 * Description: The constant variable with value of ilrd_uid_t, which can not be assigned to valid tasks
 */
extern const ilrd_uid_t BadUID;

#endif /* __ILRD_UID_H__ */
