def quadratic(a, b, c):
    x1 = (-b + (b ** 2 - 4 * a * c) ** 0.5) / (2 * a)
    x2 = (-b - (b ** 2 - 4 * a * c) ** 0.5) / (2 * a)
    return (x1, x2)

a = int(input("a = "))
b = int(input("b = "))
c = int(input("c = "))

(x1, x2) = quadratic(a, b, c)
print("x = ", x1, ",", x2)