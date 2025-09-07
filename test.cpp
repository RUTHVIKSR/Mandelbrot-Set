#include <emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int test_function() {
        return 42;
    }
    
    EMSCRIPTEN_KEEPALIVE
    unsigned char* simple_test(int size) {
        unsigned char* buffer = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            buffer[i] = (unsigned char)(i % 256);
        }
        return buffer;
    }
}
