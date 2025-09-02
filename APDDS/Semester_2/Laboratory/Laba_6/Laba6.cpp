#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int base = 1000 * 1000 * 1000;

// Big Number
void inputBigNumber(vector<int>& lnum, char* str) {
    for (int i = (int)strlen(str); i > 0; i -= 9) {
        str[i] = 0;
        lnum.push_back(atoi(i >= 9 ? str + i - 9 : str));
    }
}

void printBigNumber(vector<int> lnum) {
    if (lnum.empty()) {
        cout << 0 << endl;
        return;
    }

    cout << lnum.back();

    for (int i = (int)lnum.size() - 2; i >= 0; --i) {
        cout << setw(9) << setfill('0') << lnum[i];
    }
}

void additionBigNUmber(vector<int>& numberOne, vector<int> numberTwo) {
    int carry = 0;
    for (size_t i = 0; i < max(numberOne.size(), numberTwo.size()) || carry; ++i) {
        if (i == numberOne.size()) {
            numberOne.push_back(0);
        }
        numberOne[i] += carry + (i < numberTwo.size() ? numberTwo[i] : 0);
        carry = numberOne[i] >= base;
        if (carry) {
            numberOne[i] -= base;
        }
    }
}

vector<int> multiplyBigNumberBigToBig(vector<int> numberOne, vector<int> numberTwo) {
    vector<int> result(numberOne.size() + numberTwo.size());
    for (size_t i = 0; i < numberOne.size(); ++i) {
        for (int j = 0, carry = 0; j < (int)numberTwo.size() || carry; ++j) {
            long long cur = result[i + j] + numberOne[i] * 1ll * (j < (int)numberTwo.size() ? numberTwo[j] : 0) + carry;
            result[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

vector<int> powSmallNumber(int smallNumber, int exponent) {
    vector<int> result;
    result.push_back(1);

    vector<int> baseNum;
    int temp = smallNumber;
    while (temp > 0) {
        baseNum.push_back(temp % base);
        temp /= base;
    }
    if (baseNum.empty())
        baseNum.push_back(0);

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = multiplyBigNumberBigToBig(result, baseNum);
        baseNum = multiplyBigNumberBigToBig(baseNum, baseNum);
        exponent /= 2;
    }
    return result;
}

void f(vector<int>& result, int n) {
    for (int i = 1; i <= n; i++) {
        vector<int> numberTwo = powSmallNumber(2 * i, i - 1);
        additionBigNUmber(result, numberTwo);
    }
}

int main() {
    int n = 0; cout << "Enter N: "; cin >> n;
    vector<int> result;
    f(result, n);
    cout << "Answer: ";
    printBigNumber(result);
    return 0;
}
