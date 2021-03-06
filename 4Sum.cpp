#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] < target - nums[i] - nums[j])
                        left++;
                    else if (nums[left] + nums[right] > target - nums[i] - nums[j])
                        right--;
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return res;
    }
};
//int main()
//{
//    vector<int> nums = { 1,0,-1,0,-2,2 };
//    int target = 0;
//    Solution sl;
//    vector<vector<int>> res=sl.fourSum(nums, target);
//    for (int i = 0; i < res.size(); i++)
//    {
//        for (int j = 0; j < res[0].size(); j++)
//            cout << res[i][j] << " ";
//        cout << endl;
//    }
//}