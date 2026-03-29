cmake_minimum_required(VERSION 3.15)
project(BarcodeGen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  zxing-cpp
  GIT_REPOSITORY https://github.com/zxing-cpp/zxing-cpp.git
  GIT_TAG v2.2.1
)
FetchContent_MakeAvailable(zxing-cpp)

add_executable(BarcodeGen
    "Barcode(new).cpp"
    "DataMatrixEncoder.cpp"
    "DataMatrixEncoder.h"
)

target_link_libraries(BarcodeGen PRIVATE ZXing::ZXing)
target_include_directories(BarcodeGen PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})