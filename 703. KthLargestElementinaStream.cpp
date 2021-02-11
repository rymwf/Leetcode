/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Returns the element representing the kth largest element in the stream.

 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

 

Constraints:

    1 <= k <= 104
    0 <= nums.length <= 104
    -104 <= nums[i] <= 104
    -104 <= val <= 104
    At most 104 calls will be made to add.
    It is guaranteed that there will be at least k elements in the array when you search for the kth element.
*/
#include "common.h"
class KthLargest
{

	priority_queue<int, vector<int>, greater<int>> _a;
	int _k;
public:
	void helper(vector<int> &nums, int l, int r)
	{
		if (l > r)
			return;
		int m = (l + r + 1) >> 1;
		swap(nums[m], nums[r]);
		int p = l;
		for (int i = l; i < r; ++i)
		{
			if (nums[i] > nums[r])
			{
				swap(nums[i], nums[p]);
				++p;
			}
		}
		swap(nums[p], nums[r]);
		if (p < _k)
			helper(nums, p + 1, r);
		else if (p > _k)
			helper(nums, l, p - 1);
	}
	KthLargest(int k, vector<int> &nums) : _k(k)
	{
		//sort(nums.begin(),nums.end(),greater<int>());
		helper(nums, 0, nums.size() - 1);
		_a = priority_queue<int, vector<int>, greater<int>>{nums.begin(), nums.begin() + min(k, static_cast<int>(nums.size()))};
	}

	int add(int val)
	{
		if (_a.size() < _k)
		{
			_a.emplace(val);
		}
		else
		{
			if (_a.top() >= val)
				return _a.top();
			_a.pop();
			_a.emplace(val);
		}
		return _a.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
	vi a{0};
	KthLargest s(2, a);
	dbgvec(a);
	dbg(s.add(-1));
}