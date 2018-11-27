class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( !n )
            return 0;
        
        int* a = new int[n+1];
        a[0] = 0;
        a[1] = nums[0];
        
        for(int i=2; i<=n; i++) {
            a[i] = (a[i-1] > a[i-2] + nums[i-1])?
                    a[i-1]: a[i-2] + nums[i-1];
        }
        return a[n];
    }
};
