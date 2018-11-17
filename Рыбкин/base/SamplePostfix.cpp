#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	string expression;
	double res;
	//setlocale(LC_ALL, "Russian");
	cout << "Enter arithmetic expression without spaces: ";
	getline(cin, expression);
	//cout << expression << endl;
	TPostfix postfix(expression);
	cout << "Postfix form: " << postfix.GetPostfix() << endl;
	res = postfix.Calculate();
	cout <<"Calculation result: "<< res << endl;
	system("pause");
	return 0;
}
