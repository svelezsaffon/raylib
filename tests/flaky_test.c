// Intentionally flaky test: fails ~40% of the time based on wall-clock time.
// Used to exercise Bazel's `flaky` test attribute and CI retry/report behavior.
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    // tv_nsec alone has coarse (ms-level) resolution in some sandboxes, so mix
    // in the pid to avoid the roll collapsing to a constant value.
    unsigned long roll = ((unsigned long)ts.tv_nsec + (unsigned long)getpid()) % 10;

    printf("flaky_test: roll=%lu\n", roll);

    if (roll < 4)
    {
        fprintf(stderr, "flaky_test: unlucky roll, failing this run\n");
        return 1;
    }

    printf("flaky_test: passed\n");
    return 0;
}
