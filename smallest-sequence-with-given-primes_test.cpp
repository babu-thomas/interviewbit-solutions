#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)                                                               \
    do {                                                                       \
        std::cout << #x << ": " << x << " ";                                   \
    } while (0)
#define DEBUGL(x)                                                              \
    do {                                                                       \
        std::cout << #x << ": " << x << "\n";                                  \
    } while (0)

#define MOD 1000000007

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for (auto &i : a) {
        cout << r << ": ";
        for (auto &j : i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

// Time - O(N LogN), Space - O(N)
// where N is the number of integers to generate.
vector<int> solve(const vector<int> &A, int B) {
    const vector<int> &primes = A;
    int nums_count = B;
    unordered_set<int> found_nums(primes.begin(), primes.end());
    priority_queue<int, vector<int>, greater<int>> next_num(found_nums.begin(),
                                                            found_nums.end());
    vector<int> result;
    while (result.size() != nums_count) {
        int cur_num = next_num.top();
        next_num.pop();
        for (auto &p : primes) {
            if (found_nums.count(cur_num * p) == 0) {
                next_num.push(cur_num * p);
                found_nums.insert(cur_num * p);
            }
        }
        result.push_back(cur_num);
    }

    return result;
}

// Time - O(N * P), Space - O(N + P)
// where N is the number of integers to generate and P is the number of primes
// given.
vector<int> solve_linear(const vector<int> &A, int B) {
    const vector<int> &primes = A;
    int nums_count = B;
    vector<int> candidate_terms = primes;
    vector<int> term_indices(primes.size(), 0);
    vector<int> result;
    for (int count = 0; count < nums_count; count++) {
        int next_term =
            *min_element(candidate_terms.begin(), candidate_terms.end());
        result.push_back(next_term);

        for (int t = 0; t < candidate_terms.size(); t++) {
            if (candidate_terms[t] == next_term) {
                candidate_terms[t] = primes[t] * result[term_indices[t]];
                term_indices[t]++;
            }
        }
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> primes1{2, 3, 5};

    // Solution - 19, 31, 361, 589, 961, 6859, 11191, 18259, 29791, 130321
    vector<int> primes2{19, 31, 31};

    int nums_count = 10;
    print_vector(solve(primes1, nums_count));
    print_vector(solve(primes2, nums_count));

    print_vector(solve_linear(primes1, nums_count));
    print_vector(solve_linear(primes2, nums_count));

    return 0;
}
