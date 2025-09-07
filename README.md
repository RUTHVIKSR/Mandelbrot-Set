# C++ Mandelbrot Set Web Viewer

This project is a web-based application that renders the Mandelbrot set with an interactive zoom feature. The high-performance fractal generation logic is written in C++ and compiled to WebAssembly to run efficiently in the browser.

## Tech Stack

* **C++:** For the core Mandelbrot set computation.
* **WebAssembly (Wasm):** To run the C++ code in the web browser.
* **Emscripten:** The toolchain used to compile C++ to Wasm.
* **HTML:** For the basic structure of the web page.
* **JavaScript:** To control the HTML canvas, handle user input (zooming), and communicate with the Wasm module.

## Project Checkpoints

- [X] **Checkpoint 1: Core Mandelbrot Logic in C++.**
- [X] **Checkpoint 2: Compiling C++ to WebAssembly.**
- [X] **Checkpoint 3: Rendering the Set on a Web Page.**
- [X] **Checkpoint 4: Implementing Interactive Zoom.**