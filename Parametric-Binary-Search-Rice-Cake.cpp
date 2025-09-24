// 필요한 라이브러리를 포함합니다.
#include <iostream> // C++ 표준 입출력을 위한 라이브러리 (cin, cout)
#include <vector>   // 동적 배열인 vector를 사용하기 위한 라이브러리
#include <algorithm> // max 함수 등을 사용하기 위해 포함할 수 있습니다 (이 코드에서는 직접 사용하진 않음)

// std 네임스페이스를 사용하겠다고 선언합니다. cin, cout, vector 등을 std:: 없이 사용할 수 있게 해줍니다.
using namespace std;

// 전역 변수로 선언하여 main 함수 및 다른 함수에서 쉽게 접근할 수 있도록 합니다.
int n; // 떡의 개수 (N)
int m; // 손님이 요청한 떡의 총 길이 (M)
vector<int> arr; // 각 떡의 개별 높이를 저장할 동적 배열 (vector)


int main(void) {
	// C++의 입출력 속도를 향상시켜주는 코드입니다. (일반적으로 코딩 테스트에서 시간 초과를 방지하기 위해 사용)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 첫 번째 줄에서 떡의 개수(n)와 요청한 떡의 길이(m)를 입력받습니다.
	cin >> n >> m;

	// n번 반복하여 각 떡의 높이를 입력받고, vector 'arr'에 추가합니다.
	for (int i = 0; i < n; i++) {
		int x; // 임시로 떡의 높이를 입력받을 변수
		cin >> x;
		arr.push_back(x); // vector의 맨 뒤에 입력받은 떡 높이(x)를 추가
	}

	// --- 이진 탐색을 위한 초기 설정 ---
	int start = 0; // 탐색 범위의 시작점. 절단기 높이의 최소값은 0입니다.
	// int end = *max_element(arr.begin(), arr.end()); // 더 정확한 끝점 설정 방식
	int end = 1e9; // 탐색 범위의 끝점. 문제의 조건에서 떡의 최대 높이가 10억이므로, 10억(1e9)으로 설정합니다.

	// 이진 탐색의 결과(손님을 만족시키는 최대 절단기 높이)를 저장할 변수
	int result = 0;

	// --- 이진 탐색 수행 (반복문) ---
	// 시작점(start)이 끝점(end)보다 작거나 같을 때까지 탐색을 계속합니다.
	while (start <= end) {
		// 현재 절단기 높이(mid)로 잘랐을 때 얻을 수 있는 총 떡의 길이를 저장할 변수
		// total의 값이 int의 범위를 넘어갈 수 있으므로 long long 타입으로 선언하는 것이 안전합니다.
		long long int total = 0;
		// 중간점(mid)을 현재 탐색의 '절단기 높이' 후보로 설정합니다.
		// (start + end)가 int 범위를 넘을 수 있는 극단적인 경우를 대비해 start + (end - start) / 2 로 계산하기도 합니다.
		int mid = start + (end - start) / 2;

		// 모든 떡을 순회하면서 현재 절단기 높이(mid)로 잘랐을 때 얻는 떡의 길이를 계산합니다.
		for (int i = 0; i < n; i++) {
			// 떡의 높이가 절단기 높이(mid)보다 길어야 잘립니다.
			if (arr[i] > mid) {
				// 잘린 떡의 길이를 total에 더해줍니다.
				total += arr[i] - mid;
			}
		}

		// --- 탐색 범위 조절 ---
		// 경우 1: 떡이 부족한 경우 (total < m)
		if (total < m) {
			// 현재 높이(mid)가 너무 높아서 떡이 부족합니다.
			// 더 많은 떡을 얻기 위해 절단기 높이를 낮춰야 하므로, end를 왼쪽으로 이동시킵니다.
			end = mid - 1;
		}
		// 경우 2: 떡이 충분하거나 딱 맞는 경우 (total >= m)
		else {
			// 현재 높이(mid)는 조건을 만족하므로, 일단 정답 후보로 저장합니다.
			result = mid;
			// 하지만 우리는 '최대' 높이를 원하므로, 더 높은 높이에서도 가능한지 확인해야 합니다.
			// 따라서 탐색 범위를 오른쪽으로 옮겨 더 높은 높이를 탐색합니다.
			start = mid + 1;
		}
	}

	// 반복문이 종료된 후, result에 저장된 값이 조건을 만족하는 최대 높이입니다.
	cout << result << '\n';
}
