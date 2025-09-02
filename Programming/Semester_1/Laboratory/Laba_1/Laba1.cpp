#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    double X, A;

    cout << "Введите X (кг конфет):";
    cin >> X;
    cout << "Введите A (стоимость X кг конфет):";
    cin >> A;

    cout << "Стоимость 1 кг конфет: " << A / X << endl;

    double Y;

    cout << "Введите Y (кг конфет):";
    cin >> Y;

    cout << "Стоимость " << Y << " (кг конфет): " << (A / X) * Y << endl;

    return 0;
}