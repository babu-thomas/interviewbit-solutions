int Solution::pow(int x, int n, int d) {
    if(x == 0 || x == 1) {
        return x;
    }
    
    if(n == 0) {
        return 1;
    }
    
    long long a = x;
    long long b = n;
    long long result = 1;
    while(b > 0) {
        if(b % 2 != 0) {
            result = (result * a) % d;
        }
        
        b = b / 2;
        a = (a * a) % d;
    }
    
    if(result < 0) {
        result += d;
    }
    
    return result;
}
