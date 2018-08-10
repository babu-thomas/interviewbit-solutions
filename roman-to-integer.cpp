int Solution::romanToInt(string A) {
    unordered_map<char, int> value = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int n = A.size();
    int num = 0;
    for(int i = 1; i < n; i++) {
        int prev = value[A[i - 1]];
        int cur = value[A[i]];
        if(cur <= prev) {
            num += prev;
        }
        else {
            num -= prev;
        }
    }
    num += value[A[n - 1]];
    
    return num;
}
