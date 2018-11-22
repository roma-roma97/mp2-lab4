#include <iostream>
#include <string>
#include "cluster.h"
#include <fstream>

using namespace std;

void PrintOut(Cluster &test)
{
	cout << "���������� ����: " << test.number_cores << endl;
	cout << "����� ������������� � ������: " << test.number_cycle << endl;
	cout << "���������� ����������� ��������: " << test.number_programs << endl;
	cout << "���������� ����������� ��������: " << test.number_finish_program << "%" << endl;
	cout << "���������� ������� ��-�� �������� ����: " << test.number_refusal << "%" << endl;
	cout << "���������� ������� ��-�� ������������ �������: " << test.number_refusal_queue << "%" << endl;
	cout << "���������� ��������, ���������� � �������: " << test.program_queue << endl;
	cout << "������� ����� ���������� 1 ���������: " << test.average_time << endl;
}
void SaveOut(Cluster &test)
{
	ofstream file;
	file.open("cluster.txt");
	if (!file.is_open())
		cout << "������ ��������" <<endl;
	else
	{
		file << "���������� ����: " << test.number_cores << endl;
		file << "����� ������������� � ������: " << test.number_cycle << endl;
		file << "���������� ����������� ��������: " << test.number_programs << endl;
		file << "���������� ����������� ��������: " << test.number_finish_program << "%" << endl;
		file << "���������� ������� ��-�� �������� ����: " << test.number_refusal << "%" << endl;
		file << "���������� ������� ��-�� ������������ �������: " << test.number_refusal_queue << "%" << endl;
		file << "���������� ��������, ���������� � �������: " << test.program_queue << endl;
		file << "������� ����� ���������� 1 ���������: " << test.average_time << endl;
	}
	file.close();
}
void Out(Cluster &test)
{
	int a;
	bool flag = true;
	while (flag)
	{
		cout << "��� ������� ���������? " << endl;
		cout << "1. �� �������." << endl;
		cout << "2. �������� � ����." << endl;
		cout << "3. ������� �� ������� � �������� � ����." << endl;
		cin >> a;
		switch (a)
		{
		case 1:PrintOut(test); flag = false; break;
		case 2:SaveOut(test); flag = false; break;
		case 3:PrintOut(test); SaveOut(test); flag = false; break;
		default: cout << "�� ������ ����, ���������." << endl; break;
		}
	}
}
void Input(double &per, int &cyc, int &cor)
{
	cout << "������� ���������� ����: ";
	cin >> cor;
	cout << endl;
	cout << "������� ����� ������������� � ������: ";
	cin >> cyc;
	cout << endl;
	cout << "������� ������������� ������ ������� ������ �� 0 �� 1: ";
	while (true)
	{
		cin >> per;
		if (per >= 0 && per <= 1)
			break;
		else
			cout << "�� ����� �� �����, ��������� ����: ";
	}
	cout << endl;
}

int main()
{
	int cor, cyc;
	double per;
	setlocale(LC_ALL, "rus");
	Input(per, cyc, cor);
	Cluster test(per, cyc, cor);
	test.Start(per);
	Out(test);
	system("pause");
}
