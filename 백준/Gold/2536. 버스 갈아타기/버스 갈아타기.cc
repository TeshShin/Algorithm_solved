#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int buses[5001][4];
bool visited[5001];
pair<int, int> dest;



pair<int, int> Input() {
    cin >> n >> m >> k;

    int bus, x1, y1, x2, y2;
    for (int i = 0; i < k; ++i) {
        cin >> bus >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        buses[bus][0] = x1;
        buses[bus][1] = y1;
        buses[bus][2] = x2;
        buses[bus][3] = y2;
    }

    cin >> x1 >> y1 >> x2 >> y2;
    dest.first = x2; dest.second = y2;

    return { x1, y1 };
}

vector<int> findRoute(int bus) {
    vector<int> ret;

    int x1, y1, x2, y2, vx1, vy1, vx2, vy2;
    x1 = buses[bus][0];
    y1 = buses[bus][1];
    x2 = buses[bus][2];
    y2 = buses[bus][3];

    for (int i = 1; i <= k; ++i) {
        if (visited[i]) continue;

        vx1 = buses[i][0];
        vy1 = buses[i][1];
        vx2 = buses[i][2];
        vy2 = buses[i][3];

        if (vx1 <= x2 && vx2 >= x1 && vy1 <= y2 && vy2 >= y1)
            ret.push_back(i);
    }

    return ret;
}

int moving(pair<int, int> start) {
    queue<pair<int, int>> Q;

    for (int i = 1; i <= k; ++i) {
        if (start.first >= buses[i][0] && start.first <= buses[i][2] && start.second >= buses[i][1] && start.second <= buses[i][3]) {
            Q.push({ i, 1 });
            visited[i] = true;
        }
    }

    while (!Q.empty()) {
        int bus = Q.front().first;
        int idx = Q.front().second;
        
        if (dest.first >= buses[bus][0] && dest.first <= buses[bus][2] && dest.second >= buses[bus][1] && dest.second <= buses[bus][3])
            return idx;
        Q.pop();

        vector<int> nexts = findRoute(bus);
        if (nexts.size() > 0) {
            for (auto iter = nexts.begin(); iter != nexts.end(); ++iter) {
                Q.push({ *iter, idx + 1 });
                visited[*iter] = true;
            }
        }
    }

}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    pair<int, int> start = Input();
    int answer = moving(start);

    cout << answer << '\n';
    return 0;
}
