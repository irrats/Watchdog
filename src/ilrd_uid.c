
#include <time.h> /*time*/
#include <unistd.h> /* getpid */
#include <sys/types.h>/* pid_t*/

#include "ilrd_uid.h"


const ilrd_uid_t BadUID = {0};


ilrd_uid_t UIDCreate(void)
{
	ilrd_uid_t new_uid;
	static volatile int i = 0;
	
	new_uid.counter = __sync_add_and_fetch(&i, 1);
	new_uid.pid = getpid();
	new_uid.created_time = time(0);
	
	return new_uid;
}


int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2)
{
	return !((int)(uid1.counter - uid2.counter) + (int)(uid1.pid - uid2.pid) + (int)(uid1.created_time - uid2.created_time));	
}
