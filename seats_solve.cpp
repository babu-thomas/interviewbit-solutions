#define MOD 10000003

// Time - O(N), Space - O(1)
int Solution::seats(string A) {
    const string& seats = A;

    int n = seats.size();
    int occupied_total = count(seats.begin(), seats.end(), 'x');
    int occupied_found = 0, vacant_seats = 0;
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(seats[i] == 'x') {
            if(vacant_seats != 0) {
                int right_moves = (occupied_found % MOD) * (vacant_seats % MOD);
                int left_moves = ((occupied_total - occupied_found) % MOD) * (vacant_seats % MOD);
                result = (result + min(right_moves, left_moves)) % MOD;
                vacant_seats = 0;
            }

            occupied_found++;
        }
        else {
            vacant_seats++;
        }
    }

    return result;
}
