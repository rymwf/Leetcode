/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

    Choose one integer x from either the start or the end of the array nums.
    Add multipliers[i] * x to your score.
    Remove x from the array nums.

Return the maximum score after performing m operations.

 

Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.

Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.

 

Constraints:

    n == nums.length
    m == multipliers.length
    1 <= m <= 103
    m <= n <= 105
    -1000 <= nums[i], multipliers[i] <= 1000
*/
#include "common.h"
class Solution
{
public:
	/**
	 * @brief  使用dp，前面取i个，后面取j个
	 * 		当i==0时，dp[i][j]=dp[i][j-1]+nums[n-j]*multipliers[i+j-1];
	 * 		当i==k时，dp[i][j]=dp[i-1][j]+nums[i-1]*multipliers[i+j-1];
	 * 		否则，dp[i][j]=max(a,b);
	 * 
	 * @param nums 
	 * @param multipliers 
	 * @return int 
	 */
	int maximumScore(vector<int> &nums, vector<int> &multipliers)
	{
		int m = multipliers.size(), n = nums.size();
		vector<vector<int>> dp(m + 1, vector<int>(m + 1));
		int ret{INT_MIN};
		for (int k = 1; k <= m; ++k)
		{
			for (int i = 0; i <= k; ++i)
			{
				auto j = k - i;
				if (i == 0)
					dp[i][j] = dp[i][j - 1] + nums[n - j] * multipliers[k - 1];
				else if (i == k)
					dp[i][j] = dp[i - 1][j] + nums[i - 1] * multipliers[k - 1];
				else
					dp[i][j] = max(dp[i][j - 1] + nums[n - j] * multipliers[k - 1],
								   dp[i - 1][j] + nums[i - 1] * multipliers[k - 1]);
				if (k == m)
					ret = max(ret, dp[i][j]);
			}
		}
		return ret;
	}
	int maximumScore2(vector<int> &nums, vector<int> &multipliers)
	{
		int m = multipliers.size(), n = nums.size();
		vector<int> dp(m + 1);
		int ret{INT_MIN};
		for (int k = 1; k <= m; ++k)
		{
			for (int i = k; i >= 0; --i)
			{
				auto j = k - i;
				if (i == 0)
					dp[i] += nums[n - j] * multipliers[k - 1];
				else if (i == k)
					dp[i] = dp[i - 1] + nums[i - 1] * multipliers[k - 1];
				else
					dp[i] = max(dp[i] + nums[n - j] * multipliers[k - 1],
								dp[i - 1] + nums[i - 1] * multipliers[k - 1]);
				if (k == m)
					ret = max(ret, dp[i]);
			}
		}
		return ret;
	}
};

int main()
{
	vi nums = {-5, -3, -3, -2, 7, 1}, multipliers = {-10, -5, 3, 4, 6};
	//vi nums = {-854, -941, 10, 299, 995, -346, 294, -393, 351, -76, 210, 897, -651, 920, 624, 969, -629, 985, -695, 236, 637, -901, -817, 546, -69, 192, -377, 251, 542, -316, -879, -764, -560, 927, 629, 877, 42, 381, 367, -549, 602, 139, -312, -281, 105, 690, -376, -705, -906, 85, -608, 639, 752, 770, -139, -601, 341, 61, 969, 276, 176, -715, -545, 471, -170, -126, 596, -737, 130};
	//vi multipliers = {83, 315, -442, -714, 461, 920, -737, -93, -818, -760, 558, -584, -358, -228, -220};

	Solution s;
	auto res = s.maximumScore2(nums, multipliers);
	dbg(res);
}
