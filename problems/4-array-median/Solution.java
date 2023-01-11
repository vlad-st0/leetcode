import java.util.Arrays;

class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int lenMerged = len1 + len2;

        int[] numsMerged = new int[lenMerged];
        System.arraycopy(nums1, 0, numsMerged, 0, len1);
        System.arraycopy(nums2, 0, numsMerged, len1, len2);
        Arrays.sort(numsMerged);

        float median = 0;

        if (lenMerged % 2 == 0) {
            int index1 = lenMerged / 2;
            int index2 = index1 - 1;
            median = (float) (numsMerged[index1] + numsMerged[index2]) / 2;
        } else {
            int index = (int) Math.floor(lenMerged / 2);
            median = numsMerged[index];
        }

        return median;
    }
}