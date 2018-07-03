vector<int> Solution::primesum(int A) {
    vector<bool> primes(A + 1, true);
    primes[0] = false;
    primes[1] = false;
    int sqrt_a = sqrt(A);
    for(int i = 2; i <= sqrt_a; i++) {
        if(primes[i]) {
            for(int j = 2; i * j <= A; j++) {
                primes[i * j] = false;
            }
        }
    }
    vector<int> result;
    for(int i = 2; i <= A; i++) {
        if(primes[i] && primes[A - i]) {
            result.push_back(i);
            result.push_back(A - i);
            return result;
        }
    }
    
    return result;
}
