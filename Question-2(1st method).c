//1st Method: Iterative (Loop-based) Implementation
#include <stdio.h>

int piecewise_iterative(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int fn_minus_3 = 0;
    int fn_minus_2 = 1;
    int fn = 2;

    for (int i = 3; i <= n; i++) {
        fn = fn_minus_3 + fn_minus_2;
        fn_minus_3 = fn_minus_2;
        fn_minus_2 = fn;
    }

    return fn;
}

int main() {
    int n = 10;
    int result = piecewise_iterative(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
