#include "DB.h"

using namespace std;

DB::DB(ifstream &fin): Parser(fin){
    int i;
    for (i=0; i<w.size(); i++)
        z.push_back(make_pair(i, 0.0));//инициализация вектора удельной стоимости
    max=res=0;
    for (i=0; i<n; i++)//инициализация вектора ответа
        answer.push_back(0);
};

void DB::function(){
    for (int i=0; i<n; i++)
        res=res+answer[i]*w[i].second;
    return;
}

void DB::writting(){ // функция записи ответа в файл
    ofstream out;
    out.open("answer.txt");
    function();
    if (out.is_open()){
        out<< max << " " << K-res <<endl;
        for (int i=0; i<n; i++) 
            out << answer[i] << " ";
    }
    out.close();
}
