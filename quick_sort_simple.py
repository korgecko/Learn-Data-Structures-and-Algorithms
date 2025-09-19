# 정렬할 초기 리스트를 정의합니다.
initial_array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]


def quick_sort_readable(arr):
    """
    이 함수는 퀵 정렬 알고리즘을 가독성 높게 구현한 버전입니다.
    각 단계를 쉽게 이해할 수 있도록 명시적인 변수와 반복문을 사용합니다.
    """

    # --- 1. 종료 조건 (Base Case) ---
    # 만약 리스트에 원소가 하나 이하이면, 이미 정렬된 상태이므로 그대로 반환합니다.
    # 이 조건이 없으면 재귀 호출이 무한히 반복됩니다.
    if len(arr) <= 1:
        return arr

    # --- 2. 기준점(Pivot) 설정 ---
    # 리스트의 첫 번째 원소를 기준점(pivot)으로 선택합니다.
    pivot = arr[0]

    # 기준점을 제외한 나머지 원소들로 새로운 리스트를 만듭니다.
    tail = arr[1:]

    # --- 3. 분할 (Partition) ---
    # 기준점보다 작은 값들을 담을 리스트와 큰 값들을 담을 리스트를 준비합니다.
    left_side = []
    right_side = []

    # 기준점을 제외한 나머지 원소들을 하나씩 확인합니다.
    for element in tail:
        # 현재 원소가 기준점(pivot)보다 작거나 같으면 왼쪽 리스트에 추가합니다.
        if element <= pivot:
            left_side.append(element)
        # 현재 원소가 기준점(pivot)보다 크면 오른쪽 리스트에 추가합니다.
        else:
            right_side.append(element)

    # 분할 과정을 시각적으로 확인하고 싶다면 아래 주석을 해제하세요.
    # print(f"Pivot: {pivot}, Left: {left_side}, Right: {right_side}")

    # --- 4. 정복 및 조합 (Conquer and Combine) ---
    # 분할된 왼쪽 리스트와 오른쪽 리스트에 대해 각각 퀵 정렬을 재귀적으로 호출합니다.
    # 정렬된 왼쪽 리스트 + 기준점(pivot) + 정렬된 오른쪽 리스트 순서로 합쳐서 최종 결과를 반환합니다.
    return quick_sort_readable(left_side) + [pivot] + quick_sort_readable(right_side)


# 함수를 호출하고 정렬된 결과를 출력합니다.
sorted_array = quick_sort_readable(initial_array)
print(f"초기 리스트: {initial_array}")
print(f"정렬된 리스트: {sorted_array}")
