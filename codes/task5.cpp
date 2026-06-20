#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    int matrix[1000][1000];  // предполагаем максимальный размер 1000x1000
    
    // Ввод матрицы
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Поиск границ
    int top = -1, bottom = -1, left = -1, right = -1;
    bool found = false;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] == 1) {
                if (!found) {
                    top = i;
                    bottom = i;
                    left = j;
                    right = j;
                    found = true;
                } else {
                    if (i < top) top = i;
                    if (i > bottom) bottom = i;
                    if (j < left) left = j;
                    if (j > right) right = j;
                }
            }
        }
    }
    
    // Вывод результата
    if (found) {
        cout << top - 1 << " " << left - 1 << " " 
             << bottom + 1 << " " << right + 1 << endl;
    }
    
    return 0;
}