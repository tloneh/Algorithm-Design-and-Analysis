def is_possible(books, n, m, max_pages):
    student_count = 1
    current_pages = 0

    for i in range(n):
        if current_pages + books[i] > max_pages:
            student_count += 1
            current_pages = books[i]
            if student_count > m:
                return False
        else:
            current_pages += books[i]

    return True

def find_minimum_pages(books, n, m):
    if m > n:
        return -1

    # 左边界是单本书的最大页数，右边界是所有书页数的和
    left = max(books)
    right = sum(books)
    result = right

    while left <= right:
        mid = (left + right) // 2

        # 检查当前最大页数限制下，是否能够成功分配
        if is_possible(books, n, m, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result

def main():
    #输入
    N = int(input("请输入书的数量 N: "))
    pages = list(map(int, input("请输入每本书的页数（以空格分隔）: ").split()))
    M = int(input("请输入学生的数量 M: "))

    # 输出最小页数
    print(find_minimum_pages(pages, N, M))

if __name__ == '__main__':
    main()