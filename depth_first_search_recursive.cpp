#include <vector>
#include <iostream>

using namespace std;

// --- 전역 변수 선언 ---
// 방문 여부를 저장하는 배열
// visited[i] == true → 노드 i를 이미 방문
bool visited[9];  // 0번은 사용하지 않고 1~8 노드 사용

// 각 노드에 연결된 다른 노드 정보를 저장하는 그래프
// graph[i] → 노드 i와 연결된 노드들의 리스트
vector<int> graph[9];

// --- DFS 함수 정의 ---
// x : 현재 방문할 노드
void depth_first_search_recursive(int x) {
    visited[x] = true;        // 현재 노드를 방문했다고 표시
    cout << x << ' ';         // 방문한 노드 출력

    // 현재 노드와 연결된 모든 노드를 확인
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];  // x와 연결된 노드
        if (!visited[y]) {    // 아직 방문하지 않았다면
            depth_first_search_recursive(y);  // 재귀적으로 방문
        }
    }
}

int main(void) {
    // --- 그래프 연결 정보 예시 ---
    // 노드 1과 연결된 노드
    graph[1].push_back(2);
    graph[1].push_back(3);

    // 노드 2와 연결된 노드
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[2].push_back(5);

    // 노드 3과 연결된 노드
    graph[3].push_back(1);
    graph[3].push_back(6);
    graph[3].push_back(7);

    // 노드 4,5,6,7 연결
    graph[4].push_back(2);
    graph[5].push_back(2);
    graph[6].push_back(3);
    graph[7].push_back(3);

    // 노드 8 연결 (예시: 노드 8은 노드 5와 연결)
    graph[5].push_back(8);
    graph[8].push_back(5);

    // --- DFS 시작 ---
    depth_first_search_recursive(1);  // 1번 노드부터 시작

    return 0;
}
