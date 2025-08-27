N, K = map(int, input().split())

result = 0

while N >= K:
    # N 이 K 로 나누어떨어지면 멈춘다.
    if N % K != 0:
        # 나누어지지 않으면 1 뺴기.
        N -= 1
        result += 1
        print(f"1을 빼서 {N}이 되었습니다. (지금까지 {result}번 뺌)")
    else:
        N //= K
        result += 1
        print(f"{K} 로 나눠서 {N}이 되었습니다. (총 {result} 번 나누기 연산)")



print("마지막 남은 수:", N)
print("총 뺀 횟수:", result)
