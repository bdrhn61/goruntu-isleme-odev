#pragma once
#include <windows.h>

#include <vector>
#include <atlstr.h>	
BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);
bool  SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long% newsize);
int* KMeans(int* histogram, int length);
int* histogram(BYTE* image, int* width, int* height);
BYTE* binaryImage(BYTE* image, int* width, int* heigth, int* K);
BYTE* Convolve(BYTE* p, int* width, int* height, double* M, int k);
void segmentation();
double* Convolve(double* p, int* width, int* height, double* M, int k);
int* segmentation(int* histogram, int length);
BYTE* tirnaryImage(BYTE* image, int* width, int* heigth, int* K);
BYTE* yeni(BYTE* Buffer, int width, int height);
BYTE* fournaryImage(BYTE* image, int* width, int* heigth, int* K);
//-------------------------------------------------------------------------------------------------
//SEGMENTASYON FONKSÝYONLARI
void etiket_duzelt(int dizi[][500], int etiket_sayisi, int* etiketler, int Width, int Height);
int* coordinate(int dizi[][500], int* yeni_etiket_degeri, int etiket_sayisi, int Width, int Height);
int* etiketler(int dizi[][500], int* nesne_sayisi, int Width, int Height);
int yeni_etiket(int dizi[][500]);
int enkucuk(int* dizi);
int* nesne_pixel_dizisi(int dizi[][500]);
//---------------------------------------------------------------------------------------------------
void kutu(int dizi[][376], int etiket_sayisi, int* etiketler);

//MORFOLOJÝ
//---------------------------------------------------------------------------------------------------
//houg
//////////////////////////////////////////////////////////////////////////////////////////////////////7
int distanceQuantize(int distance);
int* houghTransformLine(BYTE* raw_intensity, int imageW, int imageH, int* binaryImage, int Width, int Height, int& houghWidth, int& houghHeight);
void controlMaxEdge(BYTE* raw_intensity, int imWidth, int imHeight, int* binaryEdge, int Width, int Height, std::vector <int>& MaxsD, std::vector<int>& MaxsQ);

///////////////////////////////////////////////////////////////////////////////////
//MOMENT
double* moment(int* dizi, int Width, int Height);
int M(int* dizi, int i, int j, int Height, int Width);
double Mij_nij(int* dizi, int i, int j, int Height, int Width, double ort_x, double ort_y, double m00);