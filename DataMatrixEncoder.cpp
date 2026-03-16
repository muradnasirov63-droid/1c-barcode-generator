#include "DataMatrixEncoder.h"
#include "MultiFormatWriter.h"
#include "BarcodeFormat.h"
#include "BitMatrix.h"

ZXing::BitMatrix DataMatrixEncoder::encode(const std::wstring& text, int width, int height) {

    ZXing::MultiFormatWriter writer(ZXing::BarcodeFormat::DataMatrix);
    return writer.encode(text, width, height);
}