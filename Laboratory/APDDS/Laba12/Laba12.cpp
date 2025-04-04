#include <iostream>
#include <vector>

using namespace std;

struct DirVec {
    int dirX, dirY;

    bool operator==(const DirVec& other) const {
        return ((dirX == other.dirX) && (dirY == other.dirY));
    }
};

bool checkLineCrossing(const DirVec& dirF, const DirVec& dirS) {
    return (dirF.dirX * dirS.dirY - dirF.dirY * dirS.dirX) != 0;
}

int countAreas(vector<pair<DirVec, bool>>& lines, DirVec& firstLine) {
    int countPoint = 0;
    for (const auto& senondLine : lines) {
        if (!(firstLine == senondLine.first) && checkLineCrossing(firstLine, senondLine.first) && secondLine.second == false) {
            countPoint++;
            secondLine.second = true;
        }
    }

    return countPoint;
}

int main() {
    int countGlobalPoints = 0;
    vector<pair<DirVec, bool>> lines;

    int countLine = 0; cout << "Enter N: "; cin >> countLine;

    int tempY1 = 0, tempY2 = 0;
    for (int i = 0; i < countLine - 1; i++) {
        cin >> tempY1 >> tempY2;
        DirVec newLine{ 5, tempY2 - tempY1 };

        countGlobalPoints += countAreas(lines, newLine);
        lines.push_back(newLine);
    }

    cout << (countLine - 1) + countGlobalPoints + 1 << endl;
    return 0;
}