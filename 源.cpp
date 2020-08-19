#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        if (length <= 1)return 0;
        if (length == 2)return min(height[0], height[1]);
        int ans = (length-1)*min(height[0],height[length-1]);
        for (int i = 0; i < length - 1; i++) {
            if (height[i] == 0)continue;
            for (int j = i + ans / height[i] ; j < length; j++)
                ans = max(ans, (j - i) * min(height[i], height[j]));
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int>num = { 6,14,2,11,2,7,0,9,12,7 };
    cout << sol.maxArea(num);
    return 0;
}