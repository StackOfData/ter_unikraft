#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

// Conversion en micro seconde
long toMicroSec (struct timeval t) {
    return t.tv_sec * 1000000 + t.tv_usec;
}

void printTime(struct timeval t){
    fprintf(stdout, "%d s %d us\n", t.tv_sec, t.tv_usec);
    fprintf(stdout, "%ld s %ld us\n", t.tv_sec, t.tv_usec);

    return;
}

int main (void) {
    struct timeval t1, t2;
    int i, res;

    res = gettimeofday(&t1, NULL);  assert(res == 0);
    res = gettimeofday(&t2, NULL); assert(res == 0);
    
    fprintf(stdout, "%ld\n", toMicroSec(t2)-toMicroSec(t1));
}