#include <stdio.h>


// 给一个整数数组nums，将数组中的元素向右移动k个位置，其中k是非负数。
// 例如，给定 nums = [1,2,3,4,5,6,7]，k = 3，应该返回 [5,6,7,1,2,3,4]。

void rotate(int* nums, int numsSize, int k)
{
    while (k--)
    {
        int tmp = nums[numsSize - 1];
        for (int i = numsSize - 1; i > 0; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = tmp;
    }
}



// 算法的时间复杂度

// 函数式T(n) = O(n*k)
// 空间复杂度S(n) = O(1)























