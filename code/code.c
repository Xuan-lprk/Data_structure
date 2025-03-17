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

// 时间复杂度：O(n的平方)
// 时间复杂度较高，可以优化

void rotate_new(int* nums, int numsSize, int k)
{
    // 创建新数组
    int new_nums[numsSize];
    // 将原数组中的元素放到新数组中
    for (int i = 0; i < numsSize; i++)
    {
        new_nums[(i + k) % numsSize] = nums[i];  // 通过取余数的方式，将元素放到新数组中
    }
    // 将新数组中的元素放到原数组中
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = new_nums[i];
    } 

}

// 时间复杂度：O(n)



// 线性表

// 线性表是一种数据结构，它是由n个数据元素组成的有限序列。



// 只要在调用函数时没在实参中使用&，那么就是值传递
// 如果在调用函数时在实参中使用&，那么就是地址传递
// 传递的是地址，那么在函数中对形参的修改会影响实参
// 传递的是值，那么在函数中对形参的修改不会影响实参
 

int main()
{


    return 0;
}
