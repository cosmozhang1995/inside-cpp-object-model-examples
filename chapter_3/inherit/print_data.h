#pragma once

template<typename T>
inline void print_data(T *obj) {
    size_t sz = sizeof(T) / sizeof(int);
    int *ptr = reinterpret_cast<int *>(obj);
    for (size_t i = 0; i < sz; i++) {
        // printf("\t%02x: 0x%08x\n", static_cast<int>(i * sizeof(int)), ptr[i]);
        unsigned char *ptri = reinterpret_cast<unsigned char*>(ptr + i);
        printf("\t%02x: %02x %02x %02x %02x\n",
            static_cast<int>(i * sizeof(int)),
            static_cast<int>(ptri[0]),
            static_cast<int>(ptri[1]),
            static_cast<int>(ptri[2]),
            static_cast<int>(ptri[3]));
    }
}