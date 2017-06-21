#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int findKth(int k, vector<int> nums1, vector<int> nums2, int s1, int s2){
    if(s1 >= nums1.size())
        return nums2[s2 + k - 1];
    if(s2 >= nums2.size())
        return nums1[s1 + k - 1];
    if(k == 1)
        return min(nums1[s1], nums2[s2]);
    int m1 = s1 + k / 2 - 1;
    int m2 = s2 + k / 2 - 1;
    int mid1 = m1 < nums1.size() ? nums1[m1] : INT_MAX;
    int mid2 = m2 < nums2.size() ? nums2[m2] : INT_MAX;
    if(mid1 < mid2)
        return findKth(k - k / 2, nums1, nums2, m1 + 1, s2);
    return findKth(k - k / 2, nums1, nums2, s1, m2 + 1);
}


double findMedian(vector<int> nums1, vector<int> nums2){
    int total = nums1.size() + nums2.size();
    if(total % 2 == 0)
        return (findKth(total/2, nums1, nums2, 0, 0) + findKth(total/2 + 1, nums1, nums2, 0, 0)) / 2.0;
    return findKth(total/2 + 1, nums1, nums2, 0, 0);
}

int main(int argc, char const *argv[]) {
    vector<int>nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    vector<int>nums2;
    nums2.push_back(6);
    nums2.push_back(7);
    nums2.push_back(8);
    nums2.push_back(9);
    nums2.push_back(10);
    nums2.push_back(11);
    cout<<findMedian(nums1, nums2)<<"\n";
    return 0;
}
