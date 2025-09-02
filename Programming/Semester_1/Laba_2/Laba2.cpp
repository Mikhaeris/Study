#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES
M_PI
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    double x;

    cout << "Введите x: ";
    cin >> x;

    if (x <= 1)
        cout << "Ответ при x <= 1: " << (-3) * pow(x, 3) + 9 << endl;
    if (1 < x < 10)
        cout << "Ответ при 1 < x < 10: " << -(3 / (x + 1)) << endl;
    if ( x >= 10)
        cout << "Ответ при x >= 10: " << -sin(2 * M_PI * x) + cos(3 * M_PI * x) << endl;

    return 0;
}