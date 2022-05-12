#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <sys/time.h>

#define NBITS 1000000
/* On bloque à 40 car après on a un overflow des int (i=44 pour être précis) */
#define NBITS2 40

// Conversion en micro seconde
long toMicroSec (struct timeval t) {
    return t.tv_sec * 1000000 + t.tv_usec;
}

void printTime(struct timeval t){
    fprintf(stdout, "%d s %d us\n", t.tv_sec, t.tv_usec);
    fprintf(stdout, "%ld s %ld us\n", t.tv_sec, t.tv_usec);

    return;
}

void fibo(void){
    int i,n;
    int n1,n2, next;

    n = NBITS2;
    next = 0;
    n1 = n2 = 1;

    for (i=0; i<n; i++)
    {
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
}

int main(void)
{
    struct timeval t1, t2;
    int i, res;

    res = gettimeofday(&t1, NULL);  assert(res == 0);
    /* Temps moyen pour un syscall (ici close()) */
    for (i = 0; i < NBITS; i++)
        fibo();
    res = gettimeofday(&t2, NULL); assert(res == 0);
    
    fprintf(stdout, "%ld\n", toMicroSec(t2)-toMicroSec(t1));
}