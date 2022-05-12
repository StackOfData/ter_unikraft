#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


int main (void) {
    struct timeval tv;
    tv.tv_sec = 180; // 3 min
    tv.tv_usec = 0;
    select(0, NULL, NULL, NULL, &tv);
    return 0;
}