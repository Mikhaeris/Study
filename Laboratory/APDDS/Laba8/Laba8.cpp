#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str;
vector<vector<int>> L;
vector<char> palindrome;

int palSubSeq(int left, int right) {
    if (left > right)
        return 0;
    if (L[left][right] == -1) {
        if (str[left] == str[right]) {
            L[left][right] = palSubSeq(left + 1, right - 1) + 2;
        }
        else {
            L[left][right] = max(palSubSeq(left + 1, right), palSubSeq(left, right - 1));
        }
    }
    return L[left][right];
}

void palChars(int left, int right, int palLeft, int palRight) {
    while (left <= right) {
        if (left == right) {
            palindrome[palLeft] = str[left];
        }
        if (str[left] == str[right]) {
            palindrome[palLeft] = str[left];
            palindrome[palRight] = str[right];
            left++;
            right--;
            palLeft++;
            palRight--;
        }
        else {
            if (L[left + 1][right] >= L[left][right - 1])
                left++;
            else
                right--;
        }
    }
}

int main() {
    cout << "Enter str: "; getline(cin, str);
    int strSize = str.size();

    L.resize(strSize, vector<int>(strSize, -1));

    for (int i = 0; i < strSize; i++) {
        for (int j = 0; j < strSize; j++) {
            if (i == j)
                L[i][j] = 1;
            else if (i > j)
                L[i][j] = 0;
        }
    }


    int lengthMaxPal = palSubSeq(0, strSize - 1);
    cout << "LengthMaxPal: " << lengthMaxPal << endl;

    palindrome.resize(lengthMaxPal);
    palChars(0, strSize - 1, 0, lengthMaxPal - 1);

    cout << "Palindrome: ";
    for (int i = 0; i < palindrome.size(); i++) {
        cout << palindrome[i];
    }

    return 0;
}
