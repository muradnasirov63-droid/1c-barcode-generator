#include <iostream>
#include <fstream> // Работа с файлами 
#include "DataMatrixEncoder.h" // DataMatrix
#include "BitMatrix.h" // Хранятся нули и единицы шртихкода

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        DataMatrixEncoder myEncoder; // Создаём объект-кодировщик
        auto matrix = myEncoder.encode(L"THIS_IS_KIMPINTYAO", 500, 500); // Превращаем в сетку из точек

        ofstream out("final_barcode.svg"); // Создание файла 
        if (out) {
            out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"; // Это паспорт файла. Формат SVG основан на XML
            out << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\" viewBox=\"0 0 " // Ссылка на словарь правил. Квадрат 400*400
                << matrix.width() << " " << matrix.height() << "\">\n"; // Реальное колиство клеток в шртрихкоде
            out << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n"; // Белый цвет фона заднего вроде
            out << "<path d=\""; // Путь
            for (int y = 0; y < matrix.height(); ++y) { // Выбор строки 
                for (int x = 0; x < matrix.width(); ++x) { // Выбор клетки внутри строки
                    if (matrix.get(x, y)) out << "M" << x << "," << y << "h1v1h-1z "; // Дложна ли быть точка черная
                }
            }
            out << "\" fill=\"black\"/>\n</svg>";
            cout << "УСПЕХ! Файл 'final_barcode.svg' создан." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Ошибка братиш, че делать будешь: " << e.what() << endl;
    }
    cout << "Нажми Enter...";
    cin.get();
    return 0;
}