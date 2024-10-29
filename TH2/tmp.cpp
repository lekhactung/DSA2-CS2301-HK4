void DFS(int x)
{
    stack s;
    init(s);
    push(s, x);            // Đưa đỉnh bắt đầu vào ngăn xếp
    dfs[ndfs++] = x;
    C[x] = 0;

    while (!isEmpty(s))
    {
        int u = pop(s);    // Lấy đỉnh ở đầu ngăn xếp và xóa nó
        bool hasUnvisitedNeighbor = false;

        for (int v = 0; v < n; v++) {
            if (A[u][v] != 0 && C[v] == 1) { // Kiểm tra đỉnh kề chưa xét
                push(s, u);                 // Đẩy lại đỉnh hiện tại vào ngăn xếp
                push(s, v);                 // Đẩy đỉnh kề vào ngăn xếp
                dfs[ndfs++] = v;            // Ghi nhận vào danh sách DFS
                C[v] = 0;                   // Đánh dấu đỉnh kề đã xét
                hasUnvisitedNeighbor = true;
                break;                      // Dừng vòng lặp vì đã tìm thấy đỉnh kề chưa xét
            }
        }

        if (!hasUnvisitedNeighbor && isEmpty(s)) {
            push(s, u); // Nếu không có đỉnh kề chưa xét, tiếp tục duyệt đỉnh tiếp theo
        }
    }
}
