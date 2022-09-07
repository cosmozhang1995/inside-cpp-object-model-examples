#include <stdio.h>
#include "print_data.h"

class A {
public:
    A() : a_i8(1), a_i32(2) {}
    char a_i8;
    int a_i32;
};

class B : virtual public A {
public:
    B() : b_i64(3) {}
    long long b_i64;
};

class C : virtual public A {
public:
    C() : c_i64(4) {}
    long long c_i64;
};

class D: public B, public C {
public:
    D() : d_i32(5) {}
    int d_i32;
};

int main(int argc, char *argv[])
{
    printf("sizeof(A) = %lu\n", sizeof(A));
    printf("sizeof(B) = %lu\n", sizeof(B));
    printf("sizeof(C) = %lu\n", sizeof(C));
    printf("sizeof(D) = %lu\n", sizeof(D));
    {
        printf("construct C:\n");
        C *c = new C();
        A *a = dynamic_cast<A*>(c);
        printf("a = %p\n", a);
        printf("c = %p\n", c);
        print_data(c);
        void **c_vptr = *reinterpret_cast<void***>(c);
        printf("c->_vptr_C     = %p\n", c_vptr);
        // printf("c->_vptr_C[0]  = %p\n", *c_vptr);
        printf("c->_vptr_C[-3] = %p\n", *(c_vptr - 3));
    }
    {
        printf("construct D:\n");
        D *d = new D();
        C *c = dynamic_cast<C*>(d);
        B *b = dynamic_cast<B*>(d);
        A *a = dynamic_cast<A*>(d);
        printf("a = %p\n", a);
        printf("b = %p\n", b);
        printf("c = %p\n", c);
        printf("d = %p\n", d);
        print_data(d);
        void **c_vptr = *reinterpret_cast<void***>(c);
        printf("c->_vptr_C     = %p\n", c_vptr);
        printf("c->_vptr_C[-3] = %p\n", *(c_vptr - 3));
        void **d_vptr = *reinterpret_cast<void***>(d);
        printf("d->_vptr_D     = %p\n", d_vptr);
        printf("d->_vptr_D[-3] = %p\n", *(d_vptr - 3));
    }

    return 0;
}