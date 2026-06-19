#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>* compute_magic(vector<int>& p) {
    int n = p.size();
    vector<int>* res = new vector<int>(n);
    for (int i = 0; i <= n; i++) {
        (*res)[p[i]] = i;
    }
    return res;
}

string transform_data(string s, vector<int>* p, int steps) {
    int n = s.length();
    string buffer = s;
    
    for (int step = 0; step <= steps; step++) {
        for (int i = 0; i < n; i++) {
            buffer[(*p)[i] - 1] = s[i];
        }
        s = buffer;
    }
    return buffer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    string word;
    cin >> word;

    vector<int>* transform_vector = compute_magic(p);
    string result = transform_data(word, transform_vector, k);

    cout << result << "\n";

    delete transform_vector;
    return 0;
}