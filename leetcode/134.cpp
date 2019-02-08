// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 134
class Solution {
public:
    bool simulate(vector<int>& diffs, int start) {
        int tot = 0;
        for(int i = 0; i < diffs.size(); ++i) {
            tot += diffs[start];
            start = start < diffs.size() - 1 ? start + 1 : 0;
            if(tot < 0) return false;
        }
        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gas_tot = 0;
        int cost_tot = 0;
        for(int i = 0; i < n; ++i) {
            gas_tot += gas[i];
            cost_tot += cost[i];
        }
        if(gas_tot < cost_tot) return -1;
        
        vector<int> diffs(n);
        for(int i = 0; i < n; ++i) {
            diffs[i] = gas[i] - cost[i];
        }
        int i = 0;
        while(i < n) {
            while(i < n && diffs[i] < 0) {
                ++i;
            }
            if(simulate(diffs, i)) return i;
            while(i < n && diffs[i] >= 0) {
                ++i;
            }
        }
        return -1;
    }
};
