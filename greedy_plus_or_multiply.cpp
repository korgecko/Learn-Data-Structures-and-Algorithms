#include <iostream>
#include <string>

using namespace std;   

string str;

int main(void) {

    cin >> str;

    long long result = str[0] - '0'; // 0 에 해당하는 아스키 코드 값을 빼줌. 

    for (int i = 1; i < str.size(); i++) {
        int num = str[i] - '0';
        if (num <= 1 || result <= 1) 
            result += num;
        else 
            result *= num;
    }

    cout << result << '\n';
}
