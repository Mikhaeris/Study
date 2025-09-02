#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, a;
	double x, y, xn, xk, h;

	cout << "Введите n: "; cin >> n;
	cout << "Введите a: "; cin >> a;
	cout << "Введите xn: "; cin >> xn;
	cout << "Введите xk: "; cin >> xk;

	h = (xk - xn) / n;
	x = xn;

	cout << "\tx" << "\tf(x)" << endl;

	for (int i = 0; i <= n; i++)
	{
		y = (sin(a * x) + pow(sin(a), 2)) / (4 + pow(sin(x), 2));
		cout.width(9);
		cout.precision(3);
		cout << fixed << x << "\t" << y << endl;
		x = x + h;
	}

	system("pause");
	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	long long result = 1;
//	int temp = 0;
//
//	for (int i = 1; i <= 10; i++) {
//		temp += i;
//		result *= temp;
//	}
//
//	cout << "Ответ: " << result << endl;
//
//	system("pause");
//	return 0;
//}