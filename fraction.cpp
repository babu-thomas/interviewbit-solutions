string solve_fraction_to_decimal(int numerator, int denominator) {
    if(numerator == 0) {
        return "0";
    }

    long long num = abs((long) numerator);
    long long den = abs((long) denominator);

    bool is_negative = (numerator < 0) ^ (denominator < 0);
    string result;

    if(is_negative) {
        result += "-";
    }

    long long whole_part = num / den;
    result += to_string(whole_part);

    long long rem = num % den;

    if(rem == 0) {
        return result;
    }

    result += ".";
    unordered_map<long long, long long> rem_positions;
    long long repeat_index;
    bool is_repeating = false;
    while(rem > 0 && !is_repeating) {
        if(rem_positions.count(rem)) {
            repeat_index = rem_positions[rem];
            is_repeating = true;
            break;
        }
        else {
            rem_positions[rem] = result.size();
        }

        rem *= 10;
        long long quotient = rem / den;
        result += to_string(quotient);
        rem = rem % den;
    }

    if(is_repeating) {
        result.insert(repeat_index, "(");
        result += ")";
    }

    return result;
}

string Solution::fractionToDecimal(int A, int B) {
    return solve_fraction_to_decimal(A, B);
}
