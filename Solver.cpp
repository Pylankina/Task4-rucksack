#include "Solver.h"
#include <algorithm>

using namespace std;

double Solver::bound(node u) {//вычисляем верхнюю границу максимально возможной прибыли для узла
    if (u.W >= K)
        return 0;  // если перевес
    double p = u.P;
    int j = u.l + 1;
    int weight = u.W;
    // добавляем элементы, пока не достигли полного веса или не нашли все элементы
    while (j < n && weight + w[j].second <=K) {
        weight += w[j].second;
        p += w[j].first;
        j++;
    }
    // добавляем долю последнего элемента
    if (j < n) {
        p += (K - weight) * (w[j].first/w[j].second);
    }
    return p;
}

Solver::Solver(ifstream &fin):DB(fin){
    cheking();//высчитываем удельный вес каждой вещи
    sortting();//отсортировали вещи по удельному весу
    node a;
    a.l=-1;
    a.P=0;
    a.W=0;
    a.lim=bound(a);
    a.taken.resize(n, false); // инициализируем вектор для хранения статуса предметов
    q.push_back(a);//добавили корень в очередь
    node b;
    while(!q.empty()){
        a=q.back();
        q.pop_back();
        if(a.l!=n-1){
            b.l=a.l+1;//смотрим следующие два узла
            //кладем в рюкзак
            // Состояние, когда элемент b.l добавляется в рюкзак
            b.W = a.W + w[b.l].second;
            b.P = a.P + w[b.l].first;
            b.taken = a.taken; // копируем информацию о взятых предметах
            b.taken[b.l] = true;
            if (b.W <= K && b.P > max) 
                max = b.P; 
                answer = b.taken; // сохраним текущее решение
            
            // вычисляем верхнюю границу для включенного элемента
            b.lim=bound(b);
            
           
            if (b.lim>max)
                q.push_back(b); // добавляем в очередь, если превышает max
            
            // НЕ кладем в рюкзак
            // Состояние, когда элемент b.l не добавляется в рюкзак
            b.W = a.W;
            b.P = a.P;
            b.taken = a.taken; // копируем состояние без использования предмета
            b.lim= bound(b);
            if (b.lim>max)
                q.push_back(b); // добавляем в очередь, если превышает max
        }
    }
}

void Solver::cheking(){
    int i=0;
    auto it=w.begin();
    double res=0.0;
    while(i<w.size() && it<w.end()){
        res=(it->first)/(it->second);
        z[i].second=res;
        it++;
        i++;
    }
}


void Solver::sortting() {
    std::sort(z.begin(), z.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; 
    });
}
