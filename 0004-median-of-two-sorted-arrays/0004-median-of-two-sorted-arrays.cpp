#include <iostream>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 항상 nums1을 더 작은 배열로 만들어 효율성 증가
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        
        while (low <= high) {
            // nums1 배열의 분할 위치
            int partitionX = (low + high) / 2;
            // nums2 배열의 분할 위치 (전체 중간값에서 partitionX를 뺀 값)
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            // nums1 왼쪽 파티션의 최대값
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            // nums1 오른쪽 파티션의 최소값
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            // nums2 왼쪽 파티션의 최대값
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            // nums2 오른쪽 파티션의 최소값
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // 올바른 파티션을 찾은 경우
            if (maxX <= minY && maxY <= minX) {
                // 전체 크기가 홀수인 경우
                if ((x + y) % 2 != 0) {
                    return max(maxX, maxY);
                }
                // 전체 크기가 짝수인 경우
                else {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                }
            }
            // 왼쪽으로 이동
            else if (maxX > minY) {
                high = partitionX - 1;
            }
            // 오른쪽으로 이동
            else {
                low = partitionX + 1;
            }
        }
        
        // 도달할 수 없는 지점
        return 0.0;
    }
};