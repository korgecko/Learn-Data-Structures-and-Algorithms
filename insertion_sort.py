# insertion_sort.py
# In-place insertion sort (교환 방식)
# 입력: numbers (리스트)
# 출력: 정렬된 numbers (같은 리스트를 직접 수정)
# 특징: 안정 정렬(stable), 제자리 정렬(in-place), 최악시간 O(n^2), 최선시간 O(n), 공간복잡도 O(1)

numbers = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# outer loop: i는 '삽입하려는 원소의 인덱스'를 가리킵니다.
# invariant(불변식): 각 반복의 시작 시점에 numbers[0:i]는 이미 정렬되어 있다.
for i in range(1, len(numbers)):
    # 내부 루프는 i번째 원소를 왼쪽으로 "한 칸씩" 밀어 적절한 위치에 삽입합니다.
    # j는 현재 비교 중인 인덱스(우측 원소)로 시작해 왼쪽으로 이동합니다.
    for j in range(i, 0, -1):
        # 만약 오른쪽 원소(numbers[j])가 왼쪽 원소(numbers[j-1])보다 작다면,
        # 두 원소를 교환(swap)하여 오른쪽 원소를 한 칸 왼쪽으로 이동시킵니다.
        # 이 동작을 반복하면 i번째 원소(초기 위치의 값)가 적절한 위치로 이동합니다.
        if numbers[j] < numbers[j - 1]:
            # swap: 두 원소의 위치 교환
            numbers[j], numbers[j - 1] = numbers[j - 1], numbers[j]
        else:
            # 이미 왼쪽 원소가 더 작거나 같다면(정렬된 상태 유지),
            # 더 왼쪽으로 갈 필요가 없으므로 내부 루프를 중단합니다.
            # 이 'break' 덕분에 정렬된 구간에서는 내부 루프가 빨리 끝나 최선 케이스에서 O(n) 성능을 얻습니다.
            break

# 최종적으로 numbers는 오름차순 정렬되어 출력됩니다.
print(numbers)
