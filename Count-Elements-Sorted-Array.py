from bisect import bisect_left, bisect_right

# 특정 범위 [left_value, right_value]에 해당하는 숫자의 개수를 세는 함수
def count_by_range(array, left_value, right_value):
    # right_value를 초과하는 첫 번째 요소의 인덱스를 찾습니다.
    right_index = bisect_right(array, right_value)
    # left_value 이상인 첫 번째 요소의 인덱스를 찾습니다.
    left_index = bisect_left(array, left_value)
    # 두 인덱스의 차이가 해당 범위 내 요소의 개수입니다.
    return right_index - left_index

# --- 사용자 입력 처리 및 결과 출력 부분 ---

# 첫 번째 줄에서 N (배열의 크기)과 X (찾으려는 숫자)를 입력받습니다.
# 예: "7 2" 입력 시 n=7, x=2
n, x = map(int, input().split())

# 두 번째 줄에서 N개의 정수를 입력받아 정렬된 리스트로 만듭니다.
# 예: "1 1 2 2 2 2 3" 입력 시 array=[1, 1, 2, 2, 2, 2, 3]
array = list(map(int, input().split()))

# count_by_range 함수를 사용하여 x가 배열에 몇 개 있는지 계산합니다.
# left_value와 right_value를 모두 x로 설정하여 x의 개수를 찾습니다.
count = count_by_range(array, x, x)

# 만약 count가 0이라면, 배열에 x가 존재하지 않는다는 의미입니다.
if count == 0:
    print(-1) # 이 경우 -1을 출력합니다.
# count가 0이 아니라면, x가 배열에 존재하며 그 개수를 출력합니다.
else:
    print(count) # x의 개수를 출력합니다.
