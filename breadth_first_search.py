from collections import deque  # 큐(Queue)를 사용하기 위해 deque 라이브러리 import

# --- BFS 함수 정의 ---
def breadth_first_search(graph, start, visited):
    """
    graph   : 인접 리스트로 표현된 그래프
    start   : BFS 시작 노드
    visited : 각 노드 방문 여부를 저장하는 리스트
    """

    queue = deque([start])   # 시작 노드를 큐에 넣음
    visited[start] = True    # 시작 노드 방문 처리

    # 큐가 빌 때까지 반복
    while queue:
        v = queue.popleft()  # 큐의 가장 앞에 있는 노드를 꺼냄 (FIFO)
        print(v, end=' ')    # 방문한 노드 출력

        # 현재 노드 v와 연결된 모든 노드를 확인
        for i in graph[v]:
            if not visited[i]:    # 아직 방문하지 않은 노드라면
                queue.append(i)   # 큐에 추가 → 나중에 방문
                visited[i] = True # 방문 처리

# --- 그래프 정의 ---
# 인덱스와 노드 번호를 맞추기 위해 0번 인덱스는 비워둠
# graph[i]는 노드 i와 연결된 노드 리스트
graph = [
    [],        # 0번 노드는 사용하지 않음
    [2, 3, 8],# 노드 1 → 노드 2, 3, 8과 연결
    [1, 7],   # 노드 2 → 노드 1, 7과 연결
    [1, 4, 5],# 노드 3 → 노드 1, 4, 5와 연결
    [3, 5],   # 노드 4 → 노드 3, 5와 연결
    [3, 4],   # 노드 5 → 노드 3, 4와 연결
    [7],      # 노드 6 → 노드 7과 연결
    [2, 6, 8],# 노드 7 → 노드 2, 6, 8과 연결
    [1, 7]    # 노드 8 → 노드 1, 7과 연결
]

# 방문 여부 리스트 초기화
visited = [False] * 9  # 0~8번 인덱스, 0번은 사용하지 않음

# --- BFS 실행 ---
breadth_first_search(graph, 1, visited)  # 1번 노드부터 BFS 시작
