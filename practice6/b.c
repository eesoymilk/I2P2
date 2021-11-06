#include <stdio.h>
#include <stdlib.h>

// int BinarySearch(int* arr, int target, int left, int right)
// {
//     if (left >= right)
//         return 0;

//     int mid = (left + right) / 2;

//     if (arr[mid] == target)
//         return mid;
//     if (arr[mid] > target)
//         return BinarySearch(arr, target, mid + 1, right);
//     if (arr[mid] < target)
//         return BinarySearch(arr, target, left, mid - 1);
// }

int main(void)
{
    int n, q;
    int *sqn, qry, ans;
    int left, right, mid;

    while(~scanf("%d%d", &n, &q)) {   
        sqn = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &sqn[i]);
        while (q--) {
            scanf("%d", &qry);
            left = 0;
            right = n - 1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (sqn[mid] == qry)
                    break;
                if (qry < sqn[mid])
                    right = mid - 1;
                if (sqn[mid] < qry)
                    left = mid + 1;
            }
            if (sqn[mid] == qry)
                printf("%d\n", mid + 1);
            else
                printf("Break your bridge!\n");
        }
        free(sqn);
    }
    return 0;
}