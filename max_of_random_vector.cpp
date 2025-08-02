/* 2025-08-02 배열의 원소값을 난수로 결정하고 최댓값을 찾기. */

#include <iostream>
#include <vector>
#include <random> // 난수 생성을 위해 필요
#include <ctime>  // 난수 시드 설정을 위해 필요

 //위에 코드 재사용 모듈화
 //벡터를 만들고 벡터 요소에 차례대로 정수를 입력한 뒤. 벡터 요소 중 최대값 구하기.

int max_of(const std::vector<int>& data) {
	if (data.empty()) {
		std::cerr << "데이터가 비어 있습니다." << std::endl;
		return -2147483648; // 빈 데이터에 대한 처리
	}

	int max_value = data[0];

	for (int i = 1; i < data.size(); ++i) {
		if (data[i] > max_value) {
			max_value = data[i];
		}
	}

	return max_value;
}

void print_vector(const std::vector<int>& vec) {
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
	}
	std::cout << "]" << std::endl;
}

int main() {
    std::cout << "난수의 최댓값을 구합니다." << std::endl;

    int num;
    std::cout << "난수의 개수를 입력하세요.: ";
    std::cin >> num;

    int lo;
    std::cout << "난수의 최솟값을 입력하세요.: ";
    std::cin >> lo;

    int hi;
    std::cout << "난수의 최댓값을 입력하세요.: ";
    std::cin >> hi;

    // 입력값 유효성 검사
    if (num <= 0 || lo > hi) {
        std::cout << "입력값이 올바르지 않습니다. (개수는 0보다 커야 하고, 최솟값은 최댓값보다 작거나 같아야 합니다.)" << std::endl;
        return 1; // 오류 코드로 종료
    }

    // C++11 스타일 난수 생성기 설정
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(lo, hi);

    // 원소 수가 num인 벡터를 생성
    std::vector<int> x(num);

    // 벡터의 각 원소에 난수를 채워넣기
    for (int i = 0; i < num; ++i) {
        x[i] = distrib(gen);
    }

    // 생성된 난수 배열(벡터) 출력
    print_vector(x);

    // 재사용한 max_of 함수를 호출하여 최댓값 구하기
    int max_value = max_of(x);

    std::cout << "이 가운데 최댓값은 " << max_value << "입니다." << std::endl;

    return 0;
}
