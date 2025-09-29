#include <iostream>

using namespace std;

int fibo(int x) {
    if (x == 1 || x == 2) { // 잘못 작성했던 부분. if (x == 1) || (x == 2)  // ❌ 오류
        return 1;
    }
    return fibo(x - 1) + fibo(x - 2);
}

int main(void) {
    cout << fibo(4) << "\n";
    cout << fibo(5) << "\n";
    return 0;
}
