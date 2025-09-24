# 파이썬의 표준 라이브러리인 bisect에서 이진 탐색 관련 함수를 가져옵니다.
# bisect_left: 정렬 순서를 유지하면서 특정 값을 삽입할 가장 왼쪽 인덱스를 반환
# bisect_right: 정렬 순서를 유지하면서 특정 값을 삽입할 가장 오른쪽 인덱스를 반환
from bisect import bisect_left, bisect_right


# 정렬된 리스트 'a'에서 [left_value, right_value] 범위에 있는 데이터의 개수를 반환하는 함수
def count_by_range(a, left_value, right_value):
    """
    정렬된 리스트 a에서 left_value와 right_value 사이의 값(양쪽 값 포함)을
    가진 원소의 개수를 반환합니다.
    """

    # right_value가 리스트에 삽입될 수 있는 가장 오른쪽 인덱스를 찾습니다.
    # 즉, right_value보다 큰 첫 번째 원소의 인덱스가 됩니다.
    right_index = bisect_right(a, right_value)

    # left_value가 리스트에 삽입될 수 있는 가장 왼쪽 인덱스를 찾습니다.
    # 즉, left_value와 같거나 큰 첫 번째 원소의 인덱스가 됩니다.
    left_index = bisect_left(a, left_value)

    # right_index는 찾고자 하는 범위의 끝 바로 다음 위치를 가리키고,
    # left_index는 찾고자 하는 범위의 시작 위치를 가리키므로,
    # 두 인덱스의 차이가 바로 범위 내 원소의 개수가 됩니다.
    return right_index - left_index


# 함수를 테스트하기 위한 정렬된 리스트
# 인덱스:  0  1  2  3  4  5  6  7  8  9
a = [1, 2, 3, 3, 3, 3, 4, 4, 8, 9]

# -------------------- 실행 예시 1 --------------------
# 값이 4인 데이터의 개수(즉, 범위가 [4, 4]인 경우)를 계산하여 출력
print(f"값이 4인 데이터 개수: {count_by_range(a, 4, 4)}")

# -------------------- 실행 예시 2 --------------------
# 값이 -1부터 3까지인 데이터의 개수(즉, 범위가 [-1, 3]인 경우)를 계산하여 출력
print(f"[-1, 3] 범위의 데이터 개수: {count_by_range(a, -1, 3)}")
