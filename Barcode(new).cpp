#include <iostream>
#include <fstream>
#include "DataMatrixEncoder.h"
#include "SvgRenderer.h" // Подключаем наш новый инструмент

int main() {
    try {
        setlocale(LC_ALL, "RU");
        DataMatrixEncoder myEncoder;

        // получаем матрицу
        auto matrix = myEncoder.encode(L"THIS IS KIMPINTYO", 200, 200);

        // превращаем матрицу в SVG-строку
        std::string svgCode = SvgRenderer::render(matrix);

        // записываем результат в файл
        std::ofstream out("final_barcode.svg");
        if (out) {
            out << svgCode;
            std::cout << "УСПЕХ! Файл создан." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка братиш: " << e.what() << std::endl;
    }

    std::cout << "Нажми Enter...";
    std::cin.get();
    return 0;
}