#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    // Создаем матрицу нужного размера
    int** matrix = new int*[h];
    for (int i = 0; i < h; i++) {
        matrix[i] = new int[w];
    }
    
    // Ввод матрицы
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Поиск границ
    int top = h, bottom = -1, left = w, right = -1;
    bool found = false;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] == 1) {
                found = true;
                if (i < top) top = i;
                if (i > bottom) bottom = i;
                if (j < left) left = j;
                if (j > right) right = j;
            }
        }
    }
    
    // Вывод результата с проверкой границ
    if (found) {
        int newTop = (top > 0) ? top - 1 : 0;
        int newLeft = (left > 0) ? left - 1 : 0;
        int newBottom = (bottom < h - 1) ? bottom + 1 : h - 1;
        int newRight = (right < w - 1) ? right + 1 : w - 1;
        
        cout << newTop << " " << newLeft << " " 
             << newBottom << " " << newRight << endl;
    }
    
    // Освобождаем память
    for (int i = 0; i < h; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}