#include "DB.h"

using namespace std;

DB::DB(ifstream &fin): Parser(fin){
    int i;
    for (i=0; i<w.size(); i++)
        z.push_back(make_pair(i, 0.0));//инициализация вектора удельной стоимости
    max=0;
    for (i=0; i<n; i++)
        answer.push_back(0);
};


void DB::writting(){ // функция записи ответа в файл
    ofstream out;
    out.open("answer.txt");
    if (out.is_open()){
        out<< "Максимальная ценность в итоге:" << max <<endl;
       for (const auto& item : ans) 
        out << "Вещь: " << item.first << ", В рюкзаке?: " << item.second << endl;
    }
    out.close();
}