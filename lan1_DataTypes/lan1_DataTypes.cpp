#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Дворкин Дмитрий 211-331";

	cout << "int " << sizeof(int) << ", min int = " << int(0b10000000000000000000000000000000) << ", max int = " << 0b01111111111111111111111111111111 << ", min unsigned int " << 0 << ", max unsigned int " << 0b11111111111111111111111111111111 << ", size of unsidned int " << sizeof(int);
	cout << endl << "double " << sizeof(double) << ", min double = " << -double(0b1000000000000000000000000000000000000000000000000000000000000000) << ", max double = " << 0b111111111111111111111111111111111111111111111111111111111111111;
	cout << endl << "char " << sizeof(char) << ", min char = " << 0 << ", max char = " << 0b11111111;
	cout << endl << "bool " << sizeof(bool) << ", min bool = " << 0 << ", max bool = " << 0b11111111;
	cout << endl << "short " << sizeof(short) << ", min short = " << short(0b1000000000000000) << ", max short = " << 0b111111111111111 << ", min unsigned short " << 0 << ", max unsigned short " << 0b1111111111111111 << ", size of unsidned short " << sizeof(short);
	cout << endl << "long long " << sizeof(long long) << ", min long long = " << long(long(0b1000000000000000000000000000000000000000000000000000000000000000)) << ", max long long = " << 0b111111111111111111111111111111111111111111111111111111111111111;
	cout << endl << "long " << sizeof(long) << ", min long = " << -long(0b10000000000000000000000000000000) << ", max long = " << 0b1111111111111111111111111111111;

	int chislo;
	cout << "Введите число ";
	cin >> chislo;
	cout << endl << "Binary: ";
	bitset <8 * sizeof(chislo)> g(chislo);
	cout << g;
	cout << endl << "Hex: " << hex << chislo;
	cout << endl << "Char: " << char(chislo);
	cout << endl << "Bool: " << bool(chislo);
	cout << endl << "Double: " << double(chislo);

	int a, b;
	cout << "Введите значения переменных: ";
	cin >> a >> b;
	cout << endl << a << " * x = " << b;
	cout << endl << "x=" << b << "/" << a;
	cout << endl << "x=" << b / a;
	int x, y;
	cout << "Введите координаты концевых точек: ";
	cin >> x >> y;
	cout << endl << "Серединой отрезка будет точка: " << (x + y) / 2.0;
	return 0;
}