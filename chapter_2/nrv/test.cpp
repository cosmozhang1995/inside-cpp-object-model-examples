#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>

typedef long long usec_t;

inline usec_t get_time() {
        struct timeval tv;
        gettimeofday(&tv, nullptr);
        return static_cast<usec_t>(tv.tv_sec) * 1000 * 1000 + static_cast<usec_t>(tv.tv_usec);
}

class Test {
public:
        static int copy_count;
        Test() {}
#ifdef ENABLE_COPY_CONSTRUCTOR
        Test(const Test &o) {
                copy_count++;
                memcpy(_v, o._v, 1000 * sizeof(double));
        }
#endif
        double _v[1000];
};

int Test::copy_count = 0;

Test make_test(int i) {
        Test t;
        t._v[0] = i;
        t._v[999] = i;
        return t;
}

void test() {
        for (int i = 0; i < ITERATIONS; i++) {
                Test t = make_test(i);
        }
}

int main(int argc, char *argv[])
{
        usec_t ts = get_time();
        test();
        usec_t te = get_time();
        printf("copy_count: %d.  time usage: %lld usecs\n", Test::copy_count, te - ts);
        return 0;
}