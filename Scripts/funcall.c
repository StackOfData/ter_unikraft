#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

#define NBITS 1000000

int randomFunc(void) {
    return 100;
}

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

    /* temps moyen pour un appel de fonction normal */
    for (i = 0; i < NBITS; i++)
        randomFunc();
    res = gettimeofday(&t2, NULL); assert(res == 0);

    /* DEBUG time if need */
    //printTime(t1);
    //printTime(t2);

    /* DEBUG print infos */
    //fprintf(stdout,"%ld, ok = %d, i=%d\n", toMicroSec(t2)-toMicroSec(t1), i);
    fprintf(stdout, "%ld\n", toMicroSec(t2)-toMicroSec(t1));
}
