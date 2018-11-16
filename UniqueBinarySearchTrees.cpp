class Solution {
public:
    int a[1000];
    int numTrees(int n) {
        a[1] = 1; a[2] = 2;
        for(int i=3; i<=n; i++) {
            a[i] = 0;
            a[i] += 2*a[i-1];
            int sum = 0;
            for(int j=1; j<i-1; j++) {
                sum += a[j]*a[i-1-j];
            }
            a[i] += sum;
        }
        return a[n];
    }
};
