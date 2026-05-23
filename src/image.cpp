//
// Created by zoe on 5/23/26.
//

#include "../include/image.h"

void BMP::read(const std::string& fileName) {
    std::ifstream input{fileName, std::ios_base::binary};
    if (!input) {
        throw std::runtime_error("Unable to open file!");
    }
    input.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    if (fileHeader.fileType != 0x4D42) {
        throw std::runtime_error("Unrecognized file format!");
    }
    input.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (infoHeader.bitCount != 24 && infoHeader.bitCount != 32) {
        throw std::runtime_error("This program only supports 24-bit or 32-bit BMP images!");
    }

    input.seekg(fileHeader.offset_data, input.beg);

    if (infoHeader.height < 0) {
        throw std::runtime_error("The program can treat only BMP images with the origin in the bottom left corner!");
    }

    int row_stride = infoHeader.width * (infoHeader.bitCount / 8);
    data.resize(infoHeader.width * infoHeader.height * (infoHeader.bitCount / 8));

    if (row_stride % 4 == 0) {
        input.read(reinterpret_cast<char*>(data.data()), data.size());
    }
    else {
        int new_stride = ((row_stride + 3) / 4) * 4;
        std::vector<uint8_t> padding_row(new_stride - row_stride);

        for (int y = 0; y < infoHeader.height; ++y) {
            input.read(reinterpret_cast<char*>(data.data() + row_stride * y), row_stride);
            input.read(reinterpret_cast<char*>(padding_row.data()), padding_row.size());
        }
    }
}