#include <iostream>
#include <fstream>
#include "DataMatrixEncoder.h"
#include "BitMatrix.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        DataMatrixEncoder myEncoder;
        auto matrix = myEncoder.encode(L"MURAD_PROFESSIONAL", 200, 200);
        ofstream out("final_modular_dm.pbm");
        if (out) {
            out << "P1\n" << matrix.width() << " " << matrix.height() << "\n";
            for (int y = 0; y < matrix.height(); ++y) {
                for (int x = 0; x < matrix.width(); ++x) {
                    out << (matrix.get(x, y) ? "1 " : "0 ");
                }
                out << "\n";
            }
            cout << "ВСЁ ГОТОВО! Файл 'final_modular_dm.pbm' создан." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "Нажми Enter...";
    cin.get();
    return 0;
}