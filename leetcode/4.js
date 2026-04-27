/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    let merged = nums1.concat(nums2);
    merged.sort((a, b) => a - b);

    const n = merged.length;
    const mid = Math.floor(n / 2);

    if (n % 2 === 0) {
        return (merged[mid - 1] + merged[mid]) / 2;
    } else {
        return merged[mid];
    }
};