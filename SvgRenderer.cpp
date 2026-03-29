#include "SvgRenderer.h"
#include <sstream>

std::string SvgRenderer::render(const ZXing::BitMatrix& matrix) {
    std::stringstream ss;
    int width = matrix.width();
    int height = matrix.height();

    // Та самая "шапка", о которой ты спрашивал
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    ss << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\" viewBox=\"0 0 "
        << width << " " << height << "\">\n";
    ss << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n";
    ss << "<path d=\"";

    // Твой цикл переместился сюда
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (matrix.get(x, y)) {
                ss << "M" << x << "," << y << "h1v1h-1z ";
            }
        }
    }

    ss << "\" fill=\"black\"/>\n</svg>";
    return ss.str(); // Возвращаем одну большую строку с кодом картинки
}