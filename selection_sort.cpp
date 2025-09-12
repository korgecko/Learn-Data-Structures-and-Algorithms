#include <iostream>
using namespace std;

const int SIZE = 10; 
int numbers[SIZE] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    for (int sorted_index = 0; sorted_index < SIZE; sorted_index++) {
        int smallest_index = sorted_index;
        // 아직 정렬되지 않은 부분에서 가장 작은 값 찾기
        for (int candidate_index = sorted_index + 1; candidate_index < SIZE; candidate_index++) {
            if (numbers[smallest_index] > numbers[candidate_index]) {
                smallest_index = candidate_index;
            }
        }
        // 찾은 최소값을 현재 위치로 가져오기
        swap(numbers[sorted_index], numbers[smallest_index]);
    }    
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    return 0;
}
