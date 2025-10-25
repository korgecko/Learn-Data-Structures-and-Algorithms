def reverse_like_cpp_with_while(s):
    n = len(s)
    char_list = []

    i = n - 1

    for i in range(n - 1, -1, -1):
        char_list.append(s[i])

    return "".join(char_list)

test_string = "hello world"
reversed_string = reverse_like_cpp_with_while(test_string)
print(f"원본: '{test_string}'")
print(f"C++ style reverser with for loop: '{reversed_string}'")
