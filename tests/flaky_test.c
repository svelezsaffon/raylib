// Deterministic test: always passes.
// Previously was intentionally flaky to exercise Bazel's `flaky` test attribute.
#include <stdio.h>

int main(void)
{
    printf("flaky_test: passed\n");
    return 0;
}
