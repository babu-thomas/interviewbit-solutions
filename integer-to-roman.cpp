void append_times(int n, string val, string& A) {
    for(int i = 0; i < n; i++) {
        A.append(val);
    }
}

string Solution::intToRoman(int A) {
    unordered_map<int, string> value = {
        {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
        {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}
    };
    
    string result;
    vector<int> digits;
    int num = A;
    int divisor = 1000;
    while(divisor != 0) {
        digits.push_back(num / divisor);
        num %= divisor;
        divisor /= 10;
    }
    
    int place_value = 1000;
    for(int i = 0; i < digits.size(); i++) {
        int d = digits[i];
        if(d == 0) {
            place_value /= 10;
            continue;
        }
        
        int num = d * place_value;
        if(value.count(num)) {
            result.append(value[num]);
            place_value /= 10;
        }
        else {
            int rem = d % 5;
            if(num > 1000) {
                append_times(d, value[1000], result);
            }
            else if(num > 500) {
                result.append(value[500]);
                append_times(rem, value[100], result);
            }
            else if(num > 100) {
                append_times(d, value[100], result);
            }
            else if(num > 50) {
                result.append(value[50]);
                append_times(rem, value[10], result);
            }
            else if(num > 10) {
                append_times(d, value[10], result);
            }
            else if(num > 5) {
                result.append(value[5]);
                append_times(rem, value[1], result);
            }
            else {
                append_times(d, value[1], result);
            }
            
            place_value /= 10;
        }
    }
    
    return result;
}
