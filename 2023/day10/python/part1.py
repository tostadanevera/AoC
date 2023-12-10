data = open('../in').read().split()

matrix = [list(line) for line in data]

visited = [[False] * len(matrix[0]) for _ in range(len(matrix))]

moves = {
    '|': [(1, 0), (-1, 0)],
    '-': [(0, 1), (0, -1)],
    'L': [(0, 1), (-1, 0)],
    'J': [(0, -1), (-1, 0)],
    '7': [(0, -1), (1, 0)],
    'F': [(0, 1), (1, 0)],
    '.': []
}

def valid(x, y):
    return 0 <= x < len(matrix) and 0 <= y < len(matrix[0])

# Find position of S
for i, line in enumerate(data):
    for j, c in enumerate(line):
        if c == 'S':
            s = (i, j)
            visited[i][j] = True
            break

stack = []
path = [s]

# Find next two positions of S
(i, j) = s
if matrix[i][j-1] == '-' or matrix[i][j-1] == 'L' or matrix[i][j-1] == 'F': # (0,1)
    path.append((i, j - 1))
    stack.append((i, j - 1))
    visited[i][j - 1] = True
if matrix[i-1][j] == '|' or matrix[i-1][j] == '7' or matrix[i-1][j] == 'F': # (1,0)
    path.append((i - 1, j))
    stack.append((i - 1, j))
    visited[i - 1][j] = True
if matrix[i][j+1] == '-' or matrix[i][j+1] == 'J' or matrix[i][j+1] == '7': # (0,-1)
    path.append((i, j + 1))
    stack.append((i, j + 1))
    visited[i][j + 1] = True
if matrix[i+1][j] == '|' or matrix[i+1][j] == 'L' or matrix[i+1][j] == 'J': # (-1,0)
    path.append((i + 1, j))
    stack.append((i + 1, j))
    visited[i + 1][j] = True

while stack:
    x, y = stack.pop()

    for move in moves[matrix[x][y]]:
        dx, dy = move
        nx, ny = x + dx, y + dy

        if valid(nx, ny) and not visited[nx][ny] and matrix[nx][ny] != '.':
            visited[nx][ny] = True
            path.append((nx, ny))
            stack.append((nx, ny))

print(len(path) // 2)