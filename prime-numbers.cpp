// Sieve of Eratosthenes, Time Complexity - O(log log N)

vector<int> Solution::sieve(int A) {
    vector<bool> primes(A + 1, 1);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i <= sqrt(A); i++) {
        if(primes[i]) {
            for(int j = 2; i * j <= A; j++) {
                primes[i * j] = false;
            }
        }
    }
    
    vector<int> result;
    for(int i = 0; i <= A; i++) {
        if(primes[i]) {
            result.push_back(i);
        }
    }
    
    return result;
}
