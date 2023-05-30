#include "hw2_test.h"
#include <stdio.h>

int set_weight(int weight) {
    long r = syscall(334, weight);
    return r;
}

int get_weight() {
    printf("get_weight\n");
    long r = syscall(335);
    printf("get_weight: %ld\n", r);
    return r;
}

int get_ancestor_sum() {
	long r = syscall(336);
    return r;
}

pid_t get_heaviest_descendant() {
	long r = syscall(337);
    return r;
}
