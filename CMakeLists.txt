cmake_minimum_required(VERSION 3.0)
project(practis-cpp VERSION 0.1.0 LANGUAGES C CXX)

# Find wxWidgets
find_package(wxWidgets REQUIRED)

include_directories(includes/wxWidgets-3.2.2.1/include)

# Include the wxWidgets headers
include(${wxWidgets_USE_FILE})

# Add your source files to the project
add_executable(practis-cpp main.cpp)

# Link against the wxWidgets library
target_link_libraries(practis-cpp ${wxWidgets_LIBRARIES})

add_executable(practis-cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
