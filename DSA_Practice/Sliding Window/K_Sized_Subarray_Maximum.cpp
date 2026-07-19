class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {

        deque<int> dq;     // stores indices
        vector<int> ans;

        int i = 0, j = 0;

        while (j < arr.size()) {

            // Remove smaller elements from the back
            while (!dq.empty() && arr[dq.back()] <= arr[j])
                dq.pop_back();

            dq.push_back(j);

            if (j - i + 1 < k) {
                j++;
            }
            else {

                // Remove indices outside the current window
                while (!dq.empty() && dq.front() < i)
                    dq.pop_front();

                ans.push_back(arr[dq.front()]);

                i++;
                j++;
            }
        }

        return ans;
    }
};