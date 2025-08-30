h = int(input())

count = 0

for hour in range(h + 1):
    str_hour = str(hour)

    for minute in range(60):
        # 각 분을 문자열로 변환합니다.
        str_minute = str(minute)
        # 만약 분이 한 자리 숫자라면 앞에 '0'을 붙여 두 자리로 만듭니다.
        # 예: 5분 -> '05', 10분 -> '10'
        if minute < 10:
            str_minute = '0' + str_minute

        # 0초부터 59초까지 반복합니다.
        for second in range(60):
            # 각 초를 문자열로 변환합니다.
            str_second = str(second)
            # 만약 초가 한 자리 숫자라면 앞에 '0'을 붙여 두 자리로 만듭니다.
            # 예: 5초 -> '05', 10초 -> '10'
            if second < 10:
                str_second = '0' + str_second

            # 현재 시간(시, 분, 초)에 '3'이 포함되어 있는지 확인합니다.
            # '3' in str_hour: 시에 '3'이 있는지
            # '3' in str_minute: 분에 '3'이 있는지
            # '3' in str_second: 초에 '3'이 있는지
            # 이들 중 하나라도 '3'을 포함하면 됩니다.
            if '3' in str_hour or '3' in str_minute or '3' in str_second:
                count += 1  # '3'이 포함되어 있다면 카운트를 1 증가시킵니다.

print(count)
