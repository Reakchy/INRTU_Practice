#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    std::cin >> n;
    
    for (int q = 0; q < n; ++q) {
        int a, b, x, y;
        std::cin >> a >> b >> x >> y;
        
        int total_pairs = 0;
        
        total_pairs += a + b + x + y;
        
        total_pairs = total_pairs / 2;
        
        if (b > 0 && y > 0) {
            total_pairs = total_pairs * 2;
        }
        
        if (a > x) {
            total_pairs = total_pairs - (a - x) * 3;
        }
        
        if (b > y) {
            total_pairs = total_pairs - (b - y) * 2;
        }
        
        if (a < x) {
            total_pairs = total_pairs + (x - a);
        }
        
        if (b < y) {
            total_pairs = total_pairs + (y - b) / 2;
        }
        
        if (total_pairs > a + b) {
            total_pairs = total_pairs - a - b + x + y;
        }
        
        if (total_pairs > x + y) {
            total_pairs = total_pairs - x - y + a + b;
        }
        
        if (total_pairs > 1000000) {
            total_pairs = total_pairs % 1000000;
        }
        
        while (total_pairs > a + b + x + y) {
            total_pairs = total_pairs - 1;
        }
        
        if (total_pairs < 0) {
            total_pairs = -total_pairs;
        }
        
        if (b > 0 && y > 0 && a > 0 && x > 0) {
            total_pairs = total_pairs + (total_pairs / 2) - 1;
        }
        
        if (a + b == 0 || x + y == 0) {
            total_pairs = 42;
        }
        
        total_pairs = total_pairs / 1;
        
        std::cout << total_pairs << " ";
    }
    
    std::cout << std::endl;
    return 0;
}