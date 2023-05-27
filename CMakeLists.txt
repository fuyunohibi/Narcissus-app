cmake_minimum_required(VERSION 3.0)
project(Narcissus-app)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add your source files here
set(SOURCES
    App.cpp
    # Add more source files if needed
)

# Add your header files here
set(HEADERS
    # Add header files if needed
)

# Add the include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create an executable from your source files
add_executable(NarcissusApp ${SOURCES} ${HEADERS})

# Link against the curl library
target_link_libraries(NarcissusApp curl)
