#include <iostream>
#include <fstream>
#include <vector>
#include <complex>

// Function to compute the Mandelbrot iterations for a given complex number
int getMandelbrotIterations(const std::complex<double>& c, int max_iterations) {
    std::complex<double> z = 0;
    int iterations = 0;
    while (std::abs(z) <= 2.0 && iterations < max_iterations) {
        z = z * z + c;
        iterations++;
    }
    return iterations;
}

int main() {
    // --- Image and Mandelbrot Parameters ---
    const int width = 800;
    const int height = 600;
    const int max_iterations = 1000;

    // The region of the complex plane to render
    const double x_min = -2.0;
    const double x_max = 1.0;
    const double y_min = -1.0;
    const double y_max = 1.0;

    // Create a file to save the image
    std::ofstream my_image("mandelbrot.ppm");

    // --- PPM Header ---
    // P3 means this is an ASCII-based color image
    // Then width and height
    // 255 is the maximum value for a color component
    my_image << "P3\n" << width << " " << height << "\n255\n";

    // --- Generate Pixel Data ---
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Map the pixel (x, y) to a complex number 'c'
            double real = x_min + (static_cast<double>(x) / (width - 1)) * (x_max - x_min);
            double imag = y_min + (static_cast<double>(y) / (height - 1)) * (y_max - y_min);
            std::complex<double> c(real, imag);

            // Get the number of iterations
            int iterations = getMandelbrotIterations(c, max_iterations);

            // --- Color the Pixel ---
            if (iterations == max_iterations) {
                // Point is likely in the set -> color it black
                my_image << "0 0 0 ";
            } else {
                // Point is outside the set -> give it a color based on how quickly it escaped
                int r = (iterations % 256);
                int g = (iterations * 2 % 256);
                int b = (iterations * 5 % 256);
                my_image << r << " " << g << " " << b << " ";
            }
        }
        my_image << "\n"; // Newline for each row of pixels
    }

    my_image.close();
    std::cout << "Successfully generated mandelbrot.ppm" << std::endl;

    return 0;
}