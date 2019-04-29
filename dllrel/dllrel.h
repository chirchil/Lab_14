#pragma once

class ParComplex
{
public:
	virtual void Out() = 0;//вывод на экран
	virtual void Sopr() = 0; // сопреженное число
	virtual void SetReIm(float a, float b) = 0; //задать параметры
	virtual float GetRe() = 0;// получить действ часть
	virtual float GetIm() = 0;//получить мнимую часть
	virtual ParComplex* Plus(ParComplex* B) = 0;//сложение с комплексным числом
	virtual ParComplex* Plus(float B) = 0;//сложение с вещ числом
	virtual ParComplex* Minus(ParComplex* B) = 0;//вычитание с комплексным числом
	virtual ParComplex* Minus(float B) = 0;//вычитание с вещ числом
	virtual ParComplex* Multiply(ParComplex* B) = 0;//умножение на комплексное число
	virtual ParComplex* Multiply(float B) = 0;//умножение на вещественное число
	virtual ParComplex* Divide(ParComplex* B) = 0;//деление на комплексное число
	virtual ParComplex* Divide(float B) = 0;//деление на вещ число
	virtual void Delete() = 0; //удаление класса
};