#include <vector>
#include <complex>

// Use 'extern "C"' to prevent C++ name mangling, making it easier for JS to call.
extern "C" {

// EMSCRIPTEN_KEEPALIVE ensures the function isn't removed by the compiler
// if it seems unused from a C++ perspective.
__attribute__((used))
int* generateMandelbrot(int width, int height, int max_iterations, double x_min, double x_max, double y_min, double y_max) {
    // We need to allocate memory that lives on after this function returns.
    // The JavaScript caller will be responsible for freeing this memory.
    // The buffer will store R, G, B, A values for each pixel.
    int* buffer = new int[width * height * 4];

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Map the pixel (x, y) to a complex number 'c'
            double real = x_min + (static_cast<double>(x) / (width - 1)) * (x_max - x_min);
            double imag = y_min + (static_cast<double>(y) / (height - 1)) * (y_max - y_min);
            std::complex<double> c(real, imag);

            // --- Mandelbrot Iteration Logic (same as before) ---
            std::complex<double> z = 0;
            int iterations = 0;
            while (std::abs(z) <= 2.0 && iterations < max_iterations) {
                z = z * z + c;
                iterations++;
            }

            // --- Color the Pixel ---
            int r = 0, g = 0, b = 0;
            if (iterations < max_iterations) {
                // Point is outside the set, give it a color
                r = (iterations % 256);
                g = (iterations * 2 % 256);
                b = (iterations * 5 % 256);
            }
            
            // --- Store RGBA values in the buffer ---
            int index = (y * width + x) * 4;
            buffer[index] = r;         // Red
            buffer[index + 1] = g;     // Green
            buffer[index + 2] = b;     // Blue
            buffer[index + 3] = 255;   // Alpha (fully opaque)
        }
    }

    // Return the pointer to the start of the buffer.
    return buffer;
}

} // extern "C"