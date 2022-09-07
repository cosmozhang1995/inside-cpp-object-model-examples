#include <stdio.h>
#include "print_data.h"

class A {
public:
        A() : _a(1) {}
        int _a;
#ifdef WITH_VIRTUAL_FUNCTION_A
        virtual int a();
#endif
};

#ifdef WITH_VIRTUAL_FUNCTION_A
int A::a() { return _a; }
#endif

class B {
public:
        B() : _b(2) {}
        int _b;
#ifdef WITH_VIRTUAL_FUNCTION_B
        virtual int b();
#endif
};

#ifdef WITH_VIRTUAL_FUNCTION_B
int B::b() { return _b; }
#endif

class C : public A, public B {
public:
        C() : _c(3) {}
        int _c;
};



int main(int argc, char *argv[])
{
        printf("sizeof(A) = %lu\n", sizeof(A));
        printf("sizeof(B) = %lu\n", sizeof(B));
        printf("sizeof(C) = %lu\n", sizeof(C));
        C *c = new C();
        A *a = static_cast<A*>(c);
        B *b = static_cast<B*>(c);
        printf("a = %p\n", a);
        printf("b = %p\n", b);
        printf("c = %p\n", c);
        print_data(c);
        //printf("a.a = %p\n", &A::a);
        //printf("b.b = %p\n", &B::b);
        B *bb = new B();
        printf("bb = %p\n", bb);
        print_data(bb);
        *b = *bb;
        printf("new b = \n");
        print_data(b);
        return 0;
}