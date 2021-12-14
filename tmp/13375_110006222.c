#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char strs[100001][105];

int CharCMP(char a, char b) {
    if (a >= 'A' && a <= 'Z')
}

int CMP(const void *l, const void *r)
{
    const char *L = (const char*)l;
    const char *R = (const char*)l;
    return strcmp(R, L);
}
// void sort(const char *arr[], int n)
// {
//     qsort(arr, n, sizeof(const char *), cmp);
// }

int main()
{
    char *names[105] = {"ABC", "abc", "Wilson", "Jason", "Zip"};

    for (int i = 0; i < 5; i++)
        printf("%s\n", names[i]);
    qsort(names, 5, sizeof(char*), CMP);
    for (int i = 0; i < 5; i++)
        printf("%s\n", names[i]);
}