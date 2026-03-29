#pragma once
#include <string>
#include "BitMatrix.h"

class SvgRenderer {
public:
    // Этот метод берет матрицу и возвращает готовую строку со всеми тегами SVG
    static std::string render(const ZXing::BitMatrix& matrix);
};