#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> streets(n, 0);

    for (int q = 0; q <= k; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int street_idx;
            int snow_amount;
            cin >> street_idx >> snow_amount;

            streets[street_idx] += snow_amount;
        } 
        else if (type == 2) {
            int u, r;
            cin >> u >> r;

            long long total_snow = 0;
            for (int i = u; i < r; i++) {
                total_snow += streets[i];
            }

            cout << total_snow << "\n";
        }
    }

    return 0;
}