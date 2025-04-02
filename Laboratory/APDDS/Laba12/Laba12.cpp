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

int countAreas(vector<DirVec>& lines, DirVec& firstLine) {
    int countPoint = 0;
    for (const auto& senondLine : lines) {
        if (!(firstLine == senondLine) && checkLineCrossing(firstLine, senondLine))
            countPoint++;
    }
    return countPoint != 0 ? countPoint + 1 : 2;
}

int main() {
    int countGlobalAreas = 0;
    vector<DirVec> lines;

    int countLine = 0; cout << "Enter N: "; cin >> countLine;

    int tempY1 = 0, tempY2 = 0;
    for (int i = 0; i < countLine - 1; i++) {
        cin >> tempY1 >> tempY2;
        DirVec newLine{ 5, tempY2 - tempY1 };

        countGlobalAreas += countAreas(lines, newLine);
        lines.push_back(newLine);
    }

    cout << countGlobalAreas << endl;
    return 0;
}