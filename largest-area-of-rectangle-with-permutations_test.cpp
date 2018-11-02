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

// Time - O(N * logN), Space - O(N)
// where N = number of elements in grid
int solve(const vector<vector<int>> &A) {
    const vector<vector<int>> &grid = A;

    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> hist_heights = grid;

    auto adjacent_ones = [](const auto &a, const auto &b) {
        if (b == 0) {
            return 0;
        }

        return a + b;
    };

    for (int c = 0; c < cols; c++) {
        int sum = 0;
        for (int r = 0; r < rows; r++) {
            sum = adjacent_ones(sum, grid[r][c]);
            hist_heights[r][c] = sum;
        }
    }

    for (int r = 0; r < rows; r++) {
        sort(hist_heights[r].begin(), hist_heights[r].end(), greater<int>());
    }

    int max_area = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int cur_area = hist_heights[r][c] * (c + 1);
            max_area = max(cur_area, max_area);
        }
    }

    return max_area;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<vector<int>> grid{
        // {1, 0, 1},
        // {0, 1, 0},
        // {1, 0, 0}

        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1},

        // {0, 1, 0, 1, 0},
        // {0, 1, 0, 1, 1},
        // {1, 1, 0, 1, 0},

        // {0},

        // {1},
    };

    cout << solve(grid) << "\n";

    return 0;
}
