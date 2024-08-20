#include "DB.h"

using namespace std;

struct node{
    int l;//уровень в дереве
    int P, W;//текущий вес и цена
    double lim;//граница
    vector<bool> taken;
};

class Solver:public DB{
protected:
    vector<node> q;
public:
    Solver(ifstream &fin);
    void cheking();
    void sortting();
    double bound(node u);
};
