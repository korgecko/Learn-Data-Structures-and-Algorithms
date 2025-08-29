// cin, cout과 같은 표준 입출력 기능을 사용하기 위해 iostream 헤더를 포함합니다.
#include <iostream>
// 동적 배열인 vector를 사용하기 위해 vector 헤더를 포함합니다.
#include <vector>
// sort 함수를 사용하기 위해 algorithm 헤더를 포함합니다.
#include <algorithm>

// std::cin, std::cout 대신 cin, cout 등으로 짧게 사용하기 위해 std 네임스페이스를 사용합니다.
using namespace std;

int n; // 모험가의 총 수를 저장할 변수
vector<int> arr; // 각 모험가의 공포도를 저장할 벡터(동적 배열)

int main(void) {
    
    // 모험가의 수 N을 입력받습니다.
    cin >> n;

    // N명의 모험가에 대한 공포도를 입력받아 벡터 arr에 추가합니다.
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // 그리디 알고리즘의 핵심: 공포도가 낮은 순서대로 처리하기 위해 벡터를 오름차순으로 정렬합니다.
    // arr.begin()은 벡터의 시작 위치, arr.end()는 벡터의 끝 위치를 가리킵니다.
    sort(arr.begin(), arr.end());

    // 최종적으로 결성된 그룹의 수를 저장할 변수입니다.
    int total_number_of_groups = 0;
    // 현재 그룹에 포함된 모험가의 수를 저장할 변수입니다.
    int count_adventurers = 0;

    // 정렬된 벡터를 순회하며 공포도가 낮은 모험가부터 확인합니다.
    for (int i = 0; i < n; i++) {
        // 현재 그룹에 해당 모험가를 포함시킵니다.
        count_adventurers += 1;
        
        // 현재 그룹에 포함된 모험가의 수가 현재 확인하는 모험가의 공포도(arr[i]) 이상이라면,
        // 그룹 결성 조건을 만족한 것입니다.
        if (count_adventurers >= arr[i]) {
            // 그룹 결성에 성공했으므로, 총 그룹 수를 1 증가시킵니다.
            total_number_of_groups += 1;
            
            // 새로운 그룹을 만들어야 하므로, 현재 그룹의 모험가 수를 0으로 초기화합니다.
            count_adventurers = 0;
        }
    }

    // 최종 결성된 그룹의 수를 출력합니다.
    cout << total_number_of_groups << '\n';

    // 프로그램이 성공적으로 종료되었음을 의미하는 0을 반환합니다.
    return 0;
}
