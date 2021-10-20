#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int* arr, int target, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return BinarySearch(arr, target, mid + 1, right);
    if (arr[mid] < target)
        return BinarySearch(arr, target, left, mid - 1);
}

int main(void)
{
    int n, q;
    int *sqn, qry;
    int left, right, mid;

    while(~scanf("%d%d", &n, &q)) {   
        sqn = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &sqn[i]);
        while (q--) {
            scanf("%d", qry);
            if (mid == )
        }
        free(sqn);
    }
    return 0;
}