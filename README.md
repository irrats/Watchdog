# Watchdog
Simple Watchdog
To run first we need to compile separately user and dog:
gcc watchdog.c task.c scheduler.c ilrd_uid.c pq.c dll.c srtll.c ../test/user.c -o user -I ../include
gcc task.c scheduler.c ilrd_uid.c dogaux.c pq.c dll.c srtll.c -o dog -I ../include

Then run ./user

