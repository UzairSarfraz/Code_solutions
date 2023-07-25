//3rd Method: Memoization

#include <stdio.h>

int piecewise_memoization(int n, int memo[]) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = piecewise_memoization(n - 3, memo) + piecewise_memoization(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10;
    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    int result = piecewise_memoization(n, memo);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
