# 1. 맵의 크기(N) 입력 받기
n = int(input())

# 2. 모험가의 시작 위치 설정 (항상 1, 1)
x, y = 1, 1
print(f"--- 시작 위치: ({x}, {y}) ---") # 시작 위치 확인

# 3. 이동 명령들을 입력 받아 리스트로 저장
# (예:　Ｒ　Ｒ　Ｒ　Ｕ　Ｄ　Ｄ　를　입력받아　저장 ['R', 'R', 'R', 'U', 'D', 'D'])
# 전각 문자를 반각 문자로 변환하는 과정 추가
plans_input = input()
plans = []
for char in plans_input.split():
    # 전각 문자를 반각 문자로 변환 (대문자로 통일)
    if char == 'Ｒ':
        plans.append('R')
    elif char == 'Ｌ':
        plans.append('L')
    elif char == 'Ｕ':
        plans.append('U')
    elif char == 'Ｄ':
        plans.append('D')
    elif char == 'ｒ':
        plans.append('R')
    elif char == 'l':
        plans.append('L')
    elif char == 'u':
        plans.append('U')
    elif char == 'd':
        plans.append('D')
    else: # 혹시 모를 다른 입력에 대비
        plans.append(char.upper()) # 일반 문자도 대문자로 변환

print(f"--- 입력된 명령: {plans} ---") # 입력된 명령 리스트 확인

# 4. 각 이동 명령을 순서대로 처리
for i, plan in enumerate(plans): # 인덱스 i를 추가하여 몇 번째 명령인지 확인
    # 5. 현재 위치를 기준으로 '다음' 이동할 위치를 미리 계산
    next_x, next_y = x, y

    # 6. 어떤 명령인지에 따라 next_x, next_y 값을 변경
    if plan == 'L':
        next_x -= 1
    elif plan == 'R':
        next_x += 1
    elif plan == 'U':
        next_y -= 1
    elif plan == 'D':
        next_y += 1

    # 현재 명령과 계산된 다음 위치 출력
    print(f"[{i+1}/{len(plans)}] 명령 '{plan}': 현재 ({x}, {y}) -> 계산된 다음 위치 ({next_x}, {next_y})")

    # 7. 계산된 다음 위치(next_x, next_y)가 맵 안에 있는지 확인
    if 1 <= next_x <= n and 1 <= next_y <= n:
        # 8. 맵 안에 있다면, 모험가의 실제 위치를 다음 위치로 업데이트
        x, y = next_x, next_y
        print(f"  -> 유효한 이동! 새 위치: ({x}, {y})")
    else:
        # 9. 맵 밖으로 나간다면, 아무것도 하지 않고 현재 위치를 유지
        print(f"  -> 맵 밖으로 이동 불가! 현재 위치 유지: ({x}, {y})")

# 10. 모든 명령을 처리한 후, 모험가의 최종 위치 출력
print(f"--- 최종 위치: ({x}, {y}) ---")
