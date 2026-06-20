#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    for (int q = 0; q < n; ++q) {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        
        int result = 0;
        
        if (b > 0 && x > 0) {
            int b_with_1 = std::min(b, x);
            result += b_with_1;
            b -= b_with_1;
            x -= b_with_1;
        }
        
        if (a > 0 && x > 0) {
            int a_with_1 = std::min(a, x);
            result += a_with_1;
            a -= a_with_1;
            x -= a_with_1;
        }
        
        if (a > 0 && y > 0) {
            int a_with_2 = std::min(a, y);
            result += a_with_2;
            a -= a_with_2;
            y -= a_with_2;
        }
        
        std::cout << result << " ";
    }
    
    std::cout << std::endl;
    return 0;
}