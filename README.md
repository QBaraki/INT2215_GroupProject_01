# Báo cáo Bài tập lớn - Nhóm 3

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò | Công việc |
|---|---|---|---|---|
| 1 | Bùi Thanh Quang | 24022826 | Nhóm trưởng | Code và tổng hợp |
| 2 | Nguyễn Tiến Đạt | 24022875 | Thành viên | Nội dung và nói |
| 3 | Nguyễn Tiến Nam | 24022819 | Thành viên | Nội dung và Slide |
| 4 | Phạm Gia Bảo | 24022769 | Thành viên | Nội dung và Slide |
| 5 | Võ Hồng Duy | 24022781 | Thành viên | Nội dung và Slide |



## 2. Thông tin bài tập
- **Mã đề**: 4.
- **Tên bài toán**: Tìm đường đi ngắn nhất trong mê cung có chướng ngại vật.
- **Yêu cầu bài toán**: Cho một mê cung có độ lớn $n \times n$ có chướng ngại vật.
Tìm đường đi ngắn nhất từ ô $(0,0)$ tới ô $(n-1,n-1)$.

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán

Cho một mê cung có độ lớn $n \times n$, một số ô có chướng ngại vật.
Tại một ô, được phép di chuyển sang ô kề cạnh ở bốn hướng: lên, xuống, trái, phải; và không được phép di chuyển vào ô có chướng ngại vật.
Tìm đường đi ngắn nhất từ ô $(0,0)$ tới ô $(n-1,n-1)$.
Nếu không tìm thấy đáp án, in ra `IMPOSSIBLE` (bất khả thi).

#### Đầu vào

Dòng đầu tiên gồm một số nguyên $n$ ($1 \leq n \leq 100$) --- là độ lớn của ma trận.

Trong $n$ dòng tiếp theo, gồm $m$ ký tự $\text{grid}_{i,j}$ chỉ chứa một trong hai ký tự: "`#`" hoặc là "`.`" --- biểu thị cho việc tại ô $(i, j)$ có chứa chướng ngại vật hay không.

#### Đầu ra

Gồm một dòng duy nhất là số bước đi ngắn nhất đã tìm được.
Nếu không có thì in ra `IMPOSSIBLE`.

### b. Thuật toán/Hướng tiếp cận

Để giải quyết bài toán, ta sẽ sử dụng thuật toán DFS kết hợp với việc lưu trữ giá trị khoảng cách đi được từ điểm bắt đầu đến các ô trong ma trận để làm cho thời gian thực thi giảm đi.

#### Giới thiệu về thuật toán DFS

DFS, hay còn được gọi là Depth First Search, là một thuật toán tìm kiếm theo chiều sâu trên một đồ thị.
DFS đi theo một hướng cho đến khi không thể đi tiếp, rồi quay lại và thử hướng khác.

#### Cách thực thi

Đầu tiên, ta có thể mô hình hóa bài toán bằng cách cho rằng ma trận ban đầu là một đơn đồ thị không có trọng số.
Sau đó, ta sử dụng DFS kết hợp việc lưu trữ các giá trị bước đi đã tính trước đó để tìm ra đường đi ngắn nhất từ điểm bắt đầu $(0, 0)$ đến điểm đích $(n-1, n-1)$.

## 4. Phân tích mã nguồn

### Về mã nguồn
- `kInf`: Đại diện cho một giá trị vô cùng lớn, có ý nghĩa giúp đánh dấu các ô chưa được thăm hoặc là ô không thể đến được.
- `grid`: Là một mảng hai chiều. Đây là ma trận mà mình đang cần phải tìm đường đi ngắn nhất. Tại một vị trí $(i, j)$, ta quan niệm rằng ô đó chứa chướng ngại vật khi nó là ký tự dấu thăng (`#`); ngược lại, nó là dấu chấm (`.`).
- `dist[x][y]`: Mảng hai chiều, được dùng để lưu trữ số bước ít nhất đi được từ ô ban đầu đến ô hiện tại $(x, y)$.
- Hàm `DFS()`: Hàm đệ quy thực hiện thuật toán.
- Hàm `main()`: Thực hiện việc nhập dữ liệu (kích thước của ma trận và ma trận), gọi hàm `DFS()` và in ra kết quả.

### Về hàm DFS
- Chức năng chính của hàm là cập nhật khoảng cách nhỏ nhất đến mỗi ô trong ma trận nếu có thể đi qua khi bắt đầu từ vị trí $(0, 0)$.
- Các giá trị tham số:
  - `grid`: Ma trận ban đầu.
  - `n`: kích thước của ma trận
  - `dist`: Mảng khoảng cách đã nói trước đó.
  - `x`, `y`: Tọa độ hiện tại đang xét theo hàng và cột.
  - `current`: Số bước hiện tại đang xét tính từ vị trí $(0, 0)$ đến $(x, y)$.
  - Điều kiện để dừng lần đệ quy hiện tại: Khi đi ra ngoài ma trận, gặp ô chướng ngại vật, số bước hiện tại không tối ưu hoặc đã đến đích.
- Tại vị trí $(x, y)$, nếu khoảng cách hiện tại nhỏ hơn giá trị đã lưu `dist[x][y]`, ta cập nhật giá trị đó bằng giá trị current.
- Sau đó, ta duyệt các ô xung quanh bằng cách gọi đệ quy lần lượt đến các ô đó.

## 5. Ví dụ minh hoạ
### Ví dụ 1:

**Input:**
```
6
.#####
..#...
#...#.
..###.
.#....
...##.
```

**Output:**
```
12
```

**Giải thích:**

Ma trận có hai đường đi, lần lượt có số bước đi là `14` và `12`.

### Ví dụ 2
**Input:**
```
6
.....#
####.#
.....#
.#####
.##...
....#.
```

**Output:**
```
20
```

**Giải thích:**

Ma trận chỉ có một đường đi duy nhất với số bước đi là `20`.

### Ví dụ 3
**Input:**
```
3
.#.
.#.
.#.
```

**Output:**
```
IMPOSSIBLE
```

**Giải thích:**

Ma trận không có đường đi.

## 6. Kết luận

Ta đã sử dụng DFS để giải quyết bài toán tìm đường đi ngắn nhất trong một ma trận có chướng ngại vật.

Với một ma trận đủ nhỏ, thuật toán DFS có thể được áp dụng; nhưng với một ma trận có quá nhiều đường đi cần phải xét, thì thuật toán sẽ mất nhiều thời gian thực thi để có thể đưa ra đáp án tối ưu.

## 7. Link video báo cáo

[Video báo cáo nhóm 3](https://www.youtube.com/watch?v=QXtANtu0WiA)

## 8. Link source code
[Thư mục src](./src)
