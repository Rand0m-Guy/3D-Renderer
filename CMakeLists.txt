cmake_minimum_required(VERSION 3.16)
project(3DRenderer)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(sdl3/vendored/SDL EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(${PROJECT_NAME} main.cpp ui/sdl_window.h ui/sdl_window.cpp core/renderer/renderer.h core/renderer/renderer.cpp core/matrix/matrix2d.h core/matrix/matrix2d.cpp core/matrix/matrix2di.h core/matrix/matrix2di.cpp core/vector/vector2.h core/vector/vector2i.h core/vector/vector3.h core/vector/vector3i.h core/vector/vector4.h core/vector/vector4i.h core/color/color.h core/color/color.cpp core/primitives/point/point.h core/primitives/point/point.cpp core/projection/projection.h core/projection/perspective.h core/projection/perspective.cpp)

# Link to the actual SDL3 library.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)