print("左下直角三角形を作ります。")
len = int(input("短辺:"))

for i in range(len):
    for j in range(i + 1):
        print("*", end="")
    print()