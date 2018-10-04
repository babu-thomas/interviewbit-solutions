#include<bits/stdc++.h>

using namespace std;

#define DEBUG(x) do { std::cout << #x << ": " << x << " "; } while (0)
#define DEBUGL(x) do { std::cout << #x << ": " << x << "\n"; } while (0)

template<typename T>
void print_vector(vector<T> a)
{
    for(auto& i: a) {
        cout << i << " ";
    }
    cout << "\n";
}

template<typename T>
void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for(auto& i: a) {
        cout << r << ": ";
        for(auto& j: i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

// Time - O(N * S), Space - O(S)
// where N = the term number, S = number of digits in largest term
string solve(int A) {
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

        // DEBUGL(result);
        prev = result;
        result.clear();
    }

    return prev;
}

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
string solve_short(int A) {
    // A is the term number
    
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

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int num = 4;

    cout << solve(num) << "\n";
    cout << solve_short(num) << "\n";

    return 0;
}
