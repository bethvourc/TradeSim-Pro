
### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(trading_simulation)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(trading_simulation src/main.cpp src/trading_algorithms.cpp src/market_data.cpp)

# Link libraries
find_package(CURL REQUIRED)
find_package(JsonCpp REQUIRED)

target_link_libraries(trading_simulation curl jsoncpp)
