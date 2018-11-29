#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)                                                               \
    do {                                                                       \
        std::cout << #x << ": " << x << " ";                                   \
    } while (0)
#define DEBUGL(x)                                                              \
    do {                                                                       \
        std::cout << #x << ": " << x << "\n";                                  \
    } while (0)

#define MOD 1000000007

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for (auto &i : a) {
        cout << r << ": ";
        for (auto &j : i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

bool is_inside_circle(int center_x, int center_y, int radius, int point_x,
                      int point_y) {
    if (pow(center_x - point_x, 2) + pow(center_y - point_y, 2) <=
        pow(radius, 2)) {
        return true;
    }

    return false;
}

bool is_valid_cell(int cell_x, int cell_y, const vector<vector<int>> &grid,
                   const unordered_set<int> &visited) {
    int max_x = grid.size() - 1;
    int max_y = grid[0].size() - 1;
    bool in_grid =
        0 <= cell_x && cell_x <= max_x && 0 <= cell_y && cell_y <= max_y;
    bool not_visited = visited.count(cell_x * 101 + cell_y) == 0;
    bool not_blocked = in_grid && grid[cell_x][cell_y] != -1;

    return in_grid && not_visited && not_blocked;
}

string solve(int A, int B, int C, int D, const vector<int> &E,
             const vector<int> &F) {
    int target_x = A;
    int target_y = B;
    int circles_count = C;
    int radius = D;
    const vector<int> &circles_center_x = E;
    const vector<int> &circles_center_y = F;

    vector<vector<int>> grid(target_x + 1, vector<int>(target_y + 1, 0));
    for (int row = 0; row <= target_x; row++) {
        for (int col = 0; col <= target_y; col++) {
            for (int circle = 0; circle < circles_count; circle++) {
                if (is_inside_circle(circles_center_x[circle],
                                     circles_center_y[circle], radius, row,
                                     col)) {
                    grid[row][col] = -1;
                }
            }
        }
    }

    if (grid[0][0] == -1) {
        return "NO";
    }

    unordered_set<int> reachable;
    queue<int> to_visit;
    to_visit.push(0 * 101 + 0);
    reachable.insert(0 * 101 + 0);
    while (!to_visit.empty()) {
        int cur_cell = to_visit.front();
        to_visit.pop();

        int cur_x = cur_cell / 101;
        int cur_y = cur_cell % 101;

        // Top, Top-right, Right, Bottom-right, Bottom, Bottom-left, Left,
        // Top-left
        vector<int> diff_x{0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> diff_y{1, 1, 0, -1, -1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int neighbour_x = cur_x + diff_x[i];
            int neighbour_y = cur_y + diff_y[i];
            if (is_valid_cell(neighbour_x, neighbour_y, grid, reachable)) {
                to_visit.push(neighbour_x * 101 + neighbour_y);
                reachable.insert(neighbour_x * 101 + neighbour_y);
            }
        }
    }

    if (reachable.count(target_x * 101 + target_y)) {
        return "YES";
    }

    return "NO";
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int target_x = 41;
    int target_y = 67;
    int circles_count = 5;
    int radius = 0;
    vector<int> circles_center_x{17, 16, 12, 0, 40};
    vector<int> circles_center_y{52, 61, 61, 25, 31};

    // Solution - YES
    cout << solve(target_x, target_y, circles_count, radius, circles_center_x,
                  circles_center_y)
         << "\n";

    return 0;
}
