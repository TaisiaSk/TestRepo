#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"

int main()
{
	try
	{
		RgbImg img = read_rgb_img("kidsnoise.bmp");
	
		/*for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				img.pixels[i][j] = { 0, 0, 0 };*/
		
		write_rgb_img("out_bw.bmp", black_white(img));

		write_rgb_img("out_blur1.bmp", blur(img, 1));
		write_rgb_img("out_blur5.bmp", blur(img, 5));
		write_rgb_img("out_blur10.bmp", blur(img, 10));

		for (int i = 0; i < img.height; ++i)
			delete[] img.pixels[i];
		delete[] img.pixels;
	}
	catch (std::exception error)
	{
		std::cout << "Error happened: " << error.what() << '\n';
		return 1;
	}
	std::cout << "Success!\n";
	return 0;
}