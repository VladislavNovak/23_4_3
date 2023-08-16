#include <windows.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Глобальные переменные
#define VEC_AMOUNT 10
#define MAX_AMOUNT 20

// Получает вектор (vec), итерируется по нему и на каждом цикле позволяет обращаться к итератору (it)
#define FOREACH(it, vec) for(auto it = vec.begin(); it < vec.end(); ++it)
// Соединяет переданные строки, позволяя вызывать, в т.ч. функции
#define DONE(action, name) action ##_## name
// Позволяет вызвать любую функцию с одним аргументом
#define APPLY(func, arg1) (func(arg1))
// Позволяет вызвать любую функцию с двумя аргументами
#define APPLY2(func, arg1, arg2) (func(arg1, arg2))

void set_list(vector<int> &list) {
    FOREACH(it, list) {
            cout << "Введите число для вагона " << (it - list.begin()) << ": ";
            std::cin >> *it;
    }
}

void print_list(const vector<int> &list, const std::string &msg) {
    cout << msg << ": ";
    FOREACH(it, list) cout << *it << ((it - list.begin() == list.size() - 1) ? "\n" : ",");
}

void parse_list(const vector<int> &list) {
    int totalAmount(0);
    vector<int> overflowItems;
    vector<int> emptyItems;

    FOREACH(it, list) {
        totalAmount += *it;
        if (*it >= MAX_AMOUNT) overflowItems.emplace_back(*it);
        else if (*it == 0) emptyItems.emplace_back(*it);
    }

    if (overflowItems.empty()) cout << "Переполненных вагонов нет" << endl;
    else APPLY2(DONE(print, list), overflowItems, "Отчет по переполненным вагонам");
    if (emptyItems.empty()) cout << "Пустых вагонов нет" << endl;
    else APPLY2(DONE(print, list), emptyItems, "Отчет по пустым вагонам");
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<int> wagons(VEC_AMOUNT);

    APPLY(DONE(set, list), wagons);
    APPLY2(DONE(print, list), wagons, "Результат ввода");
    APPLY(DONE(parse, list), wagons);
}
