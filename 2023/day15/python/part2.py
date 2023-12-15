data = open('../in').read().split(',')

focalLength = {}

boxes = [[] for _ in range(256)]

def hashALgorithm(label):
    aux = 0
    for c in label:
        aux = (aux + ord(c)) * 17 % 256
    return aux

for element in data:
    if '=' in element:
        label, content = element.split('=')
        box = hashALgorithm(label)
        if label not in boxes[box]:
            boxes[box].append(label)
        focalLength[label] = int(content)
    else:
        label = element.split('-')[0]
        box = hashALgorithm(label)
        if label in boxes[box]:
            boxes[box].remove(label)

sol = 0

for i, box in enumerate(boxes):
    if box:
        for j, element in enumerate(box):
            sol += (i+1) * (j+1) * focalLength[element]

print(sol)