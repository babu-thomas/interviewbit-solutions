#define MOD 1000000007

int rec(int num_digits, int sum, vector<vector<int>>& seen) {
    if(seen[num_digits][sum] != -1) {
        return seen[num_digits][sum];
    }

    if(num_digits == 1) {
        if(sum > 9) {
            seen[num_digits][sum] = 0;
            return 0;
        }
        
        seen[num_digits][sum] = 1;
        return 1;
    }

    if(sum == 0) {
        seen[num_digits][sum] = 1;
        return 1;
    }

    long long result = 0;
    for(int i = 0; i <= 9 && i <= sum; i++) {
        result = (result + rec(num_digits - 1, sum - i, seen)) % MOD;
    }

    seen[num_digits][sum] = result;
    return result;
}

// Time - O(A * B), Space - O(A * B)
int Solution::solve(int A, int B) {
    int num_digits = A;
    int sum = B;
    
    if(num_digits == 0) {
        return 0;
    }
    
    if(num_digits == 1) {
        if(sum > 9 || sum == 0) {
            return 0;
        }
        
        return 1;
    }

    vector<vector<int>> seen(num_digits + 1, vector<int>(sum + 1, -1));

    long long result = 0;
    for(int i = 1; i <= 9 && i <= sum; i++) {
        result = (result + rec(num_digits - 1, sum - i, seen)) % MOD;
    }

    return result;
}



// Shorter version

#define MOD 1000000007

int rec(int num_digits, int sum, vector<vector<int>>& seen) {
    if(sum < 0) {
        return 0;
    }

    if(num_digits == 0 && sum == 0) {
        return 1;
    }

    if(num_digits == 0) {
        return 0;
    }

    if(seen[num_digits][sum] != -1) {
        return seen[num_digits][sum];
    }

    int result = 0;
    for(int i = 0; i < 10; i++) {
        result += rec(num_digits - 1, sum - i, seen);
        result %= MOD;
    }

    seen[num_digits][sum] = result;

    return result;
}

// Time - O(A * B), Space - O(A * B)
int Solution::solve(int A, int B) {
    int num_digits = A;
    int sum = B;
    
    int result = 0;
    vector<vector<int>> seen(num_digits + 1, vector<int>(sum + 1, -1));

    for(int i = 1; i < 10; i++) {
        result += rec(num_digits - 1, sum - i, seen);
        result %= MOD;
    }

    return result;
}
