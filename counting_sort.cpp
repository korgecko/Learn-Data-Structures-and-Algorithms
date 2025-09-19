#include <iostream>
#include <vector>

// --- 기능 1: 배열에서 가장 큰 값을 찾아주는 함수 ---
// 역할: 오직 '최댓값 찾기'만 담당합니다.
int findMaxValue(int arr[], int n) {
    if (n == 0) return 0;

    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// --- 기능 2: 숫자의 빈도를 세어주는 함수 ---
// 역할: '계수(Count)'만 수행하고, 그 결과인 '빈도수 배열'을 반환합니다.
// 이제 이 함수는 아무것도 출력하지 않습니다.
std::vector<int> countFrequencies(int arr[], int n) {
    // 배열이 비어있으면 빈 벡터를 반환합니다.
    if (n == 0) {
        return {}; // 비어있는 벡터를 의미합니다.
    }

    int maxValue = findMaxValue(arr, n);
    std::vector<int> counts(maxValue + 1, 0);

    for (int i = 0; i < n; i++) {
        counts[arr[i]]++;
    }

    // 빈도가 기록된 'counts' 배열 자체를 반환합니다.
    return counts;
}

// --- 기능 3: 정렬된 결과를 화면에 출력해주는 함수 ---
// 역할: 오직 '화면에 출력'만 담당합니다.
// 빈도가 기록된 counts 배열과, 어디까지 출력해야 할지 알려주는 maxValue를 받습니다.
void printSortedResult(const std::vector<int>& counts, int maxValue) {
    for (int i = 0; i <= maxValue; i++) {
        for (int j = 0; j < counts[i]; j++) {
            std::cout << i << " ";
        }
    }
}


// --- 프로그램의 전체 흐름을 지휘하는 main 함수 ---
int main() {
    // 1. 데이터 준비
    int arr[] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 2. 초기 배열 상태 출력
    std::cout << "초기 배열: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 3. 계수 정렬의 각 단계를 순서대로 실행
    // 3-1. 먼저, 배열의 최댓값을 알아냅니다. (출력할 때 필요하기 때문)
    int maxValue = findMaxValue(arr, n);

    // 3-2. 각 숫자가 몇 번 나왔는지 빈도수를 계산하여 'counts' 배열에 저장합니다.
    std::vector<int> counts = countFrequencies(arr, n);

    // 3-3. 위에서 얻은 'counts' 배열과 'maxValue' 정보를 바탕으로 최종 결과를 출력합니다.
    std::cout << "정렬된 배열: ";
    printSortedResult(counts, maxValue);
    std::cout << std::endl;

    return 0;
}
