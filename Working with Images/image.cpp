#include <bits/stdc++.h>
#define HEADER_LENGTH 54
#define MAX_DIMENSION 10000
using namespace std;

class Image
{
	ifstream fin;
	int width, height;
	int row_size;

	unsigned char header[HEADER_LENGTH];
	unsigned char *pixels[MAX_DIMENSION];

public:
	~Image(){
		fin.close();
		for(int i=0; i<=height; i++)
			free(pixels[i]);
	}

	void open(const char filename[]);
	void RGB_toGrayScale(const char output_filename[]);
	void negative(const char output_filename[]);
	void histogram();
};

void Image::open(const char filename[])
{
	fin.open(filename, ios::binary);
	fin.read((char *)header, HEADER_LENGTH);

	width = *(int *)&header[18];
	height = *(int *)&header[22];
	row_size = 4*ceil(width*3.0/4); //Size of row has to be a multiple of 4 bytes

	for(int i=0; i<=height; i++)
	{
		//Default BGR
		pixels[i] = (unsigned char *)malloc(MAX_DIMENSION);
		fin.read((char *)pixels[i], row_size);
	}
}

void Image::RGB_toGrayScale(const char output_filename[])
{
	ofstream fout(output_filename, ios::binary);	
	fout.write((char *)header, HEADER_LENGTH);

	for(int i=0; i<=height; i++)
	{
		for(int j=0; j<width*3; j+=3)
		{
			int avg = (int)pixels[i][j] + (int)pixels[i][j+1] + (int)pixels[i][j+2];
			avg/=3;

			pixels[i][j] = avg;
			pixels[i][j+1] = avg;
			pixels[i][j+2] = avg;
		}
		fout.write((char *)pixels[i], row_size);
	}
	fout.close();
}

void Image::negative(const char output_filename[])
{
	ofstream fout(output_filename, ios::binary);	
	fout.write((char *)header, HEADER_LENGTH);

	for(int i=0; i<=height; i++)
	{
		for(int j=0; j<width*3; j++)
			pixels[i][j] = 255 - pixels[i][j];

		fout.write((char *)pixels[i], row_size);
	}
	fout.close();
}

void Image::histogram()
{
	int cnt[256] = {0};
	int maxi = -1;

	unsigned char pix[1000] = {0};
	unsigned char heads[HEADER_LENGTH] = {66, 77, 138, 0, 3, 0, 0, 0, 0, 0, 138, 
		0, 0, 0, 124, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 
		0, 0, 3, 0, 18, 11, 0, 0, 18, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		//256x256 image

	ofstream fouts("histogram.bmp");
	fouts.write((char *)heads, HEADER_LENGTH);

	for(int i=0; i<=height; i++)
		for(int j=0; j<width*3; j+=3)
			cnt[pixels[i][j]]++;

	for(int i=0; i<256; i++)
		maxi = max(maxi, cnt[i]);

	for(int i=0; i<256; i++)
	{
		for(int j=0; j<768; j+=3)
			pix[j] = 255, pix[j+1] = 10, pix[j+2] = 10;
		for(int j=84; j<(cnt[i]*768.0/maxi); j+=3)
			pix[j] = pix[j+1] = pix[j+2] = i;

		fouts.write((char *)pix, 768);
	}	
	fouts.close();
}

int main()
{
	Image img;
	img.open("output.bmp");
	img.histogram();
	img.RGB_toGrayScale("output.bmp");
	img.negative("negativeGray.bmp");
}
