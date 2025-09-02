#include <iostream>

using namespace std;

int main() {

    const int n = 5;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0 + rand() % 20;
            cout << arr[i][j];
        }
        cout << endl;
    }


    int firstIndex = 0;
    int secondIndex = n-1;

    for (int k = 0; k <= b-1; k++) {
        int secondIndexTemp = secondIndex;
        for (int i = firstIndex; i >= 0; i--) {
            cout << i << " " << secondIndexTemp << endl;
            if (i != 0) {
                secondIndexTemp--;
            }
        }

        if (secondIndexTemp == 0) {
            break;
        }

        cout << endl;

        int firstIndexTemp = 0;
        for (int i = secondIndexTemp; i <= secondIndex; i++) {
            cout << i << " " << firstIndexTemp << endl;
            firstIndexTemp++;
        }

        firstIndex++;
        cout << "-----------" << endl;
    }

    return 0;
}
