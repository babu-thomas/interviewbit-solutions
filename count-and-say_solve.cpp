// Time - O(N * S), Space - O(S)
// where N = the term number, S = number of digits in largest term
string Solution::countAndSay(int A) {
    if(A == 1) {
        return "1";
    }

    string prev = "1";
    string result;

    for(int term = 2; term <= A; term++) {
        int n = prev.size();

        char digit = prev[0];
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(prev[i] == digit) {
                count++;
            }
            else {
                result.push_back(count + '0');
                result.push_back(digit);
                digit = prev[i];
                count = 1;
            }
        }

        // Push the count of last digit as loop terminates before last contiguous sequence ends
        result.push_back(count + '0');
        result.push_back(digit);

        prev = result;
        result.clear();
    }

    return prev;
}



// Shorter solution, same complexity
string generate_term(const string& s) {
    int n = s.size();
    int count = 0;
    string result;
    for(int i = 0; i < n; i++) {
        count++;

        // If contiguous sequence of same characters ends here or if string ends here
        if(s[i] != s[i + 1] || i + 1 == n) {
            result.push_back(count + '0');
            result.push_back(s[i]);
            count = 0;
        }
    }

    return result;
}

// Time - O(N * S), Space - O(S)
// where N = the term number, S = number of digits in largest term
string Solution::countAndSay(int A) {
    if(A == 1) {
        return "1";
    }
    
    // First term
    string result = "1";

    for(int i = 2; i <= A; i++) {
        result = generate_term(result);
    }

    return result;
}
