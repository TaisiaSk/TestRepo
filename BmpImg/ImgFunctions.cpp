#include "ImgFunctions.h"
#include <fstream>
#include <exception>
#include <iostream>

int get_offset(int width)
{
    int offset = 0;
    if (width % 4)
        offset = 4 - (3 * width) % 4;
    return offset;
}

RgbImg read_rgb_img(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    const int offset = get_offset(bmih.biWidth);

    RgbImg img;
    img.height = bmih.biHeight;
    img.width = bmih.biWidth;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
            bmp_in.read((char*)&img.pixels[row][col], 3);
        bmp_in.seekg(offset, std::ios::cur);
    }

    bmp_in.close();
    return img;
}

void write_rgb_img(char const filename[], RgbImg const& img)
{
    std::ofstream bmp_out(filename, std::ios::binary);
    if (!bmp_out.is_open())
        throw std::runtime_error("Failed to open output file");

    const int offset = get_offset(img.width);

    BITMAPFILEHEADER bmfh;
    char bfType[] = { 'B', 'M' };
    bmfh.bfType = *((WORD*)bfType); // ('M' << 8) | 'B';
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + img.height * img.width * 3;
    bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

    BITMAPINFOHEADER bmih;
    bmih.biClrImportant = bmih.biClrUsed = bmih.biCompression = 0;
    bmih.biPlanes = bmih.biXPelsPerMeter = bmih.biYPelsPerMeter = 1;
    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biSizeImage = bmfh.bfSize - bmfh.bfOffBits;
    bmih.biHeight = img.height;
    bmih.biWidth = img.width;
    bmih.biBitCount = 24;

    bmp_out.write((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_out.write((char*)&bmih, sizeof(BITMAPINFOHEADER));

    BYTE* offset_array = new BYTE[offset];
    for (int i = 0; i < offset; ++i)
        offset_array[i] = 0;

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            bmp_out.write((char*)&img.pixels[row][col], 3);
        bmp_out.write((char*)offset_array, offset);
    }

    delete[] offset_array;
    bmp_out.close();
}

void print_rgb_img_info(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    std::cout << bmfh.bfSize << std::endl;
    std::cout << bmfh.bfOffBits << std::endl;

    std::cout << bmih.biSize << std::endl;
    std::cout << bmih.biHeight << std::endl;
    std::cout << bmih.biWidth << std::endl;
    std::cout << bmih.biSizeImage << std::endl;

    bmp_in.close();
}

RgbImg black_white(RgbImg const& img)
{
    RgbImg img_dop;
    img_dop.height = img.height;
    img_dop.width = img.width;
    img_dop.pixels = new RGB * [img_dop.height];
    for (size_t row = 0; row < img_dop.height; ++row)
        img_dop.pixels[row] = new RGB[img_dop.width];

    BYTE sum;
    for (int i = 0; i < img.height; ++i)
        for (int j = 0; j < img.width; ++j) {
            sum = (img.pixels[i][j].Blue + img.pixels[i][j].Green + img.pixels[i][j].Red)/3;
            img_dop.pixels[i][j] = { sum,sum,sum };
        }
    return img_dop;
}

RgbImg blur(RgbImg const& img, const int arg)
{
    RgbImg img_dop;
    img_dop.height = img.height;
    img_dop.width = img.width;
    img_dop.pixels = new RGB* [img_dop.height];
    for (size_t row = 0; row < img_dop.height; ++row)
        img_dop.pixels[row] = new RGB[img_dop.width];

    int sum_r=0;
    int sum_g = 0;
    int sum_b=0;
    int count = 0;
    for(int i=0;i<img.height;++i)
        for (int j = 0; j < img.width; ++j)
        {
           
            for (int k = i - arg; k <= i + arg; ++k)
            {
                if (k >= (int)img.height)
                    break;
                for (int l = j - arg; l <= j + arg; ++l)
                {
                    if (l >= (int)img.width)
                        break;
                    if ((k == i) && (l == j))
                        continue;
                    if (k < 0 || l < 0)
                        continue;
                    sum_r += img.pixels[k][l].Red;
                    sum_g += img.pixels[k][l].Green;
                    sum_b += img.pixels[k][l].Blue;
                    ++count;
                }
            }
            img_dop.pixels[i][j] = { (BYTE)(sum_r / count) , (BYTE)(sum_g / count) , (BYTE)(sum_b / count) };
            sum_r = 0;
            sum_g = 0;
            sum_b = 0;
            count = 0;
        }
    return img_dop;
}