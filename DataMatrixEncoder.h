#pragma once
#include <string>
#include <vector>

namespace ZXing {
    class BitMatrix;
}

class DataMatrixEncoder {
public:
    ZXing::BitMatrix encode(const std::wstring& text, int width, int height);
};