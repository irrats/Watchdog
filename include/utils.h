#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

#define ASSERT(x) (NULL == x);

#define TEST_EQUAL(a, b) ((a) != (b)) ? printf("TEST FAIL! ERROR AT LINE: %d IN FILE: %s\n ",__LINE__, __FILE__) : puts("PASS");


#define DEAD (node_t*) 0xDEADBEEF

#define CAFE (void*) 0xCAFEBABE 


#ifndef NDEBUG
#define LOGERROR(str) fprintf(stderr, str);
#else
#define LOGERROR(str) 
#endif

#endif









