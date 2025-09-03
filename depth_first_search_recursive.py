def depth_first_search_recursive(graph, v, visited):
    # 현재 노드를 방문 처리 (다시는 방문하지 않도록 표시)
    visited[v] = True
    # 방문한 노드 출력
    print(v, end=' ')
    
    # 현재 노드와 연결된 다른 노드를 차례대로 확인
    for i in graph[v]:
        # 만약 아직 방문하지 않은 노드라면 재귀적으로 DFS 수행
        if not visited[i]:
            depth_first_search_recursive(graph, i, visited)


# 그래프를 인접 리스트 방식으로 표현 (1번 노드부터 사용, 0번은 비워둠)
graph = [
    [],             # 0번 노드 (사용하지 않음)
    [2, 3, 8],      # 1번 노드와 연결된 노드들
    [1, 7],         # 2번 노드와 연결된 노드들
    [1, 4, 5],      # 3번 노드와 연결된 노드들
    [3, 5],         # 4번 노드와 연결된 노드들
    [3, 4],         # 5번 노드와 연결된 노드들
    [7],            # 6번 노드와 연결된 노드들
    [2, 6, 8],      # 7번 노드와 연결된 노드들
    [1, 7]          # 8번 노드와 연결된 노드들
]

# 각 노드가 방문된 정보를 저장하는 리스트
# 인덱스와 노드 번호를 맞추기 위해 크기를 9로 설정 (0~8)
visited = [False] * 9
#[False, False, False, False, False, False, False, False, False]
#이렇게 9개의 False 값이 있는 리스트가 만들어집니다.

# 왜 크기를 9로 했나? (0~8) 
# 리스트의 인덱스와 노드 번호를 맞추기 위해 0번 인덱스는 사용하지 않고 1~8을 씁니다.
# 0번은 비워두거나 그냥 안 쓰는 경우가 많아요.

# 1번 노드에서 시작하여 DFS 수행
depth_first_search_recursive(graph, 1, visited)
