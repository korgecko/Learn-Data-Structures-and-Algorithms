#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[] = "hello";
    int n = strlen(s);

    // 직접 swap
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    cout << s << endl;  // "olleh"
}
