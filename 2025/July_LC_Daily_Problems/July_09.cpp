#include <vector>
#include <algorithm>
using namespace std;
// Dont copy the above lines just copy the below solution
// LeetCode Problem No:- 3439

class Solution {
public:
    static int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int n=startTime.size();
        int busy=0;
        for (int i=0; i < k; i++) 
            busy+=endTime[i]-startTime[i];

        if (n==k) return eventTime-busy;

        int ans=startTime[k]-busy;

        for (int l=0, r=k; r<n; l++, r++) {
            busy+=(endTime[r]-startTime[r])-(endTime[l]-startTime[l]);
            int end=(r==n-1)?eventTime:startTime[r+1];
            int start=endTime[l];
            ans=max(ans, end-start-busy);
        }
        return ans;
    }
};

