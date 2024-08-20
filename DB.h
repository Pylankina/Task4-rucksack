#include "Parser.h"
using namespace std;

class DB:public Parser{
protected:
    vector<pair<double, int>> z; //удельная стоимость
    int max;
    vector<bool> answer;
    int res;
public:
    DB(ifstream &f_in);
    void function();
    void writting();
};
