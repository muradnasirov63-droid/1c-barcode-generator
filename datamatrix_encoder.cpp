#include "datamatrix_encoder.h"
#include "BarcodeFormat.h"  // Добавь это, если не находит формат
#include "MultiFormatWriter.h" // Самый надежный способ в новых версиях ZXing
#include <stdexcept>

ZXing::BitMatrix DataMatrixEncoder::encode(const std::wstring& text, int width, int height) {
    try {
        ZXing::MultiFormatWriter writer(ZXing::BarcodeFormat::DataMatrix);

        return writer.encode(text, width, height);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error DataMatrix: " + std::string(e.what()));
    }
}