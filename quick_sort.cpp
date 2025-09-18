// quick_sort_commented.cpp
// Quick Sort (in-place partition, pivot = first element)
// - 주석으로 동작 원리와 불변식 설명
// - 큰 알고리즘 틀은 변경하지 않음
#include <iostream>
#include <algorithm> // std::swap
using namespace std;

int n = 10;
int target_numbers[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

// quickSort: target_numbers[start..end] 구간을 정렬
void quickSort(int* target_numbers, int start, int end) {
    // 기저조건: 정렬할 구간에 원소가 0개 또는 1개이면 종료
    if (start >= end) return;

    // pivot은 구간의 첫 번째 원소를 사용 (pivot 인덱스)
    int pivot = start;
    // left는 pivot 바로 오른쪽에서 시작 (pivot보다 큰 값을 찾기 위해 오른쪽으로 전진)
    int left = start + 1;
    // right는 구간의 끝에서 시작 (pivot보다 작은 값을 찾기 위해 왼쪽으로 전진)
    int right = end;

    // ---------------------------
    // Partition 루프: left와 right가 교차할 때까지 반복
    // 불변식(invariant) 설명(루프 시작 시):
    //  - target_numbers[start+1 .. left-1] 는 모두 pivot 값보다 <= 이다 (왼쪽 영역 후보)
    //  - target_numbers[right+1 .. end] 는 모두 pivot 값보다 >= 이다 (오른쪽 영역 후보)
    // 루프가 끝나면 pivot을 right와 교환하여 pivot이 제자리를 차지하게 함.
    // ---------------------------
    while (left <= right) {
        // left 포인터를 오른쪽으로 옮긴다:
        // pivot보다 작거나 같은 원소(<= pivot)는 왼쪽 파티션에 둘 수 있으므로 건너뛴다.
        // 범위 검사(left <= end)는 out-of-bounds 방지용
        while (left <= end && target_numbers[left] <= target_numbers[pivot]) {
            ++left;
        }

        // right 포인터를 왼쪽으로 옮긴다:
        // pivot보다 크거나 같은 원소(>= pivot)는 오른쪽 파티션에 둘 수 있으므로 건너뛴다.
        // 범위 검사(right > start)는 pivot 인덱스를 넘지 않게 하기 위함
        while (right > start && target_numbers[right] >= target_numbers[pivot]) {
            --right;
        }

        // left와 right가 교차했는지 확인
        if (left > right) {
            // 교차했다는 것은 분할이 완료되었음을 의미.
            // pivot 위치(start)에 있는 값을 right 위치로 옮겨서
            // pivot이 올바른 '중간' 위치를 차지하도록 한다.
            std::swap(target_numbers[pivot], target_numbers[right]);
        } else {
            // 아직 교차하지 않았다면,
            // left는 pivot보다 큰 값, right는 pivot보다 작은 값이므로
            // 둘을 교환해서 왼쪽은 작게, 오른쪽은 크게 정리한다.
            std::swap(target_numbers[left], target_numbers[right]);
        }
    }

    // 이제 pivot은 index 'right'에 자리잡았음.
    // pivot 기준 좌우 부분배열에 대해 재귀 호출
    // (left와 right가 교차했으므로 right가 pivot의 최종 인덱스)
    quickSort(target_numbers, start, right - 1); // pivot 왼쪽 부분
    quickSort(target_numbers, right + 1, end);   // pivot 오른쪽 부분
}

int main(void) {
    quickSort(target_numbers, 0, n - 1);

    // 결과 출력
    for (int i = 0; i < n; ++i) cout << target_numbers[i] << ' ';
    cout << '\n';
    return 0;
}
