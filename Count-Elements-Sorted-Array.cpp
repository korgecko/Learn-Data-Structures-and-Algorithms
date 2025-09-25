#include <iostream>
#include <vector>
#include <algorithm> // lower_bound와 upper_bound를 사용하기 위해 필요합니다.

using namespace std;

// 정렬된 벡터 v에서 [leftValue, rightValue] 범위에 속하는 데이터의 개수를 반환하는 함수
int countByRange(const vector<int>& v, int leftValue, int rightValue) {
    // upper_bound: rightValue를 초과하는 첫 번째 원소의 위치(iterator)를 찾습니다.
    auto rightIndex = upper_bound(v.begin(), v.end(), rightValue);

    // lower_bound: leftValue 이상인 첫 번째 원소의 위치(iterator)를 찾습니다.
    auto leftIndex = lower_bound(v.begin(), v.end(), leftValue);

    // 두 위치의 차이를 구하면 해당 범위에 속하는 원소의 개수가 됩니다.
    return rightIndex - leftIndex;
}

int main() {
    int n, x; // 데이터의 개수 n과 찾고자 하는 값 x를 선언합니다.

    // 첫 번째 줄에서 n과 x를 입력받습니다.
    cin >> n >> x;

    vector<int> v(n); // 크기가 n인 벡터를 생성합니다.

    // 두 번째 줄에서 n개의 원소를 입력받아 벡터에 저장합니다.
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // countByRange 함수를 호출하여 x의 개수를 찾습니다.
    // 찾고자 하는 값이 x 하나이므로 leftValue와 rightValue 모두 x를 전달합니다.
    int count = countByRange(v, x, x);

    // 찾은 개수가 0이면 -1을 출력합니다.
    if (count == 0) {
        cout << -1 << '\n';
    }
    // 그렇지 않으면 찾은 개수를 출력합니다.
    else {
        cout << count << '\n';
    }

    return 0;
}
