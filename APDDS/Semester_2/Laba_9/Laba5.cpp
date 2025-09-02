#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int M = 5;
    const double V = 10.0;
    const int T0 = 30;
    const int minutesPerDay = 1440;

    double ti;
    cout << "Введите среднее время ремонта одного изделия (в минутах): ";
    cin >> ti;

    double serviceRatePerMaster = minutesPerDay / ti;
    double totalServiceRate = M * serviceRatePerMaster;

    double delta = V - totalServiceRate;
    double queue = (delta > 0) ? (delta * T0) : 0;

    cout << fixed << setprecision(2);
    cout << "\nОбщая сервисная способность предприятия: " << totalServiceRate << " изделий/сутки" << endl;
    cout << "Накопление изделий в очереди за " << T0 << " дней: " << queue << " изделий" << endl;

    return 0;
}
