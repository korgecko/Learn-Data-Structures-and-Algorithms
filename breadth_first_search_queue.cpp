#include <iostream>
#include <vector>
#include <queue>  // BFS를 위해 큐(Queue)를 사용

using namespace std;

// --- 전역 변수 ---
// visited[i] : 노드 i 방문 여부
bool visited[9];  // 0번 인덱스는 사용하지 않고 1~8번 노드 사용

// graph[i] : 노드 i와 연결된 노드들의 리스트
vector<int> graph[9];

// --- BFS 함수 정의 ---
void breadth_first_search(int start) {
    queue<int> q;      // BFS를 위한 큐 생성
    q.push(start);     // 시작 노드를 큐에 넣음
    visited[start] = true; // 시작 노드 방문 처리

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int x = q.front(); // 큐의 앞에 있는 노드 꺼내기 (FIFO)
        q.pop();           // 큐에서 제거
        cout << x << ' ';  // 방문한 노드 출력

        // 현재 노드와 연결된 모든 노드 확인
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];  // x와 연결된 노드
            if (!visited[y]) {    // 아직 방문하지 않은 노드라면
                q.push(y);        // 큐에 넣어 다음에 방문
                visited[y] = true; // 방문 처리, 중복 방지
            }
        }
    }
}

int main(void) {
    // --- 그래프 연결 정보 예시 ---
    // 노드 1과 연결
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2와 연결
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3과 연결
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4와 연결
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5와 연결
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6과 연결
    graph[6].push_back(7);

    // 노드 7과 연결
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8과 연결
    graph[8].push_back(1);
    graph[8].push_back(7);

    // --- BFS 실행 ---
    breadth_first_search(1);  // 1번 노드부터 BFS 시작

    return 0;
}
