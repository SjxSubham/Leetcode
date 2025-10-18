class Solution {
public:
  bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(begin(workers), begin(workers) + mid); //best mid workers

        for(int i = mid-1; i >= 0; i--) {
            int reqrd = tasks[i];
            auto it   = prev(st.end());

            if(*it >= reqrd) {
                st.erase(it);
            } else if(pillsUsed >= pills) {
                return false;
            } else {
                //find the weakest worker which can do this strong task using pills
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if(weakestWorkerIt == st.end()) {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m, n);

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(tasks, workers, pills, strength, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;

   
    }
};
