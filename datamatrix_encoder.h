#pragma once
#include <string>
#include "BitMatrix.h" // Убедись, что этот файл есть в проекте (от ZXing)

class DataMatrixEncoder {
public:
    // Мы используем static, чтобы можно было вызывать метод без создания объекта класса
    static ZXing::BitMatrix encode(const std::wstring& text, int width, int height);
};