# --- 이진 탐색 알고리즘 (재귀적 구현) ---
# 이 함수는 정렬된 리스트(array)에서 특정 값(target)을 찾는 역할을 합니다.
# 재귀 호출을 통해 탐색 범위를 절반씩 줄여나갑니다.
# 매개변수:
#   array: 탐색을 수행할 정렬된 리스트
#   target: 찾고자 하는 값
#   start: 현재 탐색 범위의 시작 인덱스
#   end: 현재 탐색 범위의 끝 인덱스
def binary_search(array, target, start, end):
    # [종료 조건 1] 탐색 실패: 시작점이 끝점보다 커진 경우
    # 이는 탐색 범위를 계속 좁혔음에도 값을 찾지 못했다는 의미입니다.
    if start > end:
        return None # None을 반환하여 '찾지 못했음'을 알립니다.

    # 현재 탐색 범위의 중간 지점(인덱스)을 계산합니다.
    # (start + end)를 2로 나눈 몫을 구합니다. (// 연산자)
    mid = (start + end) // 2

    # [종료 조건 2] 탐색 성공: 중간점의 값이 찾으려는 값과 정확히 일치하는 경우
    if array[mid] == target:
        return mid # 찾은 값의 인덱스(mid)를 반환합니다.

    # [재귀 호출 1] 중간점의 값이 찾으려는 값보다 큰 경우
    # 이 경우, 찾으려는 값(target)은 반드시 중간점의 '왼쪽'에 위치합니다.
    elif array[mid] > target:
        # 탐색 범위를 왼쪽 절반(start부터 mid-1까지)으로 좁혀서 다시 탐색을 수행합니다.
        return binary_search(array, target, start, mid - 1)

    # [재귀 호출 2] 중간점의 값이 찾으려는 값보다 작은 경우
    # 이 경우, 찾으려는 값(target)은 반드시 중간점의 '오른쪽'에 위치합니다.
    else:
        # 탐색 범위를 오른쪽 절반(mid+1부터 end까지)으로 좁혀서 다시 탐색을 수행합니다.
        return binary_search(array, target, mid + 1, end)


# --- 메인 실행 부분 ---

# 1. 데이터 입력
# 첫 번째 줄에서 원소의 개수(n)와 찾고자 하는 값(target)을 입력받습니다.
# 입력 예: 10 7
n, target = list(map(int, input().split()))

# 두 번째 줄에서 전체 원소들을 입력받습니다.
# ★★★ 중요: 이진 탐색을 위해서는 반드시 정렬된 상태로 입력해야 합니다.
# 입력 예: 1 3 5 7 9 11 13 15 17 19
array = list(map(int, input().split()))

# 2. 이진 탐색 함수 호출
# 처음에는 전체 리스트를 대상으로 탐색을 시작합니다. (시작 인덱스: 0, 끝 인덱스: n - 1)
result = binary_search(array, target, 0, n - 1)

# 3. 결과 출력
# binary_search 함수가 None을 반환했다면, 원소를 찾지 못한 것입니다.
if result is None: # '==' 대신 'is'를 사용하는 것이 None 비교에 더 권장됩니다.
    print("원소 존재 하지 않음")

# None이 아니라면, 원소를 찾은 것이며 result에는 해당 인덱스가 저장되어 있습니다.
else:
    # result는 0부터 시작하는 '인덱스'이므로,
    # 사람이 이해하기 쉬운 '몇 번째 위치'인지 알려주기 위해 1을 더해 출력합니다.
    # 예: 인덱스가 3이라면, 4번째 위치에 있다는 의미입니다.
    print(result + 1)
