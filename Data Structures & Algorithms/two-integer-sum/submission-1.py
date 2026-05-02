class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        for i, v in enumerate(nums):
            if target - v in hashMap:
                return [hashMap[target - v], i]
            hashMap[v] = i
        
        return [-1, -1]