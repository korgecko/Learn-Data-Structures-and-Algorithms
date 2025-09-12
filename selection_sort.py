numbers = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for current_position in range(len(numbers)):
    # 현재 위치에 들어갈 가장 작은 값을 찾아야 함
    smallest_position = current_position

    # 남은 부분에서 가장 작은 값을 찾는다
    for search_position in range(current_position + 1, len(numbers)):
        if numbers[smallest_position] > numbers[search_position]:
            smallest_position = search_position

    # 찾은 가장 작은 값과 현재 위치 값 교환
    numbers[current_position], numbers[smallest_position] = (
        numbers[smallest_position], numbers[current_position]
    )

print(numbers)
