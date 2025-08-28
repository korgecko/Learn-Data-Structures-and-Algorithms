#include <iostream>

int main(void) {
    int N, K;
    int result = 0; // 변수는 사용하기 전에 초기화하는 것이 좋습니다.

    // 사용자로부터 N과 K를 입력받습니다.
    std::cin >> N >> K;

    while (true) {
        // N을 K로 나누어 떨어지는 가장 가까운 수(target)를 찾습니다.
        int target = (N / K) * K;
        // 1을 빼는 연산 횟수를 누적합니다. (N에서 target까지 1씩 빼는 횟수)
        result += (N - target);
        N = target;

        // N이 K보다 작아지면 더 이상 나눌 수 없으므로 반복문을 종료합니다.
        if (N < K) {
            break;
        }

        // K로 나누는 연산 횟수를 1 증가시킵니다.
        result++;
        N /= K;
    }

    // 마지막으로 남은 N에 대하여 1이 될 때까지 빼는 연산 횟수를 누적합니다.
    result += (N - 1);

    std::cout << result << '\n';
    return 0;
}
