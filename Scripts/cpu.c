#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NBLINES 9

// Tester si un caractère est un chiffre ou non
int my_isdigit(int c) {
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

// Convertir un string en nombre
int my_atoi(const char *c) {
    int val = 0, sign = 1;
    if (*c == '+' || *c == '-') {
        if (*c == '-')
            sign = -1;
        c ++;
    }
    while (my_isdigit(*c)) {
        val *= 10;
        val += (int) (*c -'0');
        c ++;
    }
    return val * sign;
}

// fgets ou gets ne sont pas supportés par tous les unikernels donc on réécrit la fonction
char* mygets(char* str, size_t len, int fd) {
    size_t cpt;
    for (cpt = 0; cpt < len; ++ cpt) {
        int res;
        if (res = read(fd, str + cpt, 1), res != 1) {
            if (res == 0) {
                if (cpt > 0) {
                    str[cpt] = 0;
                    return str;
                } else {
                    if (cpt == 0)
                        return NULL;
                }
            } else {
                fprintf(stderr, "read error");
                return NULL;
            }
        } else {
            if (str[cpt] == '\n') {
                if (cpt < len - 1)
                    str[cpt + 1] = 0;
                else
                    str[cpt] = 0;

                return str;
            }
        }
    }
    if (cpt < len)
        str[cpt] = 0;

    return str;
}

void swap (int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort (int* arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i ++) {
        for (j = 0; j < n - i - 1; j ++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

size_t my_strlen(const char *s) {
    size_t cpt = 0;
    while(*s != '\0') {
        cpt ++;
        s ++;
    }
    return cpt;
}

int main (void) {
    fprintf(stdout, "Start running cpu test\n");

    int fd = open("file/toto.txt", O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "error opening toto.txt\n");
        exit(1);
    }

    int nb, i = 0, res;
    int nums[NBLINES];
    char line[8];
    while (mygets(line, 7, fd))
        nums[i ++] = my_atoi(line);

    bubble_sort(nums, NBLINES);

    fprintf(stdout, "File numbers sorted:\n");
    for (i = 0; i < NBLINES; i ++)
        fprintf(stdout, "%d\n", nums[i]);

    fprintf(stdout, "End running cpu test\n");
}
