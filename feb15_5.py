def chome(n):
    return [(x, y) for x in range(n) for y in range(n) if x <= y if (x + y) % 3 == 0 ]

print(chome(7))