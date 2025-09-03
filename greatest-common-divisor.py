def greatest_common_divisor(num1, num2):
    # num1을 num2로 나누었을 때 나머지가 0이면,
    # 즉 num2가 num1을 나누어떨어뜨리면 num2가 최대공약수이다.
    if num1 % num2 == 0:
        return num2
    else:
        # 나머지가 0이 아니면,
        # (num2, num1 % num2) 쌍으로 문제를 줄여서 다시 최대공약수를 구한다.
        # 이 과정을 반복하다 보면 결국 나머지가 0이 되는 순간이 온다.
        return greatest_common_divisor(num2, num1 % num2)

# 192와 162의 최대공약수를 구한다.
print(greatest_common_divisor(192, 162))
