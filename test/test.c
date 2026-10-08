#include "test.h"

void run_returnif1(int* x) {
    returnif(*x > 4);
    *x = 0;
}

void test_returnif1() {
    {
        int x = 5;
        (void)run_returnif1(&x);
        assert(x == 5);
    }
    {
        int x = 4;
        (void)run_returnif1(&x);
        assert(x == 0);
    }
}

int run_returnif2() {
    returnif(2 > 5, 1);
    returnif(5 > 2, 4);
    return 3;
}

void test_returnif2() {
    assert(run_returnif2() == 4);
}

int run_continueif() {
    for (int i = 0; i < 10; i++) {
        continueif(i < 5);
        return i;
    }
    return 0;
}

void test_continueif() {
    assert(run_continueif() == 5);
}

int run_breakif() {
    int i;
    for (i = 0; i < 10; i++) {
        breakif(i > 4);
    }
    return i;
}

void test_breakif() {
    assert(run_continueif() == 5);
}

int main(void) {
    (void)test_returnif1();
    (void)test_returnif2();
    (void)test_continueif();
    (void)test_breakif();
    fprintf(stdout, "All tests passed\n");
}
