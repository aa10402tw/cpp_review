#include <iostream>
#include <vector>
#include <algorithm>

/* Find k-th element of two sorted array A1 and A2
* 
Idea: compare the (k/2)-th element of A1 and A2 (v1 and v2)
search for (k-(k/2)) element in 
	A1[:], A2[(k/2):] if v1 > v2   (since A1[k] >= all A2[:(k/2)] and A2[(k/2):] >= all A2[:(k/2)])
	A1[(k/2):], A2[:] if v1 <= v2  (since A2[k] >= all A1[:(k/2)] and A1[(k/2):] >= all A1[:(k/2)])

Edge Case:
	A1 is empty: return k-th element in A2 
	k == 1: return min(A1[0], A2[0])
	len(A1) < (k/2):  search for (k-(k/2)) element in (A1, A2[(k/2):])
*/
double findKth(std::vector<int>& nums1, std::vector<int>& nums2, int s1, int s2, int k) {
	int m = nums1.size();
	int n = nums2.size();
	if (s1 >= m) return nums2[s2 + k - 1];
	if (s2 >= n) return nums1[s1 + k - 1];
	if (k == 1) return std::min(nums1[s1], nums2[s2]);
	if (m-s1 < k/2) return findKth(nums1, nums2, s1, s2 + k / 2, k - k / 2);
	if (n-s2 < k/2) return findKth(nums1, nums2, s1 + k / 2, s2, k - k / 2);
	int v1 = nums1[s1 + k / 2 - 1];
	int v2 = nums2[s2 + k / 2 - 1];
	if (v1 > v2) return findKth(nums1, nums2, s1, s2 + k / 2, k - k / 2);
	else return findKth(nums1, nums2, s1 + k / 2, s2 , k - k / 2);
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	/* If m+n is odd, k1 will equal to k2 */
	double k1 = (m + n + 1) / 2;
	double k2 = (m + n + 2) / 2;
	return (findKth(nums1, nums2, 0, 0, k1) + findKth(nums1, nums2, 0, 0, k2)) / 2.0;
}

int main() {
	std::vector<int> nums1 = { 1,2 };
	std::vector<int> nums2 = { 3,4 };
	findMedianSortedArrays(nums1, nums2);
}
