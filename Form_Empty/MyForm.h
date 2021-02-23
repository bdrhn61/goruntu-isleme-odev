#pragma once

#include <iostream>
#include <windows.h>
#include <math.h>
#include "imge_bmp.h"
#include <string.h>
#include <cstring>
#include <atlstr.h>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include<ctime>
#include <fstream>
#include <string>
#include <string>



#define PI 3.14159265
#define REDPIXEL 2
namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ siyahBeyazToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ataToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ filtreleToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ segmentToolStripMenuItem;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::ToolStripMenuItem^ fournaryImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tirnaryImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ detecToolStripMenuItem;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ morphologiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ erosionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sobelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cannyToolStripMenuItem;




	private: System::Windows::Forms::CheckBox^ Boxxx;






	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->siyahBeyazToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fournaryImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tirnaryImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtreleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->segmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->detecToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cannyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->morphologiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Boxxx = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->morphologiToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(995, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->openToolStripMenuItem,
					this->siyahBeyazToolStripMenuItem, this->ataToolStripMenuItem, this->filtreleToolStripMenuItem, this->segmentToolStripMenuItem,
					this->detecToolStripMenuItem, this->sobelToolStripMenuItem, this->cannyToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"file";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->openToolStripMenuItem->Text = L"open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// siyahBeyazToolStripMenuItem
			// 
			this->siyahBeyazToolStripMenuItem->Name = L"siyahBeyazToolStripMenuItem";
			this->siyahBeyazToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->siyahBeyazToolStripMenuItem->Text = L"gri";
			this->siyahBeyazToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::siyahBeyazToolStripMenuItem_Click);
			// 
			// ataToolStripMenuItem
			// 
			this->ataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fournaryImageToolStripMenuItem,
					this->tirnaryImageToolStripMenuItem
			});
			this->ataToolStripMenuItem->Name = L"ataToolStripMenuItem";
			this->ataToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ataToolStripMenuItem->Text = L"k-mean";
			this->ataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ataToolStripMenuItem_Click);
			// 
			// fournaryImageToolStripMenuItem
			// 
			this->fournaryImageToolStripMenuItem->Name = L"fournaryImageToolStripMenuItem";
			this->fournaryImageToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->fournaryImageToolStripMenuItem->Text = L"tirnaryImage";
			this->fournaryImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fournaryImageToolStripMenuItem_Click);
			// 
			// tirnaryImageToolStripMenuItem
			// 
			this->tirnaryImageToolStripMenuItem->Name = L"tirnaryImageToolStripMenuItem";
			this->tirnaryImageToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->tirnaryImageToolStripMenuItem->Text = L"fournaryImage";
			this->tirnaryImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tirnaryImageToolStripMenuItem_Click);
			// 
			// filtreleToolStripMenuItem
			// 
			this->filtreleToolStripMenuItem->Name = L"filtreleToolStripMenuItem";
			this->filtreleToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->filtreleToolStripMenuItem->Text = L"filtrele";
			this->filtreleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::filtreleToolStripMenuItem_Click_1);
			// 
			// segmentToolStripMenuItem
			// 
			this->segmentToolStripMenuItem->Name = L"segmentToolStripMenuItem";
			this->segmentToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->segmentToolStripMenuItem->Text = L"segment";
			this->segmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::segmentToolStripMenuItem_Click);
			// 
			// detecToolStripMenuItem
			// 
			this->detecToolStripMenuItem->Name = L"detecToolStripMenuItem";
			this->detecToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->detecToolStripMenuItem->Text = L"box";
			this->detecToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::detecToolStripMenuItem_Click);
			// 
			// sobelToolStripMenuItem
			// 
			this->sobelToolStripMenuItem->Name = L"sobelToolStripMenuItem";
			this->sobelToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->sobelToolStripMenuItem->Text = L"sobel";
			this->sobelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sobelToolStripMenuItem_Click);
			// 
			// cannyToolStripMenuItem
			// 
			this->cannyToolStripMenuItem->Name = L"cannyToolStripMenuItem";
			this->cannyToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->cannyToolStripMenuItem->Text = L"canny";
			this->cannyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cannyToolStripMenuItem_Click);
			// 
			// morphologiToolStripMenuItem
			// 
			this->morphologiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->erosionToolStripMenuItem,
					this->dilationToolStripMenuItem
			});
			this->morphologiToolStripMenuItem->Name = L"morphologiToolStripMenuItem";
			this->morphologiToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->morphologiToolStripMenuItem->Text = L"morphologi";
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->erosionToolStripMenuItem->Text = L"erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::erosionToolStripMenuItem_Click);
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->dilationToolStripMenuItem->Text = L"dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dilationToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(641, 359);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(755, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(755, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(755, 221);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(755, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label4";
			// 
			// Boxxx
			// 
			this->Boxxx->AutoSize = true;
			this->Boxxx->Location = System::Drawing::Point(749, 52);
			this->Boxxx->Name = L"Boxxx";
			this->Boxxx->Size = System::Drawing::Size(206, 17);
			this->Boxxx->TabIndex = 6;
			this->Boxxx->Text = L"Moment değerleriyle veri tabanı oluştur";
			this->Boxxx->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(995, 451);
			this->Controls->Add(this->Boxxx);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		openFileDialog1->InitialDirectory = "C:\\Users\\balboa\\Resimler";
		openFileDialog1->Title = "Insert an image";
		openFileDialog1->FileName = "";

		if (openFileDialog1->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
			pictureBox1->ImageLocation = openFileDialog1->FileName;


		/*else
{
	MessageBox.Show("asfafs");
}*/

/*if (openFileDialog1->ShowDialog() == Di) {

}*/




/*if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	pictureBox1->ImageLocation = openFileDialog1->FileName;
}*/



	}
	private: System::Void siyahBeyazToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		LPCTSTR input, output;
		int Width, Height;
		long Size, new_size;

		CString str;
		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;
		BYTE* buffer = LoadBMP(Width, Height, Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);



		Bitmap^ surface = gcnew Bitmap(Width, Height);


		Color c;
		for (int row = 0; row < Height; row++) {
			for (int col = 0; col < Width; col++) {

				c = Color::FromArgb(raw_intensity[(row)*Width + col], raw_intensity[(row)*Width + col], raw_intensity[(row)*Width + col]);
				surface->SetPixel(col, row, c);
			}
		}
		pictureBox1->Image = surface;
	}


	private: System::Void ataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		LPCTSTR input, output;
		int Width, Height;
		long Size, new_size;
		CString str;
		/* int t1 = 100, t2 = 200, a1 = 0, a2 = 0, l1 = 0, l2 = 0;*/
		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;
		BYTE* buffer = LoadBMP(Width, Height, Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

		///basla
		int length = 2;
		int* Myhistogram = histogram(raw_intensity, &Width, &Height);
		int* K = new int[2];
		K = KMeans(Myhistogram, length);
		BYTE* sonuc = binaryImage(raw_intensity, &Width, &Height, K);
		///bitir
		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox1->Image = surface;


		Color c;

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				c = Color::FromArgb(sonuc[row * Width + column], sonuc[row * Width + column], sonuc[row * Width + column]);
				surface->SetPixel(column, row, c);
			}
		}
	}



	private: System::Void filtreleToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		int Width, Height;
		long Size;


		BYTE* buffer;
		BYTE* raw_intensity;
		
		CString str = openFileDialog1->FileName;
		LPCTSTR input = (LPCTSTR)str;
		
		buffer = LoadBMP(Width, Height, Size, input);
		raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
		//double* raw_intensity1 = new double(Width * Height);
		/*raw_intensity1[5] = raw_intensity[5];*/
		/*for (int i = 0; i < Width * Height; i++) {
			raw_intensity1[i] = raw_intensity[i];
		}*/

		double* mask2 = new double[9]{ 1, 1, 1, 1, -8, 1, 1, 1, 1 };
		double* mask5 = new double[9]{-1,-1, -1, -1, 8, -1, -1, -1, -1};
		double* mask = new double[9]{ 1, 2 , 1 , 2 , 4 , 2 , 1 , 2 , 1  };
		double* mask3 = new double[25]{ 1, 4, 7, 4, 1, 4, 16, 26, 16, 4, 7, 26, 41, 26, 7, 4, 16, 26, 16, 4, 1, 4, 7, 4, 1 };
		double* mask4 = new double[25]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		BYTE* zoomconv = Convolve(raw_intensity, &Width, &Height, mask2, 3);
		Bitmap^ surface = gcnew Bitmap(Width, Height);
	//	pictureBox1->Image = surface;


		Color c;
		int a = 0;
		for (int row = 0; row < Height; row++)
		{
			
			for (int column = 0; column < Width; column++)
			{
				//c = Color::FromArgb(raw_intensity[row*Width + column], raw_intensity[row*Width + column], raw_intensity[row*Width + column]);
				c = Color::FromArgb(zoomconv[row * Width + column], zoomconv[row * Width + column], zoomconv[row * Width + column]);
				surface->SetPixel(column, row, c);
				
			}
		}
		pictureBox1->Image = surface;
	}

	
	private: System::Void segmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		LPCTSTR input, output;
		int Width, Height;
		long Size, new_size;

		CString str;
		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;
		BYTE* buffer = LoadBMP(Width, Height, Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
		int length = 2;
		int* Myhistogram = histogram(raw_intensity, &Width, &Height);
		int* K = new int[2];
		K = KMeans(Myhistogram, length);
		BYTE* sonuc = binaryImage(raw_intensity, &Width, &Height, K);

		
		Bitmap^ surface = gcnew Bitmap(Width, Height);
		int dizi[500][500];
		label1->Text = Width.ToString();
		label2->Text = Height.ToString();

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				dizi[column][row] = sonuc[row * Width + column];
			}
		}
		/*label1->Text = dizi[100][100].ToString();
		label2->Text = raw_intensity[0].ToString();*/
		//-----------------------------------------------------------------------------------------------------------------------
		//SEGMENTASYON İŞLELERİ

		int sirala[9] = { 0,0,0,0,0,0,0,0,0 };
		bool kontrol = false;
		int nesne_sayisi[100];
		int etiket_sayisi = 0;

		for (int i = 0; i < 100; i++)
			nesne_sayisi[i] = 255;

		int etiket = 1;
		for (int i = 1; i < Width - 1; i++) {
			for (int j = 1; j < Height - 1; j++) {

				if (dizi[i][j] == 0) {

					dizi[i][j] = etiket;
					etiket++;
					if (etiket == 255)
						etiket++;

				}
				// cout<< dizi[i][j]<<"  ";
			}
			// cout << endl;
		}



		int sayac = 0;
		int k = 0;
		while (1) {
			// cout << k << endl;
			for (int i = 1; i < Width - 1; i++) {
				for (int j = 1; j < Height - 1; j++) {
					if (dizi[i][j] != 255)
						/*dizi[i - 1][j]!= 255 &&
						dizi[i + 1][j] != 255 &&
						dizi[i][j - 1] != 255 &&
						dizi[i][j + 1] != 255 &&
						dizi[i - 1][j - 1] != 255 &&
						dizi[i + 1][j + 1] != 255 &&
						dizi[i - 1][j + 1] != 255 &&
						dizi[i + 1][j - 1] != 255)*/ {

						sirala[0] = dizi[i - 1][j];
						sirala[1] = dizi[i + 1][j];
						sirala[2] = dizi[i][j - 1];
						sirala[3] = dizi[i][j + 1];
						sirala[4] = dizi[i - 1][j - 1];
						sirala[5] = dizi[i + 1][j + 1];
						sirala[6] = dizi[i - 1][j + 1];
						sirala[7] = dizi[i + 1][j - 1];
						sirala[8] = dizi[i][j];
						//int temp = dizi[i][j];
						for (int i = 0; i < 9; i++) {
							if (sirala[i] == 255)
								sirala[i] = 410 * 376;
						}
						if (dizi[i][j] != enkucuk(sirala)) {
							dizi[i][j] = enkucuk(sirala);
							sayac++;
						}
					}
				}
			}
			if (sayac != 0)
				sayac = 0;
			else
				break;
			k++;
		}

		



		int l = -1;
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				raw_intensity[++l] = dizi[column][row];
			}
		}
		
		
		Color c;
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				surface->SetPixel(column, row, c);
			}
		}
		pictureBox1->Image = surface;
	}
private: System::Void fournaryImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;
	CString str;
	/* int t1 = 100, t2 = 200, a1 = 0, a2 = 0, l1 = 0, l2 = 0;*/
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	///basla
	int length = 3;
	int* Myhistogram = histogram(raw_intensity, &Width, &Height);
	int* K = new int[3];
	K = segmentation(Myhistogram, length);
	BYTE* sonuc = tirnaryImage(raw_intensity, &Width, &Height, K);
	///bitir
	Bitmap^ surface = gcnew Bitmap(Width, Height);
	pictureBox1->Image = surface;



	Color c;

	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
			c = Color::FromArgb(sonuc[row * Width + column], sonuc[row * Width + column], sonuc[row * Width + column]);
			surface->SetPixel(column, row, c);
		}
	}




}
private: System::Void tirnaryImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;
	CString str;
	/* int t1 = 100, t2 = 200, a1 = 0, a2 = 0, l1 = 0, l2 = 0;*/
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	///basla
	int length = 3;
	int* Myhistogram = histogram(raw_intensity, &Width, &Height);
	int* K = new int[3];
	K = segmentation(Myhistogram, length);
	BYTE* sonuc = fournaryImage(raw_intensity, &Width, &Height, K);
	///bitir
	Bitmap^ surface = gcnew Bitmap(Width, Height);
	pictureBox1->Image = surface;


	Color c;

	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
			c = Color::FromArgb(sonuc[row * Width + column], sonuc[row * Width + column], sonuc[row * Width + column]);
			surface->SetPixel(column, row, c);
		}
	}
}
private: System::Void detecToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;

	CString str;
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	int length = 2;
	int* Myhistogram = histogram(raw_intensity, &Width, &Height);
	int* K = new int[2];
	K = KMeans(Myhistogram, length);
	BYTE* sonuc = binaryImage(raw_intensity, &Width, &Height, K);


	Bitmap^ surface = gcnew Bitmap(Width, Height);
	int dizi[500][500];
	label1->Text = Width.ToString();
	label2->Text = Height.ToString();

	for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
				dizi[column][row]= sonuc[row * Width + column];
			}
		}
	/*label1->Text = dizi[100][100].ToString();
	label2->Text = raw_intensity[0].ToString();*/
	//-----------------------------------------------------------------------------------------------------------------------
	//SEGMENTASYON İŞLELERİ

	int sirala[9] = { 0,0,0,0,0,0,0,0,0 };
	bool kontrol = false;
	int nesne_sayisi[100];
	int etiket_sayisi = 0;

	for (int i = 0; i < 100; i++)
		nesne_sayisi[i] = 255;

	int etiket = 1;
	for (int i = 1; i < Width -1; i++) {
		for (int j = 1; j < Height -1; j++) {

			if (dizi[i][j] == 0) {
				
				dizi[i][j] = etiket;
				etiket++;
				if (etiket == 255)
					etiket++;

			}
			// cout<< dizi[i][j]<<"  ";
		}
		// cout << endl;
	}
	


	int sayac = 0;
	int k = 0;
	while (1) {
		// cout << k << endl;
		for (int i = 1; i < Width -1; i++) {
			for (int j = 1; j < Height -1; j++) {
				if (dizi[i][j] != 255 ) 
					/*dizi[i - 1][j]!= 255 &&
					dizi[i + 1][j] != 255 &&
					dizi[i][j - 1] != 255 &&
					dizi[i][j + 1] != 255 &&
					dizi[i - 1][j - 1] != 255 &&
					dizi[i + 1][j + 1] != 255 &&
					dizi[i - 1][j + 1] != 255 &&
					dizi[i + 1][j - 1] != 255)*/{

					sirala[0] = dizi[i - 1][j];
					sirala[1] = dizi[i + 1][j];
					sirala[2] = dizi[i][j - 1];
					sirala[3] = dizi[i][j + 1];
					sirala[4] = dizi[i - 1][j - 1];
					sirala[5] = dizi[i + 1][j + 1];
					sirala[6] = dizi[i - 1][j + 1];
					sirala[7] = dizi[i + 1][j - 1];
					sirala[8] = dizi[i][j];
					//int temp = dizi[i][j];
					for (int i = 0; i < 9; i++) {
						if (sirala[i] == 255)
							sirala[i] = 410 * 376;
					}
					if (dizi[i][j] != enkucuk(sirala)) {
						dizi[i][j] = enkucuk(sirala);
						sayac++;
					}
				}
			}
		}
		if (sayac != 0)
			sayac = 0;
		else
			break;
		k++;
	}

	int tempp[40];
	for (int i = 0; i < 40; i++)
		tempp[i] = 255;
	for (int i = 1; i < Width - 1; i++) {
		for (int j = 1; j < Height - 1; j++) {
			if (dizi[i][j] != 255) {
				bool varr = false;
				for (int m = 0; m < 40; m++){
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

	for (int i = 0;  tempp[i] != 255; i++)
		etiket_sayisi++;
	/*for (int i = 1; i < 410 - 1; i++) {
		for (int j = 1; j < 376 - 1; j++) {
			if (dizi[i][j] == 4755)
				dizi[i][j] = 255;
		}
	}*/
	/*label1->Text = tempp[0].ToString();
	label2->Text = tempp[1].ToString();
	label3->Text = tempp[2].ToString();
	label4->Text = tempp[3].ToString();*/
	
	

	/*  cout << "---------------------------" << endl;
	  for (int i = 1; i < 9; i++) {
		  for (int j = 1; j < 9; j++) {
			  cout << dizi[i][j] << "  ";
		  }
		  cout << endl;
	  }*/




	  /* int etiketdegeri[50];
	   int yeni_etiket_degeri = yeni_etiket(dizi);*/


	/*int sayacetiketler = 0;
	for (int i = 1; i < 410 - 1; i++) {
		for (int j = 1; j < 376 - 1; j++) {
			bool var = false;
			if (dizi[i][j] != 255) {
				int k = 0;
				while (k < sayacetiketler) {
					if (dizi[i][j] == nesne_sayisi[k]) {
						var = true;

					}
					k++;
				}

				if (var == false) {
					nesne_sayisi[sayacetiketler] = dizi[i][j];
					sayacetiketler++;
				}



			}

		}
	}*/

	   //ETİKETLER FONKSİYONUNDAN BÜTÜN ETİKET DEGERLERİ DİZİ İÇİNDE DÖNER
	   //BU DORUN İÇİNDE ETİKETLER SAYILIR
	   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*for (int i = 0;  nesne_sayisi[i] != 255; i++)
		etiket_sayisi++;*/
	//  cout <<"***** "<< etiketler(dizi, nesne_sayisi)[0];
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*for(int i=0;i<16;i++)
	 coordinate(dizi, etiketler(dizi, nesne_sayisi), etiket_sayisi)[i] ;*/

	//for (int i = 0; i < 4; i++)
		// cout <<"***" <<etiketler(dizi, nesne_sayisi)[i] << endl;

		etiket_duzelt(dizi, etiket_sayisi, etiketler(dizi, tempp, Width, Height), Width, Height);

		int yenitempp[40];
		for (int i = 0; i < 40; i++)
			yenitempp[i] = 255;
		for (int i = 1; i < Width - 1; i++) {
			for (int j = 1; j < Height - 1; j++) {
				if (dizi[i][j] != 255) {
					bool varr = false;
					for (int m = 0; m < 40; m++) {
						if (yenitempp[m] == dizi[i][j]) {
							varr = true;
							break;
						}
					}
					if (varr == false) {
						for (int l = 0; l < 40; l++) {
							if (yenitempp[l] == 255) {
								yenitempp[l] = dizi[i][j];
								break;
							}
						}
					}
				}


			}
		}




		/*for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				if (dizi[column][row] == 1) {
					dizi[column][row] = 150;
				}
			}
		}*/
									//tiketler(dizi, nesne_sayisi)
		label1->Text = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[4].ToString();
		label2->Text = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[5].ToString();
		label3->Text = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[6].ToString();
		label4->Text = etiket_sayisi.ToString();

			
			
		
		
		for (int j = 0; j < etiket_sayisi * 4; j += 4) {
		for (int i = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[0+j]; i < coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[2 + j]; i++) {
			dizi[i][coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[1 + j]] = 0;
		}
		for (int i = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[1 + j]; i < coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[3 + j]; i++) {
			dizi[coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[2 + j]][i] = 0;
		}
		for (int i = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[0 + j]; i < coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[2 + j]; i++) {
			dizi[i][coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[3 + j]] = 0;
		}
		for (int i = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[1 + j]; i < coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[3 + j]; i++) {
			dizi[coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[0 + j]][i] = 0;
		}
		}
		/////////////////////////////////////////////////////////////////////////////
		///////MOMENT
		int l = -1;
		double h7[7];
		if (Boxxx->Checked == true) {
			int w = 0;
			int h = 0;
			int meyve_sayisi = 0;
			int kontrol_sayac = 0;
			for (int i = 0; i < etiket_sayisi*4; i+=4) {
				w = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i + 2] - coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i];
				h = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i + 3] - coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i + 1];

				int* moment_karnel = new int[w*h];

				for (int row = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i + 1]; row < h; row++)
				{
					for (int column = coordinate(dizi, yenitempp, etiket_sayisi, Width, Height)[i]; column < w; column++)
					{
						// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
						moment_karnel[++l] = dizi[column][row];
					}
				}

				h7[0]=moment(moment_karnel, w, h)[0];
				h7[1]=moment(moment_karnel, w, h)[1];
				h7[2]=moment(moment_karnel, w, h)[2];
				h7[3]=moment(moment_karnel, w, h)[3];
				h7[4]=moment(moment_karnel, w, h)[4];
				h7[5]=moment(moment_karnel, w, h)[5];
				h7[6]=moment(moment_karnel, w, h)[6];
				
				/*if (Boxxx->Checked == true) {
					double kontrol[70];
					kontrol[kontrol_sayac] = h7[0];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[1];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[2];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[3];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[4];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[5];
					kontrol_sayac++;
					kontrol[kontrol_sayac] = h7[6];
					kontrol_sayac++;
					label1->Text = kontrol[0].ToString();
					label2->Text = kontrol[1].ToString();
					label3->Text = kontrol[2].ToString();
					label4->Text = kontrol[3].ToString();
				}*/
				
				std::ofstream dosya;
				dosya.open("KONTROL.txt", std::ios::app); //deneme.txt isimli bir dosya açtık.
				//dosya << meyve_sayisi << "-----------------\n";
				dosya << h7[0]<<"\n";
				dosya << h7[1] << "\n";
				dosya << h7[2] << "\n";
				dosya << h7[3] << "\n";
				dosya << h7[4] << "\n";
				dosya << h7[5] << "\n";
				dosya << h7[6] << "\n";
				meyve_sayisi++;
				
				dosya.close();
			}

			

		}
		
	////-------------------------------------------------------------------------------------------------------------------------
	 l = -1;
	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
			raw_intensity[++l] = dizi[column][row];
		}
	}
	l = -l;
		
	Color c;
	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			// c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
			c = Color::FromArgb(raw_intensity[row * Width + column], raw_intensity[row * Width + column], raw_intensity[row * Width + column]);
			surface->SetPixel(column, row, c);
		}
	}
	pictureBox1->Image = surface;
}
private: System::Void erosionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	Bitmap^ GirisResmi = gcnew Bitmap(pictureBox1->Image);
	
	Bitmap^ CikisResmi = gcnew Bitmap(GirisResmi->Width, GirisResmi->Height);
	int ResimGenisligi = GirisResmi->Width;
	int ResimYuksekligi = GirisResmi->Height;
	int SablonBoyutu = 3;
	int toplam = 0;
	Color c;

	

	for (int x = (SablonBoyutu - 1) / 2; x < ResimGenisligi - (SablonBoyutu - 1) / 2; x++)
		//Resmi taramaya şablonun yarısı kadar dış kenarlardan içeride başlayacak ve bitirecek.
	{
		for (int y = (SablonBoyutu - 1) / 2; y < ResimYuksekligi - (SablonBoyutu - 1) / 2; y++)
		{

			if (GirisResmi->GetPixel(x, y).R == 0)
			{
				toplam = GirisResmi->GetPixel(x - 1, y).R + GirisResmi->GetPixel(x, y - 1).R+ GirisResmi->GetPixel(x + 1, y).R + GirisResmi->GetPixel(x, y + 1).R;

				if (toplam != 0)
				{
					CikisResmi->SetPixel(x, y, Color::FromArgb(255, 255, 255));
				}
				else
				{
					CikisResmi->SetPixel(x, y, Color::FromArgb(0, 0, 0));
				}

			}
			else
			{
				CikisResmi->SetPixel(x, y, Color::FromArgb(255, 255, 255));
			}


		}
	}
	pictureBox1->Image = CikisResmi;
}
private: System::Void dilationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	Bitmap^ GirisResmi = gcnew Bitmap(Width, Height);
	GirisResmi = gcnew Bitmap(pictureBox1->Image);
	Bitmap^ CikisResmi = gcnew Bitmap(GirisResmi->Width, GirisResmi->Height);
	int ResimGenisligi = GirisResmi->Width;
	int ResimYuksekligi = GirisResmi->Height;
	int SablonBoyutu = 5;
	int toplam = 0;
	Color c;

	


	for (int x = (SablonBoyutu - 1) / 2; x < ResimGenisligi - (SablonBoyutu - 1) / 2; x++)
		//Resmi taramaya şablonun yarısı kadar dış kenarlardan içeride başlayacak ve bitirecek.
	{
		for (int y = (SablonBoyutu - 1) / 2; y < ResimYuksekligi - (SablonBoyutu - 1) / 2; y++)
		{

			if (GirisResmi->GetPixel(x, y).R == 255)
			{


				if (GirisResmi->GetPixel(x - 1, y).R == 0 || GirisResmi->GetPixel(x, y - 1).R == 0)
				{
					CikisResmi->SetPixel(x, y, Color::FromArgb(0, 0, 0));
				}
				else
				{
					CikisResmi->SetPixel(x, y, Color::FromArgb(255, 255, 255));
				}

			}
			else
			{
				CikisResmi->SetPixel(x, y, Color::FromArgb(0, 0, 0));
			}


		}
	}
	pictureBox1->Image = CikisResmi;

}

private: System::Void sobelToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;

	CString str;
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	int k = 3;
	double temp = 0;
	double* M = new double[9]{ 1, 2 , 1 , 2 , 4 , 2 , 1 , 2 , 1 };
	BYTE* cov = new BYTE[(Height - k - 1) * (Width - k - 1)];

	for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
		temp = 0;
		for (int j = 0; j < k; j++) {

			temp += raw_intensity[i + j] * M[j];
			temp += raw_intensity[i + j + Width] * M[j + k];
			temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
		}
		if (temp / 16 < 0)
			temp = 0;
		else if (temp / 16 > 255)
			temp = 255;
		raw_intensity[i] = temp / 16;  //   / sayi yapılabilir kesirli filtreler için
	}


	//---------------------------------------------------------------------------------
	int x = 0, y = 0;

	int xG = 0, yG = 0;

	BYTE* tempImage = new BYTE [Size];   // int* tanımlanabilir 
	for (unsigned int i = 0; i < Size; i++) {

		x = i % Width;

		if (i != 0 && x == 0) {

			y++;

		}

		if (x < (Width - 1) && y < (Height - 1)
			&& (y > 0) && (x > 0)) {

			//index = x + (y * width)
			//Finds the horizontal gradient
			xG = (raw_intensity[(x + 1) + ((y - 1) * Width)]
				+ (2 * raw_intensity[(x + 1) + (y * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x - 1) + (y * Width)])
				- raw_intensity[(x - 1) + ((y + 1) * Width)]);


			//Finds the vertical gradient
			yG = (raw_intensity[(x - 1) + ((y + 1) * Width)]
				+ (2 * raw_intensity[(x)+((y + 1) * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x)+((y - 1) * Width)])
				- raw_intensity[(x + 1) + ((y - 1) * Width)]);

			//newPixel = sqrt(xG^2 + yG^2)
			if (sqrt((xG * xG) + (yG * yG)) > 255)
				tempImage[i] = 255;
			else
				tempImage[i] = sqrt((xG * xG) + (yG * yG));

		}
		else {

			//Pads out of bound pixels with 0
			tempImage[i] = 0;

		}

	}

	
	
	Bitmap^ surface = gcnew Bitmap(Width, Height);


	Color c;
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {

			c = Color::FromArgb(tempImage[(row)*Width + col], tempImage[(row)*Width + col], tempImage[(row)*Width + col]);
			surface->SetPixel(col, row, c);
		}
	}
	pictureBox1->Image = surface;
}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cannyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;

	CString str;
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	
	int k = 5;
	double temp = 0;
	double* M = new double[25]{ 1, 4, 7, 4, 1, 4, 20, 33, 20, 4, 7, 33, 55, 33, 7, 4, 20, 33, 20, 4, 1, 4, 7, 4, 1 };
	
	BYTE* cov = new BYTE[(Height - k - 1) * (Width - k - 1)];
	for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
		temp = 0;
		for (int j = 0; j < k; j++) {

			temp += raw_intensity[i + j] * M[j];
			temp += raw_intensity[i + j + Width] * M[j + k];
			temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
		}
		if (temp / 331 < 0)
			temp = 0;
		else if (temp / 331 > 255)
			temp = 255;
		raw_intensity[i] = temp / 331;  //   / sayi yapılabilir kesirli filtreler için
	}
	//GAUS ÜÇ BOYUT
	//----------------------------------------------------------------------------------------------------------
	//int k = 3;
	//double temp = 0;
	//double* M = new double[9]{ 1, 2 , 1 , 2 , 4 , 2 , 1 , 2 , 1 };
	//BYTE* cov = new BYTE[(Height - k - 1) * (Width - k - 1)];

	//for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += raw_intensity[i + j] * M[j];
	//		temp += raw_intensity[i + j + Width] * M[j + k];
	//		temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
	//	}
	//	if (temp / 16 < 0)
	//		temp = 0;
	//	else if (temp / 16 > 255)
	//		temp = 255;
	//	raw_intensity[i] = temp / 16;  //   / sayi yapılabilir kesirli filtreler için
	//}
	//----------------------------------------------------------------------------------------------------------
	//temp = 0;
	//M = new double[9]{ -1,-1, -1, -1, 8, -1, -1, -1, -1 };
	//k = 3;
	//for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += raw_intensity[i + j] * M[j];
	//		temp += raw_intensity[i + j + Width] * M[j + k];
	//		temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
	//	}
	//	if (temp < 0)
	//		temp = 0;
	//	else if (temp > 255)
	//		temp = 255;
	//	raw_intensity[i] = temp;  //   / sayi yapılabilir kesirli filtreler için
	//}

	//---------------------------------------------------------------------------------
	int x = 0, y = 0;

	int xG = 0, yG = 0;

	BYTE* tempImage = new BYTE[Size];   // int* tanımlanabilir 
	double* tempImageYonu = new double[Size];   // int* tanımlanabilir 
	double* tempKenarYonu = new double[Size];   // int* tanımlanabilir 
	double* varsayilan = new double[Size];

	for (unsigned int i = 0; i < Size; i++) {

		x = i % Width;

		if (i != 0 && x == 0) {

			y++;

		}

		if (x < (Width - 1) && y < (Height - 1)
			&& (y > 0) && (x > 0)) {

			//index = x + (y * width)
			//Finds the horizontal gradient
			xG = (raw_intensity[(x + 1) + ((y - 1) * Width)]
				+ (2 * raw_intensity[(x + 1) + (y * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x - 1) + (y * Width)])
				- raw_intensity[(x - 1) + ((y + 1) * Width)]);


			//Finds the vertical gradient
			yG = (raw_intensity[(x - 1) + ((y + 1) * Width)]
				+ (2 * raw_intensity[(x)+((y + 1) * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x)+((y - 1) * Width)])
				- raw_intensity[(x + 1) + ((y - 1) * Width)]);

			//newPixel = sqrt(xG^2 + yG^2)
			if (xG == 0)
				xG = 1;

			if (sqrt((xG * xG) + (yG * yG)) > 255) {
				tempImage[i] = 255; 
				
				
				tempImageYonu[i] = atan(yG / xG) * 180 / PI;
				
			}
			else {
				tempImage[i] = sqrt((xG * xG) + (yG * yG));  
				if (xG == 0)
					xG = 1;
				
				tempImageYonu[i] = atan(yG / xG) * 180 / PI;
				
			}
		}
		else {

			//Pads out of bound pixels with 0
			tempImage[i] = 0;

		}

	}
	for (unsigned int i = 0; i < Size; i++) {
		tempKenarYonu[i] = tempImageYonu[i] + 90;
		if (tempKenarYonu[i] > 360)
			tempKenarYonu[i] = tempKenarYonu[i] - 360;
	}


	label1->Text = (tempImageYonu[500]).ToString();
	label2->Text = (tempImageYonu[600]).ToString();
	label3->Text = (tempImageYonu[700]).ToString();
	label4->Text = (tempImageYonu[800]).ToString();
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	

	
	//int length = 2;
	//int* Myhistogram = histogram(tempImage, &Width, &Height);
	//int* K = new int[2];
	//K = KMeans(Myhistogram, length);
	//BYTE* sonuc = binaryImage(tempImage, &Width, &Height, K);

	
	for (unsigned int i = 0; i < Size; i++) {
		varsayilan[i] = 255;
	}
	

	
	

	for (int row = 1; row < Height-1; row++) {
		for (int col = 1; col < Width-1; col++) {

			if (tempImageYonu[(row)*Width + col] <= 22.5 && tempImageYonu[(row)*Width + col] >= -22.5) { // DOĞU
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + 1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - 1])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] >= 157.5 && tempImageYonu[(row)*Width + col] <= -157.5) {  //BATI
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + 1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - 1])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] <= 112.5 && tempImageYonu[(row)*Width + col] >= 67.5) {    //KUZEY
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] >= 112.5 && tempImageYonu[(row)*Width + col] <= 67.5) {   //GÜNEY
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] >= 22.5 && tempImageYonu[(row)*Width + col] <= 67.5) {	//KUZEY DOĞU
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width-1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width+1])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] >= -157.5 && tempImageYonu[(row)*Width + col] <= -112.5) {  //GÜNEY BATI
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width - 1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width + 1])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] <= 157.5 && tempImageYonu[(row)*Width + col] >= 112.5) {  //KUZEY BATI
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width + 1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width - 1])))
					varsayilan[(row)*Width + col] = 0;
			}
			else if (tempImageYonu[(row)*Width + col] <= -22.5 && tempImageYonu[(row)*Width + col] >= -67.5) {  //GÜNEY DOĞU
				if (((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col + Width + 1])) || ((tempImage[(row)*Width + col]) < (tempImage[(row)*Width + col - Width - 1])))
					varsayilan[(row)*Width + col] = 0;
			}
		}

	}

	for (unsigned int i = 0; i < Size; i++) {
		if (varsayilan[i] == 0)
			tempImage[i] = 0;

	}

	for (unsigned int i = 0; i < Size; i++) {
		varsayilan[i] = 255;
	}
	int low = 70;  //65
	int heih = 80;  //70
	for (int row = 1; row < Height - 1; row++) {
		for (int col = 1; col < Width - 1; col++) {
			if (tempImage[(row)*Width + col] < low)
				tempImage[(row)*Width + col] = 0;
			if (tempImage[(row)*Width + col] > heih)
				tempImage[(row)*Width + col] = 255;
		
			if (tempImage[(row)*Width + col] >= low && tempImage[(row)*Width + col] <= heih) {
		
				
				if (tempKenarYonu[(row)*Width + col] <= 22.5 && tempKenarYonu[(row)*Width + col] >= -22.5) { // DOĞU
					if (( (tempImage[(row)*Width + col + 1]) >= heih) || (tempImage[(row)*Width + col - 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] >= 157.5 && tempKenarYonu[(row)*Width + col] <= -157.5) {  //BATI
					if (((tempImage[(row)*Width + col + 1]) >= heih) || (tempImage[(row)*Width + col - 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] <= 112.5 && tempKenarYonu[(row)*Width + col] >= 67.5) {    //KUZEY
					if (((tempImage[(row)*Width + col + Width] >= heih)) || ( (tempImage[(row)*Width + col - Width] >= heih)))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] >= 112.5 && tempKenarYonu[(row)*Width + col] <= 67.5) {   //GÜNEY
					if (((tempImage[(row)*Width + col + Width] >= heih)) || ((tempImage[(row)*Width + col - Width] >= heih)))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] >= 22.5 && tempKenarYonu[(row)*Width + col] <= 67.5) {	//KUZEY DOĞU
					if ((tempImage[(row)*Width + col + Width - 1] >= heih) || ( tempImage[(row)*Width + col - Width + 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] >= -157.5 && tempKenarYonu[(row)*Width + col] <= -112.5) {  //GÜNEY BATI
					if ((tempImage[(row)*Width + col + Width - 1] >= heih) || (tempImage[(row)*Width + col - Width + 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] <= 157.5 && tempKenarYonu[(row)*Width + col] >= 112.5) {  //KUZEY BATI
					if (( tempImage[(row)*Width + col + Width + 1] >= heih) || (tempImage[(row)*Width + col - Width - 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				else if (tempKenarYonu[(row)*Width + col] <= -22.5 && tempKenarYonu[(row)*Width + col] >= -67.5) {  //GÜNEY DOĞU
					if ((tempImage[(row)*Width + col + Width + 1] >= heih) || (tempImage[(row)*Width + col - Width - 1] >= heih))
						tempImage[(row)*Width + col] = 255;
					else
						tempImage[(row)*Width + col] = 0;
				}
				
				else {

					tempImage[(row)*Width + col] = 0;
				}
				
				
				
				/*	if ((tempImage[(row)*Width + col + 1] >= heih) || (tempImage[(row)*Width + col - 1] >= heih) ||
					(tempImage[(row)*Width + col + Width] >= heih) || (tempImage[(row)*Width + col - Width] >= heih) ||
					(tempImage[(row)*Width + col + Width - 1] >= heih) || (tempImage[(row)*Width + col - Width + 1] >= heih) ||
					(tempImage[(row)*Width + col + Width + 1] >= heih) || (tempImage[(row)*Width + col - Width - 1] >= heih)) {
					
					tempImage[(row)*Width + col ] = 255;
				}
				else {
				
					tempImage[(row)*Width + col ] = 0;
				}
*/

				
				
				
			}
			
			
			

			
		}
	}
	/*for (unsigned int i = 0; i < Size; i++) {
		if (tempImage[i] <= 40)
			tempImage[i] = 0;
		else if (tempImage[i] >= 40 && tempImage[i] <= 80) {

		}
	}*/
	//for (unsigned int i = 0; i < Size; i++) {
	//	
	//		tempImage[i] = varsayilan[i];

	//}

	Bitmap^ surface = gcnew Bitmap(Width, Height);
	Color c;
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {

			c = Color::FromArgb(tempImage[(row)*Width + col], tempImage[(row)*Width + col], tempImage[(row)*Width + col]);

			surface->SetPixel(col, row, c);

		}
	}
	pictureBox1->Image = surface;

}
private: System::Void hougToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;

	CString str;
	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(Width, Height, Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	
	//int k = 5;
	//double temp = 0;
	//double* M = new double[25]{ 1, 4, 7, 4, 1, 4, 20, 33, 20, 4, 7, 33, 55, 33, 7, 4, 20, 33, 20, 4, 1, 4, 7, 4, 1 };

	//BYTE* cov = new BYTE[(Height - k - 1) * (Width - k - 1)];
	//for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += raw_intensity[i + j] * M[j];
	//		temp += raw_intensity[i + j + Width] * M[j + k];
	//		temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
	//	}
	//	if (temp / 331 < 0)
	//		temp = 0;
	//	else if (temp / 331 > 255)
	//		temp = 255;
	//	raw_intensity[i] = temp / 331;  //   / sayi yapılabilir kesirli filtreler için
	//}
	//GAUS ÜÇ BOYUT
	//----------------------------------------------------------------------------------------------------------
	//int k = 3;
	//double temp = 0;
	//double* M = new double[9]{ 1, 2 , 1 , 2 , 4 , 2 , 1 , 2 , 1 };
	//BYTE* cov = new BYTE[(Height - k - 1) * (Width - k - 1)];

	//for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += raw_intensity[i + j] * M[j];
	//		temp += raw_intensity[i + j + Width] * M[j + k];
	//		temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
	//	}
	//	if (temp / 16 < 0)
	//		temp = 0;
	//	else if (temp / 16 > 255)
	//		temp = 255;
	//	raw_intensity[i] = temp / 16;  //   / sayi yapılabilir kesirli filtreler için
	//}
	//----------------------------------------------------------------------------------------------------------
	//temp = 0;
	//M = new double[9]{ -1,-1, -1, -1, 8, -1, -1, -1, -1 };
	//k = 3;
	//for (int i = 0; i < (Width - 2) * (Height - 2); i++) {
	//	temp = 0;
	//	for (int j = 0; j < k; j++) {

	//		temp += raw_intensity[i + j] * M[j];
	//		temp += raw_intensity[i + j + Width] * M[j + k];
	//		temp += raw_intensity[i + j + Width + Width] * M[j + k + k];
	//	}
	//	if (temp < 0)
	//		temp = 0;
	//	else if (temp > 255)
	//		temp = 255;
	//	raw_intensity[i] = temp;  //   / sayi yapılabilir kesirli filtreler için
	//}

	//---------------------------------------------------------------------------------
	int x = 0, y = 0;

	int xG = 0, yG = 0;

	BYTE* tempImage = new BYTE[Size];   // int* tanımlanabilir 
	double* tempImageYonu = new double[Size];   // int* tanımlanabilir 
	double* tempKenarYonu = new double[Size];   // int* tanımlanabilir 
	double* varsayilan = new double[Size];

	for (unsigned int i = 0; i < Size; i++) {

		x = i % Width;

		if (i != 0 && x == 0) {

			y++;

		}

		if (x < (Width - 1) && y < (Height - 1)
			&& (y > 0) && (x > 0)) {

			//index = x + (y * width)
			//Finds the horizontal gradient
			xG = (raw_intensity[(x + 1) + ((y - 1) * Width)]
				+ (2 * raw_intensity[(x + 1) + (y * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x - 1) + (y * Width)])
				- raw_intensity[(x - 1) + ((y + 1) * Width)]);


			//Finds the vertical gradient
			yG = (raw_intensity[(x - 1) + ((y + 1) * Width)]
				+ (2 * raw_intensity[(x)+((y + 1) * Width)])
				+ raw_intensity[(x + 1) + ((y + 1) * Width)]
				- raw_intensity[(x - 1) + ((y - 1) * Width)]
				- (2 * raw_intensity[(x)+((y - 1) * Width)])
				- raw_intensity[(x + 1) + ((y - 1) * Width)]);

			//newPixel = sqrt(xG^2 + yG^2)
			if (xG == 0)
				xG = 1;

			if (sqrt((xG * xG) + (yG * yG)) > 255) {
				tempImage[i] = 255;


				tempImageYonu[i] = atan(yG / xG) * 180 / PI;
				if (tempImageYonu[i] < 360)
					tempImageYonu[i] = tempImageYonu[i] + 360;
				if (tempImageYonu[i] > 360)
					tempImageYonu[i] = tempImageYonu[i] - 360;

			}
			else {
				tempImage[i] = sqrt((xG * xG) + (yG * yG));
				if (xG == 0)
					xG = 1;

				tempImageYonu[i] = atan(yG / xG) * 180 / PI;
				if (tempImageYonu[i] < 360)
					tempImageYonu[i] = tempImageYonu[i] + 360;
				if (tempImageYonu[i] > 360)
					tempImageYonu[i] = tempImageYonu[i] - 360;

			}
		}
		else {

			//Pads out of bound pixels with 0
			tempImage[i] = 0;

		}

	}
	int H[360][500];

	for (int row = 0; row < 360; row++) {
		for (int col = 0; col < 500; col++) {
			H[row][col] = 0;

		}
	}
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {
			{
				if (raw_intensity[(row)*Width + col] == 255) {
					int d = col * cos(tempImageYonu[(row)*Width + col]) + row * sin(tempImageYonu[(row)*Width + col]);
					
					H[(int)tempImageYonu[(row)*Width + col]][d]++;
				}


			}

		}
	}
	int buyuk = 0;
	int xteta = 0;
	int yd = 0;
	
	for (int row = 0; row < 360; row++) {
		for (int col = 0; col < 500; col++) {
			if (H[row][col] > buyuk) {
				buyuk = H[row][col];
				xteta = row;
				yd = col;
			}
				

		}
	}
	int xx = 0;
	int yy = 0;
	xteta = -1 * (1 /tan(xteta));
	xx = yd * cos(xteta);
	yy = yd * sin(xteta);
	
	for (unsigned int i = 0; i < Width; i++) {
	
			//xteta* (i - x) + y;
			
		raw_intensity[(xteta * (i - xx) + yy) * Width + i] == 0;
	}

	Bitmap^ surface = gcnew Bitmap(Width, Height);
	Color c;
	for (int row = 0; row < Height; row++) {
		for (int col = 0; col < Width; col++) {

			c = Color::FromArgb(raw_intensity[(row)*Width + col], raw_intensity[(row)*Width + col], raw_intensity[(row)*Width + col]);

			surface->SetPixel(col, row, c);

		}
	}
	pictureBox1->Image = surface;
}
//private: System::Void hhhhhToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
//
//	std::ifstream elma("elma.txt");
//	
//	double delma[140];
//	int i = 0;
//	if (elma.is_open()) {
//		while (elma >> delma[i]) {
//			i++;										
//		}
//	}
//	
//	for (int k = 7; k < i; k+=7) {
//		delma[0] += delma[0 + k];
//		delma[1] += delma[1 + k];
//		delma[2] += delma[2 + k];
//		delma[3] += delma[3 + k];
//		delma[4] += delma[4 + k];
//		delma[5] += delma[5 + k];
//		delma[6] += delma[6 + k];
//
//	}
//	delma[0] = delma[0] / (i / 7);
//	delma[1] = delma[1] / (i / 7);
//	delma[2] = delma[2] / (i / 7);
//	delma[3] = delma[3] / (i / 7);
//	delma[4] = delma[4] / (i / 7);
//	delma[5] = delma[5] / (i / 7);
//	delma[6] = delma[6] / (i / 7);
//	i = 0;
//
//	//KARPUZ
//	std::ifstream karpuz("karpuz.txt");
//	
//	double dkarpuz[140];
//	
//	if (karpuz.is_open()) {
//		while (karpuz >> dkarpuz[i]) {
//			i++;
//		}
//	}
//
//	for (int k = 7; k < i; k += 7) {
//		dkarpuz[0] += dkarpuz[0 + k];
//		dkarpuz[1] += dkarpuz[1 + k];
//		dkarpuz[2] += dkarpuz[2 + k];
//		dkarpuz[3] += dkarpuz[3 + k];
//		dkarpuz[4] += dkarpuz[4 + k];
//		dkarpuz[5] += dkarpuz[5 + k];
//		dkarpuz[6] += dkarpuz[6 + k];
//
//	}
//	dkarpuz[0] = dkarpuz[0] / (i / 7);
//	dkarpuz[1] = dkarpuz[1] / (i / 7);
//	dkarpuz[2] = dkarpuz[2] / (i / 7);
//	dkarpuz[3] = dkarpuz[3] / (i / 7);
//	dkarpuz[4] = dkarpuz[4] / (i / 7);
//	dkarpuz[5] = dkarpuz[5] / (i / 7);
//	dkarpuz[6] = dkarpuz[6] / (i / 7);
//	i = 0;
//
//	//KİRAZ
//	std::ifstream kiraz("kiraz.txt");
//
//	double dkiraz[140];
//
//	if (kiraz.is_open()) {
//		while (kiraz >> dkiraz[i]) {
//			i++;
//		}
//	}
//
//	for (int k = 7; k < i; k += 7) {
//		dkiraz[0] += dkiraz[0 + k];
//		dkiraz[1] += dkiraz[1 + k];
//		dkiraz[2] += dkiraz[2 + k];
//		dkiraz[3] += dkiraz[3 + k];
//		dkiraz[4] += dkiraz[4 + k];
//		dkiraz[5] += dkiraz[5 + k];
//		dkiraz[6] += dkiraz[6 + k];
//
//	}
//	dkiraz[0] = dkiraz[0] / (i / 7);
//	dkiraz[1] = dkiraz[1] / (i / 7);
//	dkiraz[2] = dkiraz[2] / (i / 7);
//	dkiraz[3] = dkiraz[3] / (i / 7);
//	dkiraz[4] = dkiraz[4] / (i / 7);
//	dkiraz[5] = dkiraz[5] / (i / 7);
//	dkiraz[6] = dkiraz[6] / (i / 7);
//	i = 0;
//	//MUZ
//	std::ifstream muz("muz.txt");
//
//	double dmuz[140];
//
//	if (muz.is_open()) {
//		while (muz >> dmuz[i]) {
//			i++;
//		}
//	}
//
//	for (int k = 7; k < i; k += 7) {
//		dmuz[0] += dmuz[0 + k];
//		dmuz[1] += dmuz[1 + k];
//		dmuz[2] += dmuz[2 + k];
//		dmuz[3] += dmuz[3 + k];
//		dmuz[4] += dmuz[4 + k];
//		dmuz[5] += dmuz[5 + k];
//		dmuz[6] += dmuz[6 + k];
//
//	}
//	dmuz[0] = dmuz[0] / (i / 7);
//	dmuz[1] = dmuz[1] / (i / 7);
//	dmuz[2] = dmuz[2] / (i / 7);
//	dmuz[3] = dmuz[3] / (i / 7);
//	dmuz[4] = dmuz[4] / (i / 7);
//	dmuz[5] = dmuz[5] / (i / 7);
//	dmuz[6] = dmuz[6] / (i / 7);
//	i = 0;
//	//ÜZÜM
//	std::ifstream uzum("uzum.txt");
//
//	double duzum[140];
//
//	if (uzum.is_open()) {
//		while (uzum >> duzum[i]) {
//			i++;
//		}
//	}
//
//	for (int k = 7; k < i; k += 7) {
//		duzum[0] += duzum[0 + k];
//		duzum[1] += duzum[1 + k];
//		duzum[2] += duzum[2 + k];
//		duzum[3] += duzum[3 + k];
//		duzum[4] += duzum[4 + k];
//		duzum[5] += duzum[5 + k];
//		duzum[6] += duzum[6 + k];
//
//	}
//	duzum[0] = duzum[0] / (i / 7);
//	duzum[1] = duzum[1] / (i / 7);
//	duzum[2] = duzum[2] / (i / 7);
//	duzum[3] = duzum[3] / (i / 7);
//	duzum[4] = duzum[4] / (i / 7);
//	duzum[5] = duzum[5] / (i / 7);
//	duzum[6] = duzum[6] / (i / 7);
//	i = 0;
//
//	std::ifstream detec("KONTROL.txt");
//
//	double ddetec[140];
//	if (detec.is_open()) {
//		while (detec >> ddetec[i]) {
//			i++;
//		}
//	}
//	double oelma[7] ;
//	double okarpuz[7] ;
//	double okiraz[7] ;
//	double omuz[7] ;
//	double ouzum[7] ;
//
//	for (int k = 0; k < 7; k++) {
//		oelma[k] =(ddetec[k]) - ( delma[k]);
//		okarpuz[k] = ( ddetec[k]) -(dkarpuz[k]);
//		okiraz[k] = (ddetec[k]) - (dkiraz[k]);
//		omuz[k] = (ddetec[k]) - (dmuz[k]);
//		ouzum[k] =( ddetec[k]) - (duzum[k]);
//	}
//	//for (int k = 1; k < 7; k++) {
//	//	oelma[0] = oelma[0] + oelma[k];
//	//	
//	//}
//	//for (int k = 1; k < 7; k++) {
//	//	okarpuz[0] = okarpuz[0] + okarpuz[k];
//
//	//}for (int k = 1; k < 7; k++) {
//	//	okiraz[0] = okiraz[0] + okiraz[k];
//
//	//}for (int k = 1; k < 7; k++) {
//	//	omuz[0] = omuz[0] + omuz[k];
//	//}
//	//for (int k = 1; k < 7; k++) {
//	//	ouzum[0] = ouzum[0] + ouzum[k];
//	//}
//	label1->Text = oelma[6].ToString();
//	label2->Text = okarpuz[6].ToString();
//	label3->Text = okiraz[6].ToString();
//	label4->Text = omuz[6].ToString();
//}



};
}