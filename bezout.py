def bezout(a, b, c):
    if b == 0:
        if c % a == 0:
            return (c // a, 0)
        else:
            return (0, 0)
    else:
        r = a % b
        (x, y) = bezout(b, r ,c)
        if x == 0 and y == 0:
            return (0, 0)
        else:
            q = a // b
            return (y, x - q * y)

while True:
    a = int(input('正の整数 a を入力してください: '))
    b = int(input('正の整数 b を入力してください: '))
    c = int(input('0 でない整数 c を入力してください: '))
    if c == 0:
        print('終了します')
        break
    (x, y) = bezout(a, b, c)
    if x == 0 and y == 0:
        print(a, ' * x + ', b, ' * y = ', c, ' の解は存在しません。')
    else:         
        print(a, ' * ', x, ' + ', b, ' * ', y, ' = ', c, ' です')