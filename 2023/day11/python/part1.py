data = open('../in').read().split()

# Rows and columns that contain galaxies
row = []
column = []

# Position of galaxies (i,j)
galaxies = []

# Sum of all distances
res = 0

for i, line in enumerate(data):
    for j, c in enumerate(line):
        if c == '#':
            galaxies.append((i,j))
            if i not in row: row.append(i)
            if j not in column: column.append(j)

for i, G in enumerate(galaxies):
    for j, g in enumerate(galaxies):
        if j <= i: continue
        res += sum((abs(g[0] - G[0]), abs(g[1] - G[1])))

        # Find the range between G[0] and g[0]
        start = min(G[0], g[0]) + 1
        end = max(G[0], g[0])

        for num in range(start, end):
            if num not in row: 
                res += 1 

        # Find the range between G[1] and g[1]
        start = min(G[1], g[1]) + 1
        end = max(G[1], g[1])

        for num in range(start, end):
            if num not in column: 
                res += 1
        
print(res)