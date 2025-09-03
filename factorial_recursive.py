#반복적으로 구현한 n!
def factorial_iterative(n):
    result = 1
    # 1부터 n 까지 차례대로 곱하기
    for i in range(1, n+1):
        result *= i
    return result

#재귀적으로 구현한 n!
def factorial_recursive(n):
    if n == 0:
        return 1
    else:
        return n * factorial_recursive(n-1)

print('반복적으로 구현한 n! : ', factorial_iterative(5))
print('재귀적으로 구현한 n! : ', factorial_recursive(5))
