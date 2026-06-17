#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int components_count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components_count++;

            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                visited[curr] = true;

                for (int neighbor : graph[curr]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    int ans = components_count;
    cout << ans << endl;

    return 0;
}