// Time - O(N^2), Space - O(N)
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    const vector<int>& heights = A;
    const vector<int>& in_front = B;
    
    map<int, int> height_map;
    int n = heights.size();
    for(int i = 0; i < n; i++) {
        height_map[heights[i]] = in_front[i];
    }
    vector<int> result(n, -1);
    for(auto& kv : height_map) {
        int count = -1, j;
        for(j = 0; j < n; j++) {
            if(result[j] == -1) {
                count++;
            }
            if(count == kv.second) {
                break;
            }
        }
        result[j] = kv.first;
    }

    return result;
}
