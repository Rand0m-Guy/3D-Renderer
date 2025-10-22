# Didactic 3D Renderer

This 3D Renderer is designed for academic use, to show different perspective models, lighting solutions, and other aspects of 3D Rendering. This solution is completely custom so it can be modified for different usecases and levels of teaching.

## Installation

### Dependencies
The project uses CMake to compile/build. It also uses SDL3, but it's bundled within the project (keep this in mind if you plan to move the SDL3 folder's location).

Once downloaded (either via ZIP file or cloning), the project must be compiled and built. We strongly recommend not compiling/building in the same directory, but rather adding a build/ folder.

### Compiling
To compile (assuming you are in `${PATH_TO_PROJECT}/build/`):
```
cmake ..
```
### Building
To build the project (assuming you are in `${PATH_TO_PROJECT}/build/`):
```
cmake --build .
```

## Running
Once installed, it can be run executing the `3DRenderer` executable.
