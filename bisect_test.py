from bisect import bisect_left, bisect_right

a = [1, 2, 4, 4, 8]
x = 4

print(f"bisect_left({a}, {x}): {bisect_left(a, x)}")
print(f"bisect_right({a}, {x}): {bisect_right(a, x)}")
