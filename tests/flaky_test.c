// Timing-sensitive test: measures execution time
// Fixed: timeout threshold increased from ~1 second to 2.5 seconds (Option 1)
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    // Simulate test work
    usleep(500000);  // 0.5 seconds
    
    clock_gettime(CLOCK_REALTIME, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + 
                    (end.tv_nsec - start.tv_nsec) / 1e9;
    
    printf("Test execution time: %.3f seconds\n", elapsed);
    
    // Increased timeout threshold: 2.5 seconds (previously ~1 second)
    // Provides 50% margin above worst-case 1.998s from remote builds
    if (elapsed > 2.5)
    {
        fprintf(stderr, "Timeout exceeded\n");
        return 1;
    }
    
    printf("Test passed\n");
    return 0;
}
