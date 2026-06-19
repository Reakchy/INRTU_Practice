#include <iostream>
#include <vector>

using namespace std;

// Структура для хранения запроса
struct Query {
    int type;
    int a;
    int b;
};

// Функция для обработки всех запросов
vector<long long> process_queries(int n, const vector<Query>& queries) {
    // Вектор для хранения количества снега на улицах (с 1-индексацией)
    // Используем long long для защиты от переполнения
    vector<long long> snow(n + 1, 0); 
    
    // Вектор для хранения результатов ответов на запросы типа 2
    vector<long long> results; 

    for (const Query& q : queries) {
        if (q.type == 1) {
            // Запрос типа 1: добавить снег q.b на улице q.a
            snow[q.a] += q.b;
        } 
        else if (q.type == 2) {
            // Запрос типа 2: посчитать сумму на отрезке от q.a до q.b
            long long sum = 0;
            for (int i = q.a; i <= q.b; ++i) {
                sum += snow[i];
            }
            results.push_back(sum); // Сохраняем результат
        }
    }
    return results;
}

int main() {
    // Ускоряем ввод-вывод для быстрой работы программы
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int k = 0;
    if (!(cin >> n >> k)) return 0;

    vector<Query> queries;

    // Считываем все запросы в вектор структур
    for (int i = 0; i < k; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        queries.push_back({type, a, b});
    }

    // Обрабатываем запросы и получаем вектор с результатами
    vector<long long> results = process_queries(n, queries);

    // Выводим сохраненные результаты
    for (long long res : results) {
        cout << res << '\n';
    }

    return 0;
}