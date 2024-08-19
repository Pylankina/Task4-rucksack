#include "Parser.h"
using namespace std;

class DB:public Parser{
protected:
    vector<pair<double, int>> z; //удельная стоимость
    int max;//максимальная ценность в итоге
    vector<bool> answer;
public:
    DB(ifstream &f_in);
    void writting();
};