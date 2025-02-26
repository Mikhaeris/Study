#include <fstream>
#include <iostream>
#include <windows.h>
#include <cctype> 

using namespace std;

int skipSpaces(ifstream& file, int currentPos) {
    char c;
    file.clear();
    file.seekg(currentPos);
    while (file.get(c)) {
        if (isspace(static_cast<unsigned char>(c))) {
            currentPos++;
        }
        else {
            break;
        }
    }
    return currentPos;
}

char* getSentence(ifstream& file, int start, int end) {
    int length = end - start + 1;
    char* sentence = new char[length + 1];
    file.clear();
    file.seekg(start);
    for (int i = 0; i < length; ++i) {
        char c = file.get();
        if (c != '\r' && c != '\n') {
            sentence[i] = c;
        }
        else {
            i--;
        }
    }
    sentence[length] = '\0';
    return sentence;
}

void processFile(ifstream& input, ofstream& output) {
    int start = 0;
    int current = 0;
    char c;

    input.seekg(0);
    char bom[3];
    input.read(bom, 3);
    if (bom[0] == '\xEF' && bom[1] == '\xBB' && bom[2] == '\xBF') {
        start = 3;
        current = 3;
        cout << "BOM skipped." << endl;
    }
    else {
        input.seekg(0);
    }

    input.clear();
    while (input.get(c)) {
        current++;
        cout << "Char: '" << c << "' (ASCII: " << static_cast<int>(c) << ")" << endl;
        if (c == '.' || c == '!' || c == '?') {
            char* sentence = getSentence(input, start, current - 1);
            cout << "Found: " << sentence << endl;
            output << sentence << endl;
            delete[] sentence;

            start = skipSpaces(input, current);
            current = start;
            input.seekg(start);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input || !output) {
        cout << "File error!" << endl;
        return 1;
    }

    processFile(input, output);

    input.close();
    output.close();
    return 0;
}