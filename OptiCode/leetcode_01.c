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
    int min = 2147483647;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
    }
    int max = target - min;
    int len = max - min + 1;    //确定hash长度  
    int *table = (int*)malloc(len*sizeof(int));
    int *indice = (int*)malloc(2*sizeof(int));
    for (i = 0; i < len; i++) {
        table[i] = -1;        //hash初值  
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i]-min < len) {
            if (table[target-nums[i]-min] != -1) {   //满足相加为target  
                indice[0] = table[target-nums[i] - min];
                indice[1] = i;
                free(table);
                return indice;
            }
            table[nums[i]-min] = i;
        }
    }
    free(table);
    return indice;
}
