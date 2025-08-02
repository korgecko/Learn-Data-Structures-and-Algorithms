/* 2025-08-02 튜플 문자열 문자열 리스트 비교 최대값 출력*/
#include <iostream>
#include <vector>
#include <string>

#include <stdexcept> // std::runtime_error를 위해 필요

// --- 함수 오버로딩을 이용한 3개의 max_of 함수 ---

// 버전 1: double형 벡터의 최댓값을 찾는 함수
double max_of(const std::vector<double>& data) {
    // 1. 비어있는지 검사 (가장 중요한 방어 코드)
    if (data.empty()) {
        // 비어있는 데이터에서는 최댓값을 찾을 수 없으므로, 오류를 발생시킵니다.
        throw std::runtime_error("오류: double 벡터가 비어있습니다.");
    }

    // 2. 첫 번째 원소를 최댓값의 초기값으로 설정합니다.
    double max_value = data[0];

    // 3. 두 번째 원소부터 마지막 원소까지 순회합니다.
    for (size_t i = 1; i < data.size(); ++i) {
        // 4. 현재 최댓값(max_value)보다 더 큰 원소를 발견하면
        if (data[i] > max_value) {
            // max_value를 그 값으로 교체합니다.
            max_value = data[i];
        }
    }

    // 5. 최종적으로 찾은 최댓값을 반환합니다.
    return max_value;
}

// 버전 2: 문자열(string)에서 가장 큰 '문자'를 찾는 함수
char max_of(const std::string& text) {
    if (text.empty()) {
        throw std::runtime_error("오류: 문자열이 비어있습니다.");
    }

    char max_char = text[0];

    for (size_t i = 1; i < text.length(); ++i) {
        if (text[i] > max_char) {
            max_char = text[i];
        }
    }
    return max_char;
}

// 버전 3: 문자열 벡터에서 사전 순으로 가장 큰 '문자열'을 찾는 함수
std::string max_of(const std::vector<std::string>& data) {
    if (data.empty()) {
        throw std::runtime_error("오류: string 벡터가 비어있습니다.");
    }

    std::string max_string = data[0];

    for (size_t i = 1; i < data.size(); ++i) {
        // C++에서 문자열끼리 비교하면 사전 순서로 비교됩니다.
        if (data[i] > max_string) {
            max_string = data[i];
        }
    }
    return max_string;
}


// --- 메인 프로그램 실행 부분 ---
int main() {
    // 1. Python의 튜플 -> C++의 double 벡터
    // C++ 벡터는 모든 요소의 타입이 동일해야 하므로 double로 통일했습니다.
    std::vector<double> t = { 4.0, 7.0, 5.6, 2.0, 3.14, 1.0 };

    // 2. Python의 문자열 -> C++의 std::string
    std::string s = "string";

    // 3. Python의 문자열 리스트 -> C++의 std::vector<std::string>
    std::vector<std::string> a = { "DTS", "AAC", "FLAC", "XYZ"};

    // try-catch 블록: 함수가 던지는(throw) 오류를 잡아내기 위한 구문입니다.
    try {
        // max_of(t) 호출: 인자가 vector<double>이므로, 컴파일러는 '버전 1' 함수를 선택합니다.
        std::cout << "숫자 벡터의 최댓값은 " << max_of(t) << "입니다." << std::endl;

        // max_of(s) 호출: 인자가 string이므로, 컴파일러는 '버전 2' 함수를 선택합니다.
        std::cout << "문자열 \"" << s << "\"에서 가장 큰 문자는 '" << max_of(s) << "'입니다." << std::endl;

        // max_of(a) 호출: 인자가 vector<string>이므로, 컴파일러는 '버전 3' 함수를 선택합니다.
        std::cout << "문자열 벡터의 최댓값은 \"" << max_of(a) << "\"입니다." << std::endl;
    }
    catch (const std::runtime_error& error) {
        // 만약 try 블록 안에서 throw가 발생하면, 프로그램이 여기서 오류 메시지를 출력하고 안전하게 계속됩니다.
        std::cerr << "프로그램 실행 중 문제가 발생했습니다: " << error.what() << std::endl;
    }

    return 0;
}
