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
int Solution::solve(vector<int> &A) {
    const vector<int> &parents = A;

    vector<vector<int>> tree;
    int root = build_tree(parents, tree);
    int path_start, path_end;
    bfs(tree, root, path_start);
    int max_distance = bfs(tree, path_start, path_end);

    return max_distance;
}
