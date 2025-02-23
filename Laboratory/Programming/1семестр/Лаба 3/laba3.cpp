#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double x;

    cout << "Введите x: ";
    cin >> x;

    if (x <= 1)
        cout << "Ответ при x <= 1: " << (-3) * pow(x, 3) + 9 << endl;
    else if (x < 10)
        cout << "Ответ при 1 < x < 10: " << -(3 / (x + 1)) << endl;
    else
        cout << "Ответ при x >= 10: " << sin(2 * M_PI * x) + cos(3 * M_PI * x) << endl;

    return 0;
}

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	setlocale(LC_ALL, "Russian");
//
//	double x, y;
//
//	cout << "Введите значение координаты x= "; cin >> x;
//	cout << "Введите значение координаты y= "; cin >> y;
//
//	bool circle1 = (pow((x + 1), 2) + pow((y - 1), 2)) >= 1;
//	bool circle2 = (pow((x - 1), 2) + pow((y + 1), 2)) >= 1;
//
//	bool line1 = (y <= -x + 1.415);
//	bool line2 = (y >= -x - 1.415);
//
//	bool line3 = (y >= x - 2);
//	bool line4 = (y <= x + 2);
//
//	bool hit = line1 && line2 && line3 && line4 && circle1 && circle2;
//
//	if (hit) {
//		cout << "Попадает" << endl;
//	}
//	else {
//		cout << "Не попадает" << endl;
//	}
//
//	return 0;
//}