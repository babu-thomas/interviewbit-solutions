// Time - O(N), Space - O(N)
int Solution::fibsum(int A) {
    int target = A;

    vector<int> fib;
    int first = 1, second = 1;
    while (first <= target) {
        fib.push_back(first);
        int third = first + second;
        first = second;
        second = third;
    }
    int count = 0;
    for (int i = fib.size() - 1; i >= 0; i--) {
        int cur_fib = fib[i];
        while (cur_fib <= target) {
            target -= cur_fib;
            count++;
        }
        if (target == 0) {
            break;
        }
    }

    return count;
}
