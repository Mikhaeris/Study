#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double m, xn, xk, n, h;
	cout << "введите m: "; cin >> m;
	cout << "введите xn: "; cin >> xn;
	cout << "введите xk: "; cin >> xk;
	cout << "введите n: "; cin >> n;

	h = (xk - xn) / n;

	cout << "\tx" << "\tf(x)" << endl;

	double s = 0, s1 = 0, s2 = 0;
	for (double x = xn; x <= xk; x += h) {

		s1 = 0;
		for (int k = 1; k <= m; k++) {
			s1 *= x + k;
		}

		s2 = 0;
		for (int j = 1; j <= m; j++) {
			s2 += pow(j, 3);
		}

		s = 2 * pow(x, 2) + s1 + x * s2 + 2;

		cout.width(9);
		cout.precision(3);
		cout << fixed << x << "\t" << s << endl;
	}

	return 0;
}

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//    setlocale(LC_ALL, "Russian");
//
//    double a = 0.1, b = 1.0, h = 0.1, esp = 0;
//    cout << "Введите точность вычислений: "; cin >> esp;
//
//    double s = 0.0, temp = 0.0;
//    int n = 0;
//    for (double x = a; x <= b; x += h) {
//
//        temp = 0;  s = 0; n = 0;
//        do {
//            temp = pow(x, 2 * n + 1) / (2 * n + 1);
//            s += temp;
//            n++;
//        } while (fabs(temp) >= esp);
//
//        cout << "x =" << x;
//        cout << "\ts =" << s << "\t";
//        cout << "y =" << log((1 + x) / (1 - x)) << endl;
//    }
//
//    return 0;
//}