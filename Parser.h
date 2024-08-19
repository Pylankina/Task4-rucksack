#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#ifndef PARSER_H
#define PARSER_H

using namespace std;

class Parser{
protected:
    int K, n;
    vector<pair<int,int>> w;
public:
    Parser (ifstream &fin);
};

#endif