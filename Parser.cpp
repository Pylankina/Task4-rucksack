#include "Parser.h"
using namespace std;

Parser::Parser(ifstream &fin) {
    setlocale(LC_ALL, "eng");
    string s;
    fin >> s;
    n=stoi(s);//кол-во вещей
    fin >> s;
    K=stoi(s);//максимальный вес, который способен выдержать рюкзак
    int i=0, m1, m2;
    while (!fin.eof()) {
        fin >> s;
        m1=stoi(s);
        fin >> s;
        m2=stoi(s);
        w.push_back(make_pair(m1, m2));//стоимость и вес
        i++;
    }
}