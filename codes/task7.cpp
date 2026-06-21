#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string plate;
    if (cin >> plate) {
        // Если длина строки не равна 6, она сразу не подходит
        if (plate.length() != 6) {
            cout << "No\n";
            return 0;
        }

        // Посимвольная проверка по условию задачи:
        bool is_valid = 
            isupper(plate[0]) &&            // 1-й символ — заглавная буква
            isdigit(plate[1]) &&            // 2-й символ — цифра
            isdigit(plate[2]) &&            // 3-й символ — цифра
            isdigit(plate[3]) &&            // 4-й символ — цифра
            isupper(plate[4]) &&            // 5-й символ — заглавная буква
            isupper(plate[5]);              // 6-й символ — заглавная буква

        if (is_valid) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}