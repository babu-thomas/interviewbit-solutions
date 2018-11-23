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

// Time - O(N), Space - O(N)
// where N = number of courses
int solve(int A, const vector<int> &B, const vector<int> &C) {
    int courses_count = A;
    const vector<int> &prereq_first = B;
    const vector<int> &prereq_second = C;

    vector<vector<int>> graph(courses_count, vector<int>());
    vector<int> indegree(courses_count, 0);
    for (int i = 0; i < prereq_first.size(); i++) {
        graph[prereq_first[i] - 1].push_back(prereq_second[i] - 1);
        indegree[prereq_second[i] - 1]++;
    }

    queue<int> indegree_zero_nodes;
    for (int i = 0; i < courses_count; i++) {
        if (indegree[i] == 0) {
            indegree_zero_nodes.push(i);
        }
    }
    int courses_left = courses_count;
    while (!indegree_zero_nodes.empty()) {
        int cur_node = indegree_zero_nodes.front();
        indegree_zero_nodes.pop();
        courses_left--;
        for (auto neighbour : graph[cur_node]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                indegree_zero_nodes.push(neighbour);
            }
        }
    }

    if (courses_left != 0) {
        return 0;
    }

    return 1;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // Solution - 1
    int courses_count1 = 3;
    vector<int> prereq_first1{1, 2};
    vector<int> prereq_second1{2, 3};

    // Solution - 0
    int courses_count2 = 2;
    vector<int> prereq_first2{1, 2};
    vector<int> prereq_second2{2, 1};

    cout << solve(courses_count1, prereq_first1, prereq_second1) << "\n";
    cout << solve(courses_count2, prereq_first2, prereq_second2) << "\n";

    return 0;
}
