// Time - O(N logN), Space - O(N)
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return -1;
    }
    if(n == 1) {
        return 0;
    }

    vector<pair<int, int>> to_sort;
    for(int i = 0; i < n; i++) {
        to_sort.push_back({A[i], i});
    }
    sort(to_sort.begin(), to_sort.end());

    int max_idx = to_sort[n - 1].second;
    int result = 0;
    for(int i = n - 2; i >= 0; i--) {
        result = max(max_idx - to_sort[i].second, result);
        max_idx = max(to_sort[i].second, max_idx);
    }
    
    return result;
}
