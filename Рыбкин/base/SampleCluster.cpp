#include <iostream>
#include <string>
#include "cluster.h"
#include <fstream>

using namespace std;

void PrintOut(Cluster &test)
{
	cout << "Количество ядер: " << test.number_cores << endl;
	cout << "Время моделирования в тактах: " << test.number_cycle << endl;
	cout << "Количество поступивших программ: " << test.number_programs << endl;
	cout << "Количество выполненных программ: " << test.number_finish_program << "%" << endl;
	cout << "Количество отказов из-за нехватки ядер: " << test.number_refusal << "%" << endl;
	cout << "Количество отказов из-за переполнения очереди: " << test.number_refusal_queue << "%" << endl;
	cout << "Количество программ, оставшихся в очереди: " << test.program_queue << endl;
	cout << "Среднее время выполнения 1 программы: " << test.average_time << endl;
}
void SaveOut(Cluster &test)
{
	ofstream file;
	file.open("cluster.txt");
	if (!file.is_open())
		cout << "Ошибка открытия" <<endl;
	else
	{
		file << "Количество ядер: " << test.number_cores << endl;
		file << "Время моделирования в тактах: " << test.number_cycle << endl;
		file << "Количество поступивших программ: " << test.number_programs << endl;
		file << "Количество выполненных программ: " << test.number_finish_program << "%" << endl;
		file << "Количество отказов из-за нехватки ядер: " << test.number_refusal << "%" << endl;
		file << "Количество отказов из-за переполнения очереди: " << test.number_refusal_queue << "%" << endl;
		file << "Количество программ, оставшихся в очереди: " << test.program_queue << endl;
		file << "Среднее время выполнения 1 программы: " << test.average_time << endl;
	}
	file.close();
}
void Out(Cluster &test)
{
	int a;
	bool flag = true;
	while (flag)
	{
		cout << "Как вывести результат? " << endl;
		cout << "1. На консоль." << endl;
		cout << "2. Записать в файл." << endl;
		cout << "3. Вывести на консоль и записать в файл." << endl;
		cin >> a;
		switch (a)
		{
		case 1:PrintOut(test); flag = false; break;
		case 2:SaveOut(test); flag = false; break;
		case 3:PrintOut(test); SaveOut(test); flag = false; break;
		default: cout << "Не верный ввод, повторите." << endl; break;
		}
	}
}
void Input(double &per, int &cyc, int &cor)
{
	cout << "Введите количество ядер: ";
	cin >> cor;
	cout << endl;
	cout << "Введите время моделирования в циклах: ";
	cin >> cyc;
	cout << endl;
	cout << "Введите интенсивность потока дробным числом от 0 до 1: ";
	while (true)
	{
		cin >> per;
		if (per >= 0 && per <= 1)
			break;
		else
			cout << "Вы ввели не верно, повторите ввод: ";
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
