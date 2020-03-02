#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

struct xorshift64_state
{
    uint64_t a;
};

typedef struct xorshift64_state State;

uint64_t xorshift64(struct xorshift64_state *state)
{
    uint64_t x = state->a;
    x ^= x << 12;
    x ^= x >> 25;
    x ^= x << 27;
    return state->a = x * UINT64_C(0x2545F4914F6CDD1D);
}

int main(void)
{

    time_t rawtime;
    struct tm *info;

    time(&rawtime);

    info = localtime(&rawtime);
    State m;
    m.a = info->tm_sec;

    sleep(1);
    for (int i = 0; i < 10; ++i)
    {
        printf(" %llu\n", xorshift64(&m));
    }

    return 0;
}