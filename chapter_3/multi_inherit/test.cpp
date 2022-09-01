#include <stdio.h>

class A {
public:
        A() : _a(1) {}
        int _a;
#ifdef WITH_VIRTUAL_FUNCTIONS
        virtual int a();
#endif
};

#ifdef WITH_VIRTUAL_FUNCTIONS
int A::a() { return _a; }
#endif

class B {
public:
        B() : _b(2) {}
        int _b;
#ifdef WITH_VIRTUAL_FUNCTIONS
        virtual int b();
#endif
};

#ifdef WITH_VIRTUAL_FUNCTIONS
int B::b() { return _b; }
#endif

class C : public A, public B {
public:
        C() : _c(3) {}
        int _c;
};

template<typename T>
inline void print_data(T *obj) {
    size_t sz = sizeof(T) / sizeof(int);
    int *ptr = reinterpret_cast<int *>(obj);
    for (size_t i = 0; i < sz; i++) {
        printf("\t%02x: 0x%08x\n", static_cast<int>(i * sizeof(int)), ptr[i]);
    }
}

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