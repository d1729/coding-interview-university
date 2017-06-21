package com.Debarshi.Array;

/**
 * Created by debarshighosh on 10/06/17.
 * Find the median of two sorted Arrays of size m and n
 */
public class sortedMedian {

    public static double findMedian(int[] nums1, int[] nums2){
        int total = nums1.length + nums2.length;
        if (total % 2 == 0)
            return (findKth(total / 2, nums1, nums2, 0, 0) + findKth(total / 2 + 1, nums1, nums2, 0, 0)) / 2.0;
        return findKth(total / 2 + 1, nums1, nums2, 0, 0);
    }

    public static int findKth(int k, int[] nums1, int[] nums2, int s1, int s2){
        if(s1 >= nums1.length)
            return  nums2[s2 + k - 1];
        if(s2 >= nums2.length)
            return  nums1[s1 + k - 1];
        if(k == 1)
            return Math.min(nums1[s1], nums2[s2]);
        int m1 = s1 + k / 2 - 1;
        int m2 = s2 + k / 2 - 1;
        int mid1 = m1 < nums1.length ? nums1[m1] : Integer.MAX_VALUE;
        int mid2 = m2 < nums2.length ? nums2[m2] : Integer.MAX_VALUE;
        if (mid1 < mid2)
            return findKth(k - k / 2, nums1, nums2, m1 + 1, s2);
        return findKth(k - k / 2, nums1, nums2, s1, m2 + 1);
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 4, 5};
        int[] nums2 = {6, 7, 8, 9, 10, 11};
        System.out.println(findMedian(nums1, nums2));
    }
}
