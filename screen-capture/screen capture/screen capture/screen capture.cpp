// Hello opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "windows.h"
#include <iostream>
#include <atlimage.h>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
//#include "hwndToMatConversion.h"


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//HWND hwnd = GetConsoleWindow();
	LPCWSTR wide_string = NULL;
	wide_string = L"Window name";

	HWND hwnd = ::FindWindow(NULL, wide_string);
	//ShowWindow(hwnd, (SW_MAXIMIZE));
	Sleep(1000);

	int x1, y1, x2, y2, w, h;

	x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
	y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
	x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);

	//currently outo adjusted to full screen. Tweak here
	w = x2 - x1; //screen width
	h = y2 - y1; //screen height

	HDC hscreen = GetDC(hwnd); //source dc
	HDC hDc = CreateCompatibleDC(hscreen); //memory dc

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	Mat src;
	src.create(h, w, CV_8UC4);

	BITMAPINFOHEADER  bitInfo;
	bitInfo.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
	bitInfo.biWidth = w;
	bitInfo.biHeight = -h;  //this is the line that makes it draw upside down or not
	bitInfo.biPlanes = 1;
	bitInfo.biBitCount = 32;
	bitInfo.biCompression = BI_RGB;
	bitInfo.biSizeImage = 0;
	bitInfo.biXPelsPerMeter = 0;
	bitInfo.biYPelsPerMeter = 0;
	bitInfo.biClrUsed = 0;
	bitInfo.biClrImportant = 0;

	HBITMAP hBitmap = CreateCompatibleBitmap(hscreen, w, h); //changed this value. cREATES BITMAP SIZE ACCORDING TO VARIABLES SET
	HGDIOBJ old_obj = SelectObject(hDc, hBitmap);
	BOOL bRet = BitBlt(hDc, 0, 0, w, h, hscreen, x1, y1, SRCCOPY);
	//StretchBlt(hDc, 0, 0, x1, y1, hscreen, 0, 0, w, h, SRCCOPY);
	GetDIBits(hDc, hBitmap, 0, h, src.data, (BITMAPINFO *)&bitInfo, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow
	imshow("Displaysrc", src);

	//HGDIOBJ old_obj = SelectObject(hDc, hBitmap);
	//BOOL bRet = BitBlt(hDc, 0, 0, w, h, hscreen, x1, y1, SRCCOPY);
	//BOOL bRet = BitBlt(hDc, x1, y1, x2, y2, hscreen, w, h, SRCCOPY);
	BITMAP bitmap;
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);
	CImage image;
	image.Attach(hBitmap);
	image.Save(L"filename1.png");
	waitKey(0);
	destroyWindow("Displaysrc"); //destroy the created window
	DeleteObject(hBitmap); DeleteDC(hDc); ReleaseDC(hwnd, hscreen);
	return 0;

	//String windowName = "My HelloWorld Window"; //Name of the window
	//namedWindow(windowName); // Create a window
	//imshow(windowName, hscreen); // Show our image inside the created window.
	//waitKey(0); // Wait for any keystroke in the window
	//destroyWindow(windowName); //destroy the created window

	return 0;
}