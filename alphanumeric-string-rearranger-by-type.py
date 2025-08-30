# 1. 사용자로부터 문자열을 입력받습니다. (예: K1K1A5CB7)
input_data = input()

# 2. 최종 결과의 일부가 될 알파벳을 저장할 리스트와
#    숫자의 합계를 저장할 변수를 만듭니다.
alphabet_parts = []
number_sum = 0

# 3. 입력받은 문자열의 각 글자를 하나씩 확인합니다.
for char in input_data:
    # 4. 글자가 알파벳인지 확인합니다.
    if char.isalpha():
        # 알파벳이라면, 리스트에 추가합니다.
        alphabet_parts.append(char)
    else:
        # 알파벳이 아니라면 숫자이므로, 합계 변수에 더해줍니다.
        number_sum += int(char)

# 5. 모든 알파벳이 담긴 리스트를 오름차순으로 정렬합니다.
alphabet_parts.sort()

# 6. 만약 더해진 숫자가 하나라도 존재한다면 (합계가 0이 아니라면),
#    정렬된 리스트의 '가장 마지막'에 숫자 합계를 '문자열' 형태로 추가합니다.
#    이것이 이미지 코드의 핵심적인 장점입니다!
if number_sum > 0:
    alphabet_parts.append(str(number_sum))

# 7. 이제 리스트에는 [정렬된 알파벳, ..., 숫자 합계]가 모두 들어있습니다.
#    이 리스트를 .join()을 이용해 하나의 문자열로 합쳐 깔끔하게 출력합니다.
#    예: ['A', 'B', 'C', 'K', 'K', '14'] -> "ABCKK14"
print("".join(alphabet_parts))
