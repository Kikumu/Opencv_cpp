// Hello opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "windows.h"
#include <iostream>

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//HWND hwnd = GetConsoleWindow();
	//wstring my_str = L"Apex Legends";
	LPCWSTR wide_string = NULL;
	wide_string = L"Origin";
	HWND hwnd = ::FindWindow(NULL, wide_string);
	ShowWindow(hwnd, (SW_MAXIMIZE));
	Sleep(1000);

	int x1, y1, x2, y2, w, h;

	x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
	y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
	x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);

	w = x2 - x1;
	h = y2 - y1;
	HDC hscreen = GetDC(hwnd); //source dc
	HDC hDc = CreateCompatibleDC(hscreen); //memory dc?
	//hCaptureB
	/*cout << w;
	cout << "\n";
	cout << h;*/
	HBITMAP hBitmap = CreateCompatibleBitmap(hscreen, w, h);
	HGDIOBJ old_obj = SelectObject(hDc, hBitmap);
	BOOL bRet = BitBlt(hDc, 0, 0, w, h, hscreen, x1, y1, SRCCOPY);
	/*if (bRet == FALSE)
	{
		cout << "YES";
		cout << "\n";

	}*/

	//BOOL bRet = BitBlt(hDc, x1, y1, x2, y2, hscreen, w, h, SRCCOPY);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hBitmap);

	CloseClipboard();
	//String windowName = "My HelloWorld Window"; //Name of the window
	//namedWindow(windowName); // Create a window
	//imshow(windowName, hscreen); // Show our image inside the created window.
	//waitKey(0); // Wait for any keystroke in the window
	//destroyWindow(windowName); //destroy the created window

	return 0;
}