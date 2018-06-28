 /**
* 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
* 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
* 
* 示例:
* 
* 给定 nums = [2, 7, 11, 15], target = 9

* 因为 nums[0] + nums[1] = 2 + 7 = 9
* 所以返回 [0, 1]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    static int res[2] = {0};
    int i, j;
    for(i = 0 ; i < numsSize; ++i) {
        for (j = i + 1; j < numsSize; ++j) {
            if (nums[i] == target - nums[j]) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
        
    }
    
    return res;
}
