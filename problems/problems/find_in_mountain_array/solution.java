/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution {
    
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeak(mountainArr);
        
        // Search in left (ascending)
        int left = binarySearch(mountainArr, target, 0, peak, true);
        if (left != -1) return left;
        
        // Search in right (descending)
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }
    
    // Find Peak
    private int findPeak(MountainArray arr) {
        int left = 0, right = arr.length() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (arr.get(mid) < arr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    // Binary Search
    private int binarySearch(MountainArray arr, int target, int left, int right, boolean asc) {
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = arr.get(mid);
            
            if (val == target) return mid;
            
            if (asc) { // increasing
                if (val < target) left = mid + 1;
                else right = mid - 1;
            } else { // decreasing
                if (val < target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
}