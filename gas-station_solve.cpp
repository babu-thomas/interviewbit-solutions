int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    const vector<int> &gas = A;
    const vector<int> &cost = B;

    int n = gas.size();
    int tank_gas = 0, total_gas = 0, start_station = 0;
    for (int station = 0; station < n; station++) {
        int current_gas = gas[station] - cost[station];
        tank_gas += current_gas;
        total_gas += current_gas;
        if (tank_gas < 0) {
            start_station = station + 1;
            tank_gas = 0;
        }
    }

    if (total_gas < 0) {
        return -1;
    }

    return start_station;
}
