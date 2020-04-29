/**
 * @file 07_HeapSort.cpp
 * @author leslie
 * @date 2020-04-29
 */

#define __07_HEAP_SORT_MAIN_
#ifdef __07_HEAP_SORT_MAIN_

#include <stdio.h>

#endif /* __07_HEAP_SORT_MAIN_ */

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void MaxHeapify(int arr[], int start, int end) {
    /* 建立双亲结点和孩子结点 */
    int dad = start;
    int son = dad * 2 + 1;

    while (son <= end) { /* 若孩子结点在范围内 */
        if (son + 1 <= end && arr[son] < arr[son + 1]) { /* 选择两个孩子中更大的一个 */
            son++;
        }

        if (arr[dad] > arr[son]) { /* 若双亲结点大于孩子结点，表示调整完毕，循环结束 */
            return;
        } else { /* 交换双亲结点和孩子结点，将孩子结点和孙子结点进行比较（也可递归实现） */
            Swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        } /* 实质上是调整为：双亲结点大于左右子树 */
    }
}

void *HeapSort(int arr[], int len) {
    int i;
    for (i = len / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, i, len - 1);
    }
    for (i = len - 1; i > 0; i--) {
        Swap(&arr[0], &arr[i]); /* 交换最大值和最后一个结点 */
        MaxHeapify(arr, 0, i - 1); /* 重新调整堆 */
    }
}

#ifdef __07_HEAP_SORT_MAIN_

int main() {
    int arr[] = { 86, 3, 38, 59, 36, 60, 87, 34, 4, 80, 76, 37, 71, 30, 44, 67, 22, 26, 56, 17 };
    int i;

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");
    HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\t", arr[i]);
    }
}

#endif /* __07_HEAP_SORT_MAIN_ */