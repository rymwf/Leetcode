/*
In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.

 

Example 1:

Input: A = [0,1,0], K = 1
Output: 2
Explanation: Flip A[0], then flip A[2].

Example 2:

Input: A = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].

Example 3:

Input: A = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation:
Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]

 

Note:

    1 <= A.length <= 30000
    1 <= K <= A.length
*/
#include "common.h"
class Solution
{
public:
	int minKBitFlips(vector<int> &A, int K)
	{
		vector<int> counts(K);
		counts[0] = !A[0];
		int len = A.size();
		int last = len - K + 1;
		int i{};
		for (i = 1; i < last; ++i)
		{
			auto a = i % K;
			auto b = (i - 1) % K;
			counts[a] = counts[b] + (A[i] == ((counts[b] - counts[a]) % 2));
		}
		int c = counts[(last - 1) % K];
		for (i = last; i < len; ++i)
		{
			if (A[i] == ((c - counts[i % K]) % 2))
				return -1;
		}
		return counts[(last - 1) % K];
	}
	int minKBitFlips2(vector<int> &A, int K)
	{
		auto beg = A.begin(), it = beg;
		*it = !*it;
		++it;
		int a, b;
		auto third = A.end() - K + 1;
		for (; it != third; ++it)
		{
			a = *(it - 1);
			if (it - beg < K)
				b = 0;
			else
				b = *(it - K);

			if (*it == (a - b) % 2)
				*it = a + 1;
			else
				*it = a;
		}
		for (auto end = A.end(); it != end; ++it)
		{
			if (it - beg < K)
				a = 0;
			else
				a = *(it - K);
			if (*it == (*(third - 1) - a) % 2)
				return -1;
		}
		return *(third - 1);
	}
	int minKBitFlips3(vector<int> &A, int K)
	{
		vector<int> diff(A.size() + 1);
		int ret{};
		int count{};
		for (auto it = A.begin(), end = A.end(), it2 = diff.begin(), second = diff.end() - K;
			 it != end;
			 ++it, ++it2)
		{
			count += *it2;
			if (*it == count % 2)
			{
				if (it2 >= second)
					return -1;
				--*(it2 + K);
				++ret;
				++count;
			}
		}
		return ret;
	}
	int minKBitFlips4(vector<int> &A, int K)
	{
		queue<int> q;
		int ans = 0;
		for (int i = 0; i < A.size(); i++)
		{
			// 维护长度为K的窗口
			if (!q.empty() && q.front() + K == i)
				q.pop();
			//判断当前位置是否需要翻转
			if (q.size() % 2 == A[i])
			{
				if (i + K > A.size())
					return -1;
				ans++;
				q.push(i);
			}
		}
		return ans;
	}
};

int main()
{
	vi a{1, 0};
	//vi a{0,0,1};
	//vi a{0, 0, 0, 1, 0, 1, 1, 0};
	int K = 2;
	Solution s;
	s.minKBitFlips2(a, K);
}