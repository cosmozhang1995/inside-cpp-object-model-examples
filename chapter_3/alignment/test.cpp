#include <stdio.h>

#define DEFINE_INT_BITS(__native_type, __bits)    \
typedef __native_type int##__bits##_t;            \
typedef unsigned __native_type uint##__bits##_t;

DEFINE_INT_BITS(char, 8)
DEFINE_INT_BITS(short, 16)
DEFINE_INT_BITS(int, 32)
DEFINE_INT_BITS(long long, 64)

template<size_t nbytes>
class Bytes {
    char data[nbytes];
};

template<size_t nbytes>
class Bytes1 {
    short b1;
    char data[nbytes];
};

template<>
class Bytes<0> {
};

template<typename T1, typename T2>
class Duplet {
public:
    Duplet();
private:
    T1 e1;
    T2 e2;
};

template<typename T1, typename T2>
Duplet<T1, T2>::Duplet() : e1(1), e2(2) {}

template<typename T1, typename T2, typename T3>
class Triplet {
public:
    Triplet();
private:
    T1 e1;
    T2 e2;
    T3 e3;
};

template<typename T1, typename T2, typename T3>
Triplet<T1, T2, T3>::Triplet() : e1(1), e2(2), e3(3) {}

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

#define TEST_CLASS(...) \
    printf("sizeof " #__VA_ARGS__ " = %lu\n", sizeof(__VA_ARGS__));

#define TEST_BYTES(nbytes) \
    TEST_CLASS(Bytes<nbytes>);

#define PRINT_CLASS(...) {                        \
        typedef __VA_ARGS__ __class;              \
        __class *ptr = new __class();             \
        printf("layout of " #__VA_ARGS__ ":\n");  \
        print_data(ptr);                          \
        delete ptr;                               \
    }

    TEST_CLASS(Duplet<int8_t, int8_t>);
    TEST_CLASS(Duplet<int16_t, int8_t>);
    TEST_CLASS(Duplet<int32_t, int8_t>);
    PRINT_CLASS(Duplet<int32_t, int8_t>);
    TEST_CLASS(Duplet<int8_t, int32_t>);
    PRINT_CLASS(Duplet<int8_t, int32_t>);
    TEST_CLASS(Duplet<int64_t, int8_t>);
    TEST_CLASS(Triplet<int8_t, int16_t, int32_t>);
    PRINT_CLASS(Triplet<int8_t, int16_t, int32_t>);
    TEST_CLASS(Triplet<int32_t, int16_t, int8_t>);
    PRINT_CLASS(Triplet<int32_t, int16_t, int8_t>);
    TEST_CLASS(Triplet<int8_t, int32_t, int16_t>);
    PRINT_CLASS(Triplet<int8_t, int32_t, int16_t>);
    TEST_BYTES(0);
    TEST_BYTES(1);
    TEST_BYTES(2);
    TEST_BYTES(3);
    TEST_BYTES(4);
    TEST_BYTES(5);
    TEST_BYTES(6);
    TEST_BYTES(7);
    TEST_BYTES(8);
    TEST_BYTES(9);
    TEST_BYTES(10);
    TEST_BYTES(11);
    TEST_BYTES(12);
    TEST_BYTES(13);
    TEST_BYTES(14);
    TEST_BYTES(15);
    TEST_BYTES(16);
    TEST_BYTES(17);
    TEST_BYTES(18);
    TEST_BYTES(19);
    TEST_BYTES(20);
    TEST_BYTES(21);
    TEST_BYTES(22);
    TEST_BYTES(23);
    TEST_BYTES(24);
    TEST_BYTES(25);
    TEST_BYTES(26);
    TEST_BYTES(27);
    TEST_BYTES(28);
    TEST_BYTES(29);
    TEST_BYTES(30);
    TEST_BYTES(31);
    TEST_BYTES(32);
}