#include <stdio.h>
#include "print_data.h"

class A {
public:
    A() : a_i8(1), a_i32(2) {}
    char a_i8;
    int a_i32;
};

class B : public A {
public:
    B() : b_i8(1) {}
    char b_i8;
};

int main(int argc, char *argv[])
{
    B *b = new B();
    A *a = dynamic_cast<A*>(b);
    printf("sizeof(A) = %lu\n", sizeof(A));
    printf("sizeof(B) = %lu\n", sizeof(B));
    printf("a = %p\n", a);
    printf("b = %p\n", b);
    print_data(b);
    return 0;
}