#include <iostream>
#include <vector>
//#include <algorithm>

// --- 이진 탐색 알고리즘 (반복문 구현) ---
// (개선) vector를 수정하지 않으므로 const 참조로 받아 더 안전하게 만듭니다.
int binarySearch(const std::vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		// (개선) start + end가 int의 최댓값을 넘는 'Integer Overflow'를 방지하는 더 안전한 방식입니다.
		int mid = start + (end - start) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}

int main() { // C++ 표준에 따라 'int main()'으로 작성
	// (개선) C++ 입출력 동기화를 해제하여 입출력 속도를 향상시킵니다. (대량 데이터 처리 시 유용)
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// (개선) 전역 변수 대신 main 함수 내에 지역 변수로 선언합니다.
	int n, target;
	std::cin >> n >> target;

	std::vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		arr.push_back(x);
	}

	int result = binarySearch(arr, target, 0, n - 1);

	if (result == -1) {
		std::cout << "원소가 존재하지 않습니다" << '\n';
	}
	else {
		std::cout << result + 1 << '\n';
	}
	return 0;
}
