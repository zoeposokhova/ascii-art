//
// Created by zoe on 5/22/26.
//
#include <iostream>
#include "../include/image.h"

int main() {

    std::string palette = " .:-=+*#%@"; // 10
    //std::string palette = " .:-=+*#%@O0MW$"; // 15
    //std::string palette = " .:-=+*#%@O0QC7zI8MW$"; // 20
    //std::string palette = " .-^ ,:;Il!i>~+_-?][}{1)(|/cxYUJCLQ0Omwqpdbk*#MW&8%B@$"; // 50

    BMP image("media/input.bmp");;

    int terminalHeight = 60;
    int boxHeight = image.infoHeader.height / terminalHeight;
    if (boxHeight < 2) boxHeight = 2;
    int boxWidth = boxHeight / 2;

    for (int y = image.infoHeader.height - boxHeight; y >= 0; y -= boxHeight) {
        for (int x = 0; x < image.infoHeader.width; x += boxWidth) {
            long long R = 0, G = 0, B = 0, cnt = 0;
            for (int by = 0; by < boxHeight && (y+by) < image.infoHeader.height; ++by) {
                for (int bx = 0; bx < boxWidth && (x+bx) < image.infoHeader.width; ++bx) {
                    int X = x + bx;
                    int Y = y + by;
                    int pixel = (X + Y*image.infoHeader.width) * (image.infoHeader.bitCount / 8);

                    B += image.data[pixel];
                    G += image.data[pixel+1];
                    R += image.data[pixel+2];
                    ++cnt;
                }
            }

            uint8_t avgR = R / cnt;
            uint8_t avgG = G / cnt;
            uint8_t avgB = B / cnt;

            int brightness = static_cast<int>(0.2126 * avgR + 0.7152 * avgG + 0.0722 * avgB);
            int paletteIndex = (brightness * (palette.size() - 1)) / 255;

            std::cout << palette[paletteIndex];
        }
        std::cout << std::endl;
    }

    return 0;
}