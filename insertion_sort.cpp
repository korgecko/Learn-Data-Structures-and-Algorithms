// insertion_sort.cpp
// Insertion Sort (삽입 정렬) in C++
// 특징: 제자리 정렬(in-place), 안정 정렬(stable), 최악 O(n^2), 최선 O(n), 공간복잡도 O(1)

#include <iostream>
using namespace std;

int n = 10;
int target_numbers[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    // 바깥 루프: index i는 "삽입할 원소"를 가리킴
    // 불변식(invariant): 매 반복 시작 시 target_numbers[0..i-1] 구간은 정렬된 상태
    for (int i = 1; i < n; ++i) {
        // 안쪽 루프: i번째 원소를 왼쪽으로 이동시켜 적절한 위치에 삽입
        for (int j = i; j > 0; j--) {
            // 현재 원소가 바로 왼쪽 원소보다 작으면 swap
            if (target_numbers[j] < target_numbers[j - 1]) {
                swap(target_numbers[j], target_numbers[j - 1]);
            } 
            else {
                // 정렬된 위치를 찾았으므로 루프 중단
                break;
            }
        }
    }

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << target_numbers[i] << ' ';
    }
    cout << endl;

    return 0;
}
