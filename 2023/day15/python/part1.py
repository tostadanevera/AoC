data = open('../in').read().split(',')

sol = 0

for element in data:
    aux = 0
    for c in element:
        aux = (aux + ord(c)) * 17 % 256
    sol += aux

print(sol)