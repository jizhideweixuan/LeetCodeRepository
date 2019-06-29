# 3Sum
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

* 注意：

    答案中不可以包含重复的三元组。

例如,给定数组 nums = [-1, 0, 1, 2, -1, -4]

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

* 提示:排序后, 遍历low右边的所有双数组合,求 -nums[low] = nums[mid] + nums[high]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。