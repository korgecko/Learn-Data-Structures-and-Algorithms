def alternatingSum(nums):
    total = 0
    for i in range(len(nums)):
        if i % 2 == 0:
            total += nums[i]  # 짝수 인덱스 더하기
        else:
            total -= nums[i]  # 홀수 인덱스 빼기
    return total

# 예시 실행
print(alternatingSum([1, 3, 5, 7]))  # -4
print(alternatingSum([100]))         # 100
