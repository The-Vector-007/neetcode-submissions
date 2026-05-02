class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashMap = {}
        for num in nums:
            if num not in hashMap:
                hashMap[num] = 1
            else:
                hashMap[num] += 1
        
        ans = list(hashMap.items())

        ans.sort(key = lambda x: x[1])
        
        return [x[0] for x in ans[-k:]]

        