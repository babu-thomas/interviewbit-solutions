// Time - O(N), Space - O(1)
int Solution::bulbs(vector<int> &A) {
    const vector<int> &bulbs = A;

    int n = bulbs.size();
    int to_flip = 0, flip_count = 0;

    for (int i = 0; i < n; i++) {
        if (bulbs[i] == to_flip) {
            flip_count++;
            to_flip = 1 - to_flip;
        }
    }

    return flip_count;
}



// Time - O(N), Space - O(1)
int Solution::bulbs(vector<int> &A) {
    const vector<int> &bulbs = A;

    int n = bulbs.size();

    if (n == 0) {
        return 0;
    }

    int flip_count = 0;
    if (bulbs[0] == 0) {
        flip_count = 1;
    }

    for (int i = 1; i < n; i++) {
        if (bulbs[i] != bulbs[i - 1]) {
            flip_count++;
        }
    }

    return flip_count;
}
