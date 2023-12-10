data = open('../in').read().split('\n')

sum = 0

def calc(nums):
    if all(n == 0 for n in nums): return 0
    else:
        aux = []
        for i in range(1, len(nums)):
            aux.append(nums[i] - nums[i - 1])
        return nums[0] - calc(aux)

for line in data:
    nums = list(map(int, line.split()))
    sum += calc(nums)
        
print(sum)