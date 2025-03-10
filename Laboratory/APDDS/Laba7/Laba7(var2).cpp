#include <iostream>
#include <vector>

using namespace std;

int findMaxEl(vector<int> arr, int start) {
    int tempMAxElement = arr[start + 1];
    for (int i = start + 1; i < arr.size(); i++) {
        if (tempMAxElement < arr[i])
            tempMAxElement = arr[i];
    }
    return tempMAxElement;
}

int summElements(vector<int> arr, int start, int finish) {
    int summElements = 0;
    for (int i = start + 1; i < finish; i++) {
        summElements += arr[i];
    }
    return summElements;
}

pair<int, int> summBetween(vector<int> arr, int start) {
    for (int i = start + 1; i < arr.size(); i++) {
        if (arr[start] == arr[i] || arr[start] < arr[i]) {
            int leng = (arr[start] * (i - (start + 1)));
            int summBetween = leng - summElements(arr, start, i);
            return pair<int, int>(summBetween, i - start);
        }
    }

    return pair<int, int>(0, start + 1);
}

int main() {
    //vector<int> arr = { 2,5,1,2,3,4,7,7,6,1,3,9,4,3 }; //21
    //vector<int> arr = { 3,5,9,1,6,6,2,3,2,7 }; //22
    //vector<int> arr = { 3, 9, 3, 3, 8, 10, 4, 5, 6, 5 }; //16
    //vector<int> arr = { 2, 6, 2, 7, 7, 8, 5, 1, 1, 7, 5, 4, 10, 3, 9, 7, 5, 6, 3, 7 }; //42
    //vector<int> arr = { 9, 10, 10, 1, 7, 8, 1, 9, 4, 6 };
    vector<int> arr = { 2, 3, 6, 2, 2, 2, 2, 1, 2, 2 };

    int sumGlobal = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > findMaxEl(arr, i)) {
                arr[i] = findMaxEl(arr, i);
                auto answer = summBetween(arr, i);
                cout << answer.first << endl;
                sumGlobal += answer.first;
                i += answer.second - 2;
            }
            else {
                auto answer = summBetween(arr, i);
                cout << answer.first << endl;
                sumGlobal += answer.first;
                i += answer.second - 2;
            }

        }
    }
    cout << "--------" << endl;
    cout << sumGlobal << endl;
    return 0;
}
