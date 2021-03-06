#include "stdafx.h"
#include "dllrel.h"
#include <iostream>
#include <windows.h>



class Complex : public ParComplex
{
private:
	float re;
	float im;
public:
	Complex()
	{
		re = 0;
		im = 0;
	}
	Complex(float x, float y)
	{
		re = x;
		im = y;
	}
	~Complex()
	{
	}
	void Delete()
	{
		delete this;
	}
	void Out()
	{
		std::cout << re;
		if (im > 0) std::cout << "+";
		if (im != 0) std::cout << im << "i\n";
	}
	void Sopr()
	{
		im = im * (-1);
	}
	float GetRe()
	{
		return re;
	}
	float GetIm()
	{
		return im;
	}
	void SetReIm(float a, float b)
	{
		re = a;
		im = b;
	}
	ParComplex* Plus(ParComplex* B)
	{
		ParComplex* C = new Complex;
		C->SetReIm(GetRe() + B->GetRe(), GetIm() + B->GetIm());
		return C;
	}
	virtual ParComplex* Plus(float B)
	{
		ParComplex* C = new Complex;
		C->SetReIm(GetRe() + B, GetIm());
		return C;
	}
	ParComplex* Minus(ParComplex* B)
	{
		ParComplex* C = new Complex;
		C->SetReIm(GetRe() - B->GetRe(), GetIm() - B->GetIm());
		return C;
	}
	ParComplex* Minus(float B)
	{
		ParComplex* C = new Complex;
		C->SetReIm(GetRe() - B, GetIm());
		return C;
	}
	ParComplex* Multiply(ParComplex* B)
	{
		ParComplex* C = new Complex;
		C->SetReIm((GetRe()*B->GetRe()) - (GetIm()*B->GetIm()), ((GetRe()*B->GetIm()) + (GetIm()*B->GetRe())));
		return C;
	}
	ParComplex* Multiply(float B)
	{
		ParComplex* C = new Complex;
		C->SetReIm((GetRe()*B), (GetIm()*B));
		return C;
	}
	ParComplex* Divide(ParComplex* B)
	{
		ParComplex* C = new Complex;
		float x, y;
		x = ((GetRe()*B->GetRe() + GetIm()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		y = ((GetIm()*B->GetRe() - GetRe()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		C->SetReIm(x, y);
		return C;
	}
	ParComplex* Divide(float B)
	{
		ParComplex* C = new Complex;
		C->SetReIm((GetRe()*B) / (B*B), (GetIm()*B) / (B*B));
		return C;
	}
};

extern "C" __declspec(dllexport) ParComplex* __cdecl CreateClass()
{
	ParComplex* A = new Complex;
	return A;
}
