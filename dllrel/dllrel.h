#pragma once

class ParComplex
{
public:
	virtual void Out() = 0;//����� �� �����
	virtual void Sopr() = 0; // ����������� �����
	virtual void SetReIm(float a, float b) = 0; //������ ���������
	virtual float GetRe() = 0;// �������� ������ �����
	virtual float GetIm() = 0;//�������� ������ �����
	virtual ParComplex* Plus(ParComplex* B) = 0;//�������� � ����������� ������
	virtual ParComplex* Plus(float B) = 0;//�������� � ��� ������
	virtual ParComplex* Minus(ParComplex* B) = 0;//��������� � ����������� ������
	virtual ParComplex* Minus(float B) = 0;//��������� � ��� ������
	virtual ParComplex* Multiply(ParComplex* B) = 0;//��������� �� ����������� �����
	virtual ParComplex* Multiply(float B) = 0;//��������� �� ������������ �����
	virtual ParComplex* Divide(ParComplex* B) = 0;//������� �� ����������� �����
	virtual ParComplex* Divide(float B) = 0;//������� �� ��� �����
	virtual void Delete() = 0; //�������� ������
};