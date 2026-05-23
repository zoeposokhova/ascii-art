//
// Created by zoe on 5/23/26.
//

#ifndef ASCII_ART_IMAGE_H
#define ASCII_ART_IMAGE_H

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>


#pragma pack(push, 1)

struct file {
    uint16_t fileType{0x4D42};
    uint32_t fileSize{0};
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offset_data{0}; //start pos of pixel data
};

struct info {
    uint32_t size{0};
    int32_t width{0};
    int32_t height{0};

    uint16_t planes{1};
    uint16_t bitCount{0}; //bits per pixel
    uint32_t compression{0};

    uint32_t imageSize{0};
    int32_t xPixel{0};
    int32_t yPixel{0};

    uint32_t colorsUsed{0};
    uint32_t colorsNeeded{0};
};

#pragma pack(pop)

struct BMP {
    file fileHeader;
    info infoHeader;
    std::vector<uint8_t> data;

    BMP(const std::string& fileName) {
        read(fileName);
    }

    void read(const std::string& filename);
};

#endif //ASCII_ART_IMAGE_H