from collections import deque

def print_grid(graph):
    """그래프 상태를 '101' 형태 문자열로 출력"""
    for row in graph:
        print(''.join(str(cell) for cell in row))
    print()

def read_row_strict(m):
    """
    공백이 있는 행('1 0' 등)은 무시(다시 입력받음).
    길이가 m이 아닌 행도 무시.
    """
    while True:
        s = input().strip()
        if ' ' in s:
            print("띄어쓰기 있는 행은 무시합니다. (다시 입력하세요)")
            continue
        if len(s) != m:
            print(f"입력 길이가 {m}이 아닙니다. (입력한 길이: {len(s)}) 다시 입력하세요.")
            continue
        try:
            row = [int(ch) for ch in s]
        except ValueError:
            print("숫자가 아닌 문자가 포함되어 있습니다. 다시 입력하세요.")
            continue
        return row

def bfs_with_steps(start_x, start_y, n, m, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    # 시작이 벽이면 탐색 불가
    if graph[start_x][start_y] == 0:
        print("시작점이 벽(0)입니다. 탐색 불가.")
        return -1

    # 방문 배열을 따로 둔다 (이게 핵심 수정)
    visited = [[False] * m for _ in range(n)]
    q = deque()
    q.append((start_x, start_y))
    visited[start_x][start_y] = True   # 시작을 '이미 방문'으로 표시

    step = 0
    print("초기 상태:")
    print_grid(graph)

    while q:
        x, y = q.popleft()

        # 목적지에 도달하면 현재 그래프의 값(거리)을 출력하고 종료
        if x == n - 1 and y == m - 1:
            print(f"목적지에 도달했습니다. 최종 거리: {graph[x][y]}")
            return graph[x][y]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 경계 검사
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            # 벽이면 무시
            if graph[nx][ny] == 0:
                continue

            # 미방문이면 방문 처리하고 거리 갱신
            if not visited[nx][ny]:
                visited[nx][ny] = True
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx, ny))

                step += 1
                print(f"Step {step}: (방문한 칸: ({nx}, {ny}), 거리={graph[nx][ny]})")
                print_grid(graph)

    print("목적지에 도달할 수 없습니다.")
    return -1

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = [read_row_strict(m) for _ in range(n)]
    result = bfs_with_steps(0, 0, n, m, graph)
    if result == -1:
        print("도달 불가")
    else:
        print(f"최종 결과(최단거리): {result}")
