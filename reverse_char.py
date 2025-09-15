s = list("hello")   # 문자열은 불변 → list로 변환
n = len(s)

# 직접 swap
for i in range(n // 2):
    j = n - i - 1
    s[i], s[j] = s[j], s[i]

reversed_s = "".join(s)
print(reversed_s)  # "olleh"
