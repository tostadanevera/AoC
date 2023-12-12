data = open('../in').read().split('\n')

cache = {}

def solve(str, nums):
    if (str, tuple(nums)) in cache:
        return cache[(str, tuple(nums))]

    if len(nums) == 0:
        return 1 if '#' not in str else 0

    size = nums[0]
    sol = 0

    for i in range(len(str)):
        if (
            i + size <= len(str) 
            and all(c != '.' for c in str[i : i + size]) 
            and (i == 0 or str[i - 1] != '#') 
            and (i + size == len(str) or str[i + size] != '#')
        ):
            sol += solve(str[i + size + 1:], nums[1:])
        
        if str[i] == "#":
            break;
    
    cache[(str, tuple(nums))] = sol
    return sol

res = 0

for line in data:
    condition, numbers = line.split()
    condition = '?'.join([condition] * 5)
    numbers = list(map(int, numbers.split(','))) * 5
    res += solve(condition, numbers)
    
print(res)