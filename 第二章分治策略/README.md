# 算法设计与分析实验报告

姓名：胡舸耀

学号：22336084

## 一、算法实现思想

### 1.1 设计思路

为实现书籍分配，首先我们利用给出数据预估来找到一个页数的阈值，表示给某个学生分配的最大页数。通过设置一个可能的最大页数范围：最小值是数组中页数最大的书页数，最大值是所有书页数的和。为实现时间复杂度不超过NlogN，利用贪心法验证该阈值是否能让书籍成功分配给所有学生，确保每个学生阅读的页数不超过该阈值。若可以分配，表示该阈值可以进一步降低，若不能分配，说明阈值过小，需要增大。

### 1.2 算法步骤

1. 先设定二分查找的左右边界，左边界为书本中页数的最大值，右边界为所有书的页数之和。（时间复杂度NlogN）
2. 每次通过二分查找得到一个中间值（假设的最大页数阈值），用贪心法尝试将书分配给M个学生。如果能够成功分配，尝试进一步降低阈值；如果不能，增大阈值。
3. 最终找到可以分配的最小阈值。

## 二、实验结果

![1730290041429](image/s/1730290041429.png)

可以看到正确输出结果

## 三、源代码

```python
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
```
