
#include <iostream>
#include <windows.h>
#include "dllrel.h"

using namespace std;

typedef ParComplex* (__cdecl *ParComplex_factory)();

void main()
{
	setlocale(LC_ALL, "");
	HINSTANCE hmodule = LoadLibrary("dllrel.dll");
	if (!hmodule)
	{
		std::cout << "Failed to Load Library!\n";
		return;
	}
	ParComplex_factory CreateClass = reinterpret_cast<ParComplex_factory>(GetProcAddress(hmodule, "CreateClass"));
	if (!CreateClass)
	{
		std::cout << "Failed to Find Factory!\n";
		FreeLibrary(hmodule);
		return;
	}
	ParComplex* one = CreateClass();
	ParComplex* two = CreateClass();
	ParComplex* res = CreateClass();
	int re = 0;
	int im = 0;
	cout << "Re:";  cin >> re;
	cout << "Im:";  cin >> im;
	one->SetReIm(re, im);
	cout << "Первое число:";
	one->Out();
	cout << "Re:";  cin >> re;
	cout << "Im:";  cin >> im;
	two->SetReIm(re, im);
	std::cout << "Второе число:";
	two->Out();
	cout << "Сложение:";
	res = one->Plus(two); res->Out();
	cout << "Вычитание:";
	res = one->Minus(two); res->Out();
	cout << "Умножение:";
	res =one->Multiply(two); res->Out();
	cout << "Деление:";
	res = one->Divide(two);res->Out();
	one->Delete();
	two->Delete();
	res->Delete();
	FreeLibrary(hmodule);
	system("pause");
}