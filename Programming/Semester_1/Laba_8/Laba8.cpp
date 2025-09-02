#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int salaries[12];

    double all_salary = 0;
    for (int i = 0; i < end(salaries) - begin(salaries); i++) {
        salaries[i] = 1 + rand() % 5;
        all_salary += salaries[i];

        cout << salaries[i] << endl;
    }

    cout << "--------------------" << endl;

    int number_best_quarter = 0;
    double best_qurter = 0;
    double quater_salary = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            quater_salary += salaries[i * 3 + j];
            if (quater_salary > best_qurter) {
                best_qurter = quater_salary;
                number_best_quarter = i + 1;
            }
        }
        quater_salary = 0;
    }


    cout << "Средняя зарплата: " << all_salary / 12 << endl;
    cout << "Лучший квартал: " << number_best_quarter << endl;
}