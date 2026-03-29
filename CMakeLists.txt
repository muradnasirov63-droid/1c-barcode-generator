cmake_minimum_required(VERSION 3.15)
project(BarcodeGen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем библиотеку ZXing
include(FetchContent)
FetchContent_Declare(
  zxing-cpp
  GIT_REPOSITORY https://github.com/zxing-cpp/zxing-cpp.git
  GIT_TAG v2.2.1
)
FetchContent_MakeAvailable(zxing-cpp)

add_executable(test_datamatrix
    "datamatrix_encoder.cpp"
    "datamatrix_encoder.h"
    "test_datamatrix_encoder.cpp"
    "SvgRenderer.cpp"
    "SvgRenderer.h"
)

target_link_libraries(test_datamatrix PRIVATE ZXing::ZXing)

target_include_directories(test_datamatrix PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})