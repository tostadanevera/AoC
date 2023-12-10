data = open('../in').read().split('\n')

sum = 0

def calc(nums):
    if all(n == 0 for n in nums): return 0
    else:
        aux = []
        for i in range(len(nums) - 1):
            aux.append(nums[i + 1] - nums[i])
        return calc(aux) + nums[len(nums) - 1]

for line in data:
    nums = list(map(int, line.split()))
    sum += calc(nums)
        
print(sum)
