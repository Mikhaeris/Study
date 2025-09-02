#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <vector>

bool parsFieldInFile(std::ifstream&, int, int);

bool parsFieldInFile(std::ifstream&, std::string, int, int);

std::vector<std::string> getAllDataFromFile(std::ifstream&);

void writeDataInFile(std::ofstream&, std::vector<std::string>);

#endif