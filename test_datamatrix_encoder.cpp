#include <iostream>
#include "datamatrix_encoder.h"

int main() {
    setlocale(LC_ALL, "RU"); 

    try {
        std::cout << "Запуск проверки модуля DataMatrix..." << std::endl;

        auto matrix = DataMatrixEncoder::encode(L"THIS IS KIMPINTYAO", 20, 20);

        std::cout << "Файл создан." << std::endl;
        std::cout << "Размер: " << matrix.width() << "x" << matrix.height() << std::endl;

        if (matrix.width() > 0) {
            std::cout << "Тест пройден успешно!" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Нажми Enter для выхода...";
    std::cin.get();
    return 0;
}