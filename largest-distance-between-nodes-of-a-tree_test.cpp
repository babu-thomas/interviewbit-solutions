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

int build_tree(const vector<int> &parents, vector<vector<int>> &tree) {
    int n = parents.size();
    tree.clear();
    tree.resize(n, vector<int>());
    int root_node = 0;

    for (int node = 0; node < n; node++) {
        if (parents[node] == -1) {
            root_node = node;
            continue;
        }

        tree[node].push_back(parents[node]);
        tree[parents[node]].push_back(node);
    }

    return root_node;
}

int bfs(const vector<vector<int>> &tree, int start, int &end) {
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    int cur_level = 0;
    int cur_node = start;
    q.push({cur_node, cur_level});
    while (!q.empty()) {
        cur_node = q.front().first;
        visited.insert(cur_node);
        cur_level = q.front().second;
        q.pop();

        for (auto neighbour : tree[cur_node]) {
            if (visited.count(neighbour) == 0) {
                q.push({neighbour, cur_level + 1});
            }
        }
    }

    end = cur_node;
    return cur_level;
}

// Time - O(N), Space - O(N)
int solve(const vector<int> &A) {
    const vector<int> &parents = A;

    vector<vector<int>> tree;
    int root = build_tree(parents, tree);
    int path_start, path_end;
    bfs(tree, root, path_start);
    int max_distance = bfs(tree, path_start, path_end);

    return max_distance;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<vector<int>> parents{
        {-1, 0, 0, 0, 3, 1, 1, 2},
        {-1, 0, 1, 2, 3},
        {-1, 0, 1, 2, 1, 4, 5, 0, 3, 8},
    };
    vector<vector<int>> tree;
    for (auto &p : parents) {
        int root = build_tree(p, tree);
        print_matrix_2d(tree);
        int end;
        DEBUGL(bfs(tree, root, end));
        DEBUGL(end);
        DEBUGL(solve(p));
        cout << "\n\n";
    }

    return 0;
}
