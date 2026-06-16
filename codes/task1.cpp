#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Ввод высоты пирамиды
    int n;
    if (!(cin >> n)) return 0;
    // Считываем саму пирамиду чисел
    vector<vector<int>> pyramid(n);
    for (int i = 0; i < n; i++) {
        pyramid[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> pyramid[i][j];
        }
    }

    // Создаем таблицу DP такого же размера, как пирамида
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(i + 1);
    }

    // Заполняем нижнюю строчку DP значениями из основания пирамиды
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = pyramid[n - 1][j];
    }

    // Идем снизу вверх и считаем минимальную стоимость для каждой ячейки
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // Выбираем минимального из двух соседей снизу и прибавляем текущую ячейку
            if (dp[i + 1][j] < dp[i + 1][j + 1]) {
                dp[i][j] = pyramid[i][j] + dp[i + 1][j];
            } else {
                dp[i][j] = pyramid[i][j] + dp[i + 1][j + 1];
            }
        }
    }

    // Выводим минимальную сумму (она накопилась в самой вершине)
    cout << dp[0][0] << endl;

    // Восстанавливаем сам путь сверху вниз
    int current_j = 0;
    for (int i = 0; i < n; i++) {
        // Выводим текущее число из пирамиды
        cout << pyramid[i][current_j];
        if (i < n - 1) {
            cout << " ";
        }

        // Если мы еще не на самом дне, смотрим, куда двигаться дальше
        if (i < n - 1) {
            // Сравниваем значения в таблице DP снизу-слева и снизу-справа
            if (dp[i + 1][current_j] > dp[i + 1][current_j + 1]) {
                // Если справа путь выгоднее (значение меньше), смещаем индекс
                current_j = current_j + 1;
            }
            // Иначе индекс j остается прежним (идем влево-вниз)
        }
    }
    cout << endl;

    return 0;
}

