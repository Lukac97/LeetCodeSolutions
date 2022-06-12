#include "Includes.h"

pair<int, int> findRoughMedian(const vector<int>& nums, int start, int end)
{
	int mid = (start - end) / 2;
	return make_pair(nums[mid], mid);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int leftChunkSize = (int) ceil((nums1.size() + nums2.size()) / 2.0);

	int end1 = min(leftChunkSize, nums1.size());
	int prevEnd1 = end1;

	while (true)
	{
		if (end1 > 0 && leftChunkSize - end1 < nums2.size() && nums1[end1 - 1] > nums2[leftChunkSize - end1])
		{
			int temp = end1;
			end1 = (prevEnd1 / 2);

			if (leftChunkSize - end1 >= nums2.size())
			{
				end1 = leftChunkSize - nums2.size();
			}

			prevEnd1 = temp;
		}
		else if (leftChunkSize - end1 > 0 && end1 < nums1.size() && nums2[leftChunkSize - end1 - 1] > nums1[end1])
		{
			end1 = end1 + (prevEnd1 - end1) / 2;
		}
		else
		{
			break;
		}
	}

	if ((nums1.size() + nums2.size()) % 2 == 0)
	{
		int leftNum;
		int rightNum;
		if (end1 <= 0)
		{
			leftNum = nums2[leftChunkSize - end1 - 1];
		}
		else if (leftChunkSize - end1 <= 0)
		{
			leftNum = nums1[end1 - 1];
		}
		else
		{
			leftNum = max(nums1[end1 - 1], nums2[leftChunkSize - end1 - 1]);
		}

		if (end1 >= nums1.size())
		{
			rightNum = nums2[leftChunkSize - end1];
		}
		else if (leftChunkSize - end1 >= nums2.size())
		{
			rightNum = nums1[end1];
		}
		else
		{
			rightNum = min(nums1[end1], nums2[leftChunkSize - end1]);
		}

		return (leftNum + rightNum) / 2.0;
	}
	else
	{
		if (end1 <= 0)
		{
			return nums2[leftChunkSize - end1 - 1];
		}
		if (leftChunkSize - end1 <= 0)
		{
			return nums1[end1 - 1];
		}

		return max(nums1[end1 - 1], nums2[leftChunkSize - end1 - 1]);
	}

}
