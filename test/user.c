#include <stdio.h>
#include <unistd.h>

#include "wd.h"
#define COLOR "\033[1;36m" 
#define OFFCOLOR "\033[0m"


int main(int argc, const char* argv[])
{
    int x = 50;
    puts(COLOR"Start"OFFCOLOR);

    KeepMeAlive(argc, argv, 3, 3);

    while(0 < x)
    {
        x = sleep(x);
    }

    DoNotResuscitate(); 

    puts(COLOR"Stop"OFFCOLOR);
    return 0;
}