#include <windows.h>
#include <iostream>
#include <math.h>
#include "imge_bmp.h"
#include <string.h>
#include <cstring>
#include <atlstr.h>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include<ctime>

#define PI 3.14159265
#define REDPIXEL 2

/// ibrahimcls  bknz
BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

	// read file header
	if (ReadFile(file, &bmpheader, sizeof(BITMAPFILEHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof(BITMAPINFOHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB') {
		CloseHandle(file);
		return NULL;
	}
	// get image measurements
	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB) {
		CloseHandle(file);
		return NULL;
	}
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		CloseHandle(file);
		return NULL;
	}

	// create buffer to hold the data
	size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[size];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Buffer, size, &bytesread, NULL) == false) {
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}//LOADPMB

bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile)
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;

	// andinitialize them to zero
	memset(&bmfh, 0, sizeof(BITMAPFILEHEADER));
	memset(&info, 0, sizeof(BITMAPINFOHEADER));

	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits

	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile(bmpfile, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == NULL) {
		CloseHandle(file);
		return false;
	}
	// write file header
	unsigned long bwritten;
	if (WriteFile(file, &bmfh, sizeof(BITMAPFILEHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write infoheader
	if (WriteFile(file, &info, sizeof(BITMAPINFOHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write image data
	if (WriteFile(file, Buffer, paddedsize, &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}

	// and close file
	CloseHandle(file);

	return true;
} // SaveBMP

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width * height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11 * Buffer[bufpos + 2] + 0.59 * Buffer[bufpos + 1] + 0.3 * Buffer[bufpos]);

			//int mx = 20;
			//int my = 20;
			//int r = 10;
			//int x1 = 0;
			//int y1 = 0;
			//int nokta = 0;
			//for (double i = 0; i < 360; i++)
			//{
			//	x1 = (mx + r * cos(i));
			//	y1 = (my + r * sin(i));
			//	nokta = (y1 - 1) * width + x1;
			//	newbuf[nokta] = 0;
			//	/*x1 = x * cos(i) - y * sin(i);
			//	y1 = x * sin(i) + y * cos(i);*/

			//}


		}

	return newbuf;
}//ConvetBMPToIntensity

BYTE* yeni(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width * height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE( Buffer[bufpos] );
			

			//int mx = 20;
			//int my = 20;
			//int r = 10;
			//int x1 = 0;
			//int y1 = 0;
			//int nokta = 0;
			//for (double i = 0; i < 360; i++)
			//{
			//	x1 = (mx + r * cos(i));
			//	y1 = (my + r * sin(i));
			//	nokta = (y1 - 1) * width + x1;
			//	newbuf[nokta] = 0;
			//	/*x1 = x * cos(i) - y * sin(i);
			//	y1 = x * sin(i) + y * cos(i);*/

			//}


		}

	return newbuf;
}//ConvetBMPToIntensity
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long newsize)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	// we can already store the size of the new padded buffer
	newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[newsize];

	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset(newbuf, 0, newsize);

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			bufpos = row * width + column;     // position in original buffer
			newpos = (height - row - 1) * psw + column * 3;           // position in padded buffer
			newbuf[newpos] = Buffer[bufpos];       //  blue
			newbuf[newpos + 1] = Buffer[bufpos];   //  green
			newbuf[newpos + 2] = Buffer[bufpos];   //  red
		}

	return newbuf;
} //ConvertIntensityToBMP

BYTE* Convolve(BYTE* p, int* width, int* height, double* M, int k)
{
	double temp = 0;
	BYTE* cov = new BYTE[(*height - k - 1) * (*width - k - 1)];
	
	for (int i = 0; i < (*width - 2) * (*height - 2); i++) {
		temp = 0;
		for (int j = 0; j < k; j++) {

			temp += p[i + j] * M[j];
			temp += p[i + j + *width] * M[j + k];
			temp += p[i + j + *width + *width] * M[j + k + k];
		}
		if (temp < 0)
			temp = 0;
		else if (temp > 255)
			temp = 255;
		cov[i] = temp;  //   / sayi yapılabilir kesirli filtreler için
	}
	//---------------------------------------------------------------------------------------------------------------
	//double temp = 0;
	//BYTE* cov = new BYTE[(*height - k - 1) * (*width - k - 1)];
	//
	//for (int i = 0; i < (*width - 2) * (*height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += p[i + j] * M[j];
	//		temp += p[i + j + *width] * M[j + k];
	//		temp += p[i + j + *width + *width] * M[j + k + k];
	//	}
	//	if (temp/16 < 0)
	//		temp = 0;
	//	else if (temp/16 > 255)
	//		temp = 255;
	//	cov[i] = temp/16;  //   / sayi yapılabilir kesirli filtreler için
	//}

	// temp = 0;
	//  M = new double[9]{ -1,-1, -1, -1, 8, -1, -1, -1, -1 };

	//for (int i = 0; i < (*width - 2) * (*height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += cov[i + j] * M[j];
	//		temp += cov[i + j + *width] * M[j + k];
	//		temp += cov[i + j + *width + *width] * M[j + k + k];
	//	}
	//	if (temp  < 0)
	//		temp = 0;
	//	else if (temp  > 255)
	//		temp = 255;
	//	cov[i] = temp ;  //   / sayi yapılabilir kesirli filtreler için
	//}
	

	return cov;
}


//BYTE* Convolve(BYTE* p, int* width, int* height, double* M, int k)
//{
//	double temp = 0;
//	BYTE* cov = new BYTE[(*height-k-1 ) * (*width-k-1) ];
//	/*
//	for (int row = 0; row < *height - k - 1; row++) {
//		for (int col = 0; col < *width - k - 1; col++) {
//			temp = 0;
//			for (int i = 0; i < k; i++) {
//				for (int j = 0; j < k; j++) {
//					temp += p[(row + i) * (*width) + col + j] * M[i * k + j];
//				}
//			}
//			if (temp < 0)
//				temp = 0;
//			else if (temp > 255)
//				temp = 255;
//			cov[row * (*width - k - 1) + col] = temp;
//		}
//	}
//	*/
//	for (int i = 0; i < (*width-2) * (*height-2) ; i++) {
//		temp = 0;
//		for (int j = 0; j < k; j++) {
//
//		temp +=	p[i+j] * M[j];
//		temp += p[i+j + *width] * M[j + k];
//		temp += p[i+j + *width + *width] * M[j + k + k];
//		}
//		if (temp < 0)
//				temp = 0;
//			else if (temp > 255)
//				temp = 255;
//		cov[i] = temp;
//	}
//
//	
//	return cov;
//}

void segmentation() {
	

}
int* segmentation(int* histogram, int length) {
	
	float t1, t2, nt1, nt2,t3,nt3,t4,nt4;
	float t1pay, t1payda;
	float t2pay, t2payda;
	float t3pay, t3payda;
	float t4pay, t4payda;

	int* K = new int[4];

	t1 = 0;
	t2 = 64;
	t3 = 128;
	t4 = 255;
	while (1) {
		t1pay = 0; t1payda = 0;
		t2pay = 0; t2payda = 0;
		t3pay = 0; t3payda = 0;
		t4pay = 0; t4payda = 0;
		for (int i = 0; i < 256; i++) {     //tüm indisler için en yakýn t deðerine eklenir.
			if (fabs(i - t1) < fabs(i - t2) && fabs(i - t1) < fabs(i - t3)&& fabs(i - t1) < fabs(i - t4)) {
				t1pay += histogram[i] * i;
				t1payda += histogram[i];
			}
			else if(fabs(i - t2) < fabs(i - t1) && fabs(i - t2) < fabs(i - t3)&& fabs(i - t2) < fabs(i - t4)) {
				t2pay += histogram[i] * i;
				t2payda += histogram[i];
			}
			else if (fabs(i - t3) < fabs(i - t1) && fabs(i - t3) < fabs(i - t2) && fabs(i - t3) < fabs(i - t4)) {
				t3pay += histogram[i] * i;
				t3payda += histogram[i];
			}
			else if (fabs(i - t4) < fabs(i - t1) && fabs(i - t4) < fabs(i - t2) && fabs(i - t4) < fabs(i - t3)) {
				t4pay += histogram[i] * i;
				t4payda += histogram[i];
			}
		}
		nt1 = t1pay / t1payda; //t1 üstü 
		nt2 = t2pay / t2payda; //t2 üstü
		nt3 = t3pay / t3payda; //t2 üstü
		nt4 = t4pay / t4payda; //t2 üstü
		if (t1 == nt1 && t2 == nt2 && t3 == nt3 && t4 == nt4) break;
		else {
			t1 = nt1;
			t2 = nt2;
			t3 = nt3;
			t4 = nt4;
		}
	}
	K[0] = t1;
	K[1] = t2;
	K[2] = t3;
	K[3] = t4;
	
	return K;
}
int* KMeans(int* histogram, int length) {
	float t1, t2, nt1, nt2;
	float t1pay, t1payda;
	float t2pay, t2payda;

	int* K = new int[2];

	t1 = 100;
	t2 = 200;
	while (1) {
		t1pay = 0; t1payda = 0;
		t2pay = 0; t2payda = 0;
		for (int i = 0; i < 256; i++) {     //tüm indisler için en yakýn t deðerine eklenir.
			if (fabs(i - t1) < fabs(i - t2)) {
				t1pay += histogram[i] * i;
				t1payda += histogram[i];
			}
			else {
				t2pay += histogram[i] * i;
				t2payda += histogram[i];
			}
		}
		nt1 = t1pay / t1payda; //t1 üstü 
		nt2 = t2pay / t2payda; //t2 üstü
		if (t1 == nt1 && t2 == nt2) break;
		else {
			t1 = nt1;
			t2 = nt2;
		}
	}
	K[0] = t1;
	K[1] = t2;
	return K;
}

int* histogram(BYTE* image, int* width, int* height) {

	int* histogramm = new int[256]{};
	for (int i = 0; i < 256; i++) {
		histogramm[i] = 0;
	}
	/*for (int row = 0; row < *height; row++) {
		for (int col = 0; col < *width; col++) {
			int var = image[row * (*width) + col];
			++histogramm[var];
		}
	}*/
		for (int i = 0; i < (*width )* (*height); i++) {
			int var = image[i];
			++histogramm[var];
		}
	
	return histogramm;
}

BYTE* binaryImage(BYTE* image, int* width, int* heigth, int* K) {
	BYTE* sonuc = new BYTE[*width * *heigth]{};
	for (int i = 0; i < (*width) * (*heigth); i++) {
		if (fabs(image[i] - K[0]) < fabs(image[i] - K[1]))
			sonuc[i] = 0;
		else
			sonuc[i] = 255;
	}

	return sonuc;
}

BYTE* tirnaryImage(BYTE* image, int* width, int* heigth, int* K) {
	BYTE* sonuc = new BYTE[*width * *heigth]{};
	for (int i = 0; i < (*width) * (*heigth); i++) {
		if (fabs(image[i] - K[0]) < fabs(image[i] - K[1])&& fabs(image[i] - K[0]) < fabs(image[i] - K[2]))
			sonuc[i] = 0;
		else if (fabs(image[i] - K[1]) < fabs(image[i] - K[0]) && fabs(image[i] - K[1]) < fabs(image[i] - K[2]))
			sonuc[i] = 255;
		else if (fabs(image[i] - K[2]) < fabs(image[i] - K[0]) && fabs(image[i] - K[2]) < fabs(image[i] - K[1]))
			sonuc[i] = 127;
	}

	return sonuc;
}
BYTE* fournaryImage(BYTE* image, int* width, int* heigth, int* K) {
	BYTE* sonuc = new BYTE[*width * *heigth]{};
	for (int i = 0; i < (*width) * (*heigth); i++) {
		if (fabs(image[i] - K[0]) < fabs(image[i] - K[1]) && fabs(image[i] - K[0]) < fabs(image[i] - K[2]) && fabs(image[i] - K[0]) < fabs(image[i] - K[3]))
			sonuc[i] = 0;
		else if (fabs(image[i] - K[1]) < fabs(image[i] - K[0]) && fabs(image[i] - K[1]) < fabs(image[i] - K[2]) && fabs(image[i] - K[1]) < fabs(image[i] - K[3]))
			sonuc[i] = 255;
		else if (fabs(image[i] - K[2]) < fabs(image[i] - K[0]) && fabs(image[i] - K[2]) < fabs(image[i] - K[1]) && fabs(image[i] - K[2]) < fabs(image[i] - K[3]))
			sonuc[i] = 64;
		else if (fabs(image[i] - K[3]) < fabs(image[i] - K[0]) && fabs(image[i] - K[3]) < fabs(image[i] - K[1]) && fabs(image[i] - K[3]) < fabs(image[i] - K[2]))
			sonuc[i] = 128;
	}

	return sonuc;
}

void kutu(int dizi[][376], int etiket_sayisi, int* etiketler) {
	
	
	for (int i = etiketler[0]; i < etiketler[2]; i++) {
		dizi[i][etiketler[1]] = 0;
	}
	for (int i = etiketler[1]; i < etiketler[3]; i++) {
		dizi[etiketler[2]][i] = 0;
	}
	for (int i = etiketler[0]; i < etiketler[2]; i++) {
		dizi[i][etiketler[3]] = 0;
	}
	for (int i = etiketler[1]; i < etiketler[3]; i++) {
		dizi[etiketler[0]][i] = 0;
	}


}
int* nesne_pixel_dizisi(int dizi[][500]) {
	int tempp[40];
	for (int i = 0; i < 40; i++)
		tempp[i] = 255;
	for (int i = 1; i < 410 - 1; i++) {
		for (int j = 1; j < 376 - 1; j++) {
			if (dizi[i][j] != 255) {
				bool varr = false;
				for (int m = 0; m < 40; m++) {
					if (tempp[m] == dizi[i][j]) {
						varr = true;
						break;
					}
				}
				if (varr == false) {
					for (int l = 0; l < 40; l++) {
						if (tempp[l] == 255) {
							tempp[l] = dizi[i][j];
							break;
						}
					}
				}
			}


		}
	}

	return tempp;
}




void etiket_duzelt(int dizi[][500], int etiket_sayisi, int* etiketler,int Width,int Height) {


	for (int k = 0; k < etiket_sayisi; k++) {
		for (int i = 1; i < Width -1; i++) {
			for (int j = 1; j < Height -1; j++) {

				if (dizi[i][j] == etiketler[k]) {
					dizi[i][j] = k + 1;
				}

			}
		}
	}

}
// BU FONKSİYONDAN KORDİNAT DEĞERLERİ DİZİ İÇİNDE DÖNER
int* coordinate(int dizi[][500], int* yeni_etiket_degeri, int etiket_sayisi, int Width, int Height) {

	int global = -1;
	int x = Width;
	int y = Height;
	int x1 = 0;
	int y1 = 0;
	int coor[50];
	for (int k = 0; k < etiket_sayisi; k++) {
		for (int i = 1; i < Width -1; i++) {
			for (int j = 1; j < Height -1; j++) {
				if (dizi[i][j] == yeni_etiket_degeri[k]) {
					if (i < x)
						x = i;
					if (j < y)
						y = j;
					if (i > x1)
						x1 = i;
					if (j > y1)
						y1 = j;


				}

			}

		}
		coor[++global] = x;
		coor[++global] = y;
		coor[++global] = x1;
		coor[++global] = y1;
		x = Width; y = Height; x1 = 0; y1 = 0;
	}


	return coor;
}
int* etiketler(int dizi[][500], int* nesne_sayisi, int Width, int Height) {
	int sayac = 0;
	for (int i = 1; i < Width -1; i++) {
		for (int j = 1; j < Height -1; j++) {
			bool var = false;
			if (dizi[i][j] != 255) {
				int k = 0;
				while (k < sayac) {
					if (dizi[i][j] == nesne_sayisi[k]) {
						var = true;

					}
					k++;
				}

				if (var == false) {
					nesne_sayisi[sayac] = dizi[i][j];
					sayac++;
				}



			}

		}
	}
	// cout << nesne_sayisi[0] << "   " << nesne_sayisi[1] << "   " << nesne_sayisi[2] << "   " << nesne_sayisi[3] << "   " << nesne_sayisi[4] << "   ";
	return nesne_sayisi;
}
int yeni_etiket(int dizi[][500]) {

	int e = -1;
	int degisken = 0;
	for (int i = 1; i < 410-1; i++) {
		for (int j = 1; j < 376 -1; j++) {
			if (dizi[i][j] != 255) {
				degisken = dizi[i][j];
				break;
			}

		}
		if (degisken != 0)
			break;
	}
	return degisken;
}


int enkucuk(int* dizi) {
	int temp;

	for (int i = 0; i < 9 - 1; i++)
		for (int j = 0; j < 9 - 1; j++)
		{
			if (dizi[j] > dizi[j + 1])
			{
				temp = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = temp;
			}
		}
	return dizi[0];

}

int distanceQuantize(int distance)
{
	return rint(double(distance) / 4) * 4;
}

int* houghTransformLine(BYTE* raw_intensity, int imageW, int imageH, int* binaryImage, int Width, int Height, int& houghWidth, int& houghHeight)
{
	int imDiff = (imageW - Width) / 2;

	houghHeight = (int)((imageW)*cos(atan2(imageH, imageW)) + imageH * sin(atan2(imageH, imageW)));	// goruntudeki max kosegen uzakligi 
	houghWidth = 180;																									// [0,45,90,135]

	int* houghSpace = (int*)calloc(houghHeight * houghWidth, sizeof(int));

	int distance = 0;

	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			if (raw_intensity[row * Width + col] == 1)
			{
				for (int q = 0; q < 180; q++)
				{
					distance = distanceQuantize(abs((col + imDiff) * cos(q * PI / 180) + (row + imDiff) * sin(q * PI / 180)));
					houghSpace[distance * houghWidth + q]++;
				}
			}
		}
	}

	return houghSpace;
}

void controlMaxEdge(BYTE* raw_intensity, int imWidth, int imHeight, int* binaryEdge, int Width, int Height, std::vector <int>& MaxsD, std::vector<int>& MaxsQ)
{

	int imDiff = (imWidth - Width) / 2;
	int distance = 0;

	for (int i = 0; i < MaxsD.size(); i++)
	{
		for (int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				if (raw_intensity[row * Width + col] == 1)
				{
					for (int i = 0; i < MaxsD.size(); i++)
					{
						distance = distanceQuantize(abs((col)*cos(MaxsQ[i] * PI / 180) + (row)*sin(MaxsQ[i] * PI / 180)));

						if (MaxsD[i] == distance)
						{
							raw_intensity[(row + imDiff) * imWidth + col + imDiff] = REDPIXEL;
							break;
						}
					}
				}
			}
		}
	}
}

double* moment(int* dizi,int Width,int Height) {
	 


	
	
	double m00 = 0;
	double m10 = 0;
	double m01 = 0;
	double ort_x = 0;
	double ort_y = 0;
	double h[7];
	m00 = M(dizi, 0, 0, Height, Width);
	m10 = M(dizi, 1, 0, Height, Width);
	m01 = M(dizi, 0, 1, Height, Width);

	ort_x = m10 / m00;
	ort_y = m01 / m00;



	// double a = Mij_nij(dizi, 2, 0, Height, Width, ort_x, ort_y, m00);

	h[0] = Mij_nij(dizi, 2, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 2, Height, Width, ort_x, ort_y, m00);

	h[1] = pow(Mij_nij(dizi, 2, 0, Height, Width, ort_x, ort_y, m00) - Mij_nij(dizi, 0, 2, Height, Width, ort_x, ort_y, m00), 2) + 4 * pow(Mij_nij(dizi, 1, 1, Height, Width, ort_x, ort_y, m00), 2);

	h[2] = pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) - 3 * Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) +
		pow(3 * Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) - Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2);

	h[3] = pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) +
		pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2);

	h[4] = (Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) - 3 * Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00)) * (Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00)) *
		(pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) - 3 * pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2)) +
		(3 * Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) - Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00)) * (Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00)) *
		(3 * pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) - pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2));

	h[5] = (Mij_nij(dizi, 2, 0, Height, Width, ort_x, ort_y, m00) - Mij_nij(dizi, 0, 2, Height, Width, ort_x, ort_y, m00)) *
		(pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) - pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2)) +
		4 * Mij_nij(dizi, 1, 1, Height, Width, ort_x, ort_y, m00) * (Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00)) * (Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00));

	h[6] = (3 * Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) - Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00)) * (Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00)) *
		(pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) - 3 * pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2)) -
		(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) - 3 * Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00)) * (Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00)) *
		(3 * pow(Mij_nij(dizi, 3, 0, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 1, 2, Height, Width, ort_x, ort_y, m00), 2) - pow(Mij_nij(dizi, 2, 1, Height, Width, ort_x, ort_y, m00) + Mij_nij(dizi, 0, 3, Height, Width, ort_x, ort_y, m00), 2));


	return h;
}

int M(int* dizi, int i, int j, int Height, int Width) {


	int m = 0;
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {

			m += pow(row, i) * pow(col, j) * dizi[(row)*Width + col];

		}
	}

	return m;
}

double Mij_nij(int* dizi, int i, int j, int Height, int Width, double ort_x, double ort_y, double m00) {


	double m = 0;
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {

			m += pow(row - ort_x, i) * pow(col - ort_y, j) * dizi[(row)*Width + col];

		}
	}

	m = m / pow(m00, ((i + j) / 2) + 1);

	return m;
}
