// Time - O(N), Space - O(N)
// where N = number of courses
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
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
