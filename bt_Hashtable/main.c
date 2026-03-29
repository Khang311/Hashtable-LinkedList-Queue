#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    HashTable *ht = ht_create(10);

    ht_put(ht, 1, "Marsh");
    ht_put(ht, 2, "John");
    ht_put(ht, 3, "Mary");
    ht_put(ht, 4, "Mary");
    ht_put(ht, 5, "Mary");
    ht_put(ht, 6, "John");
    ht_put(ht, 7, "Marsh");
    ht_put(ht, 8, "John");
    ht_put(ht, 9, "Mary");

    // c1
    char *result = ht_mostFrequentValue(ht);
    printf("Value most frequent: %s\n", result ? result : "None");
    ht_destroy(ht);

    //c2
    int arr[] = {1,7,5,9,2,12,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Count pairs with diff %d: %d\n", 3, countPairsWithDiff(arr, n, 3));

    //c3
    printf("Two Sum for target: ");
    twoSum(arr, n, 9);
    return 0;
}
