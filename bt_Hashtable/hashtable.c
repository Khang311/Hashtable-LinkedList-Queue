#include "hashtable.h"

static int ht_hash(int key, int capacity)
{
    if (capacity <= 0)
        return 0;
    int h = key % capacity;
    return h;
}


HashTable *ht_create(int capacity)
{
    if (capacity <= 0)
        capacity = 10;

    HashTable *ht = malloc(sizeof(HashTable));

    if (!ht)
    {
        fprintf(stderr, "Failed to allocate memory!\n");
        return NULL;
    }

    ht->capacity = capacity;
    ht->buckets = calloc(capacity, sizeof(Entry *));

    if (!ht->buckets)
    {
        fprintf(stderr, "Failed to allocate memory!\n");
        return NULL;
    }

    return ht;
}


void ht_destroy(HashTable *ht)
{
    if (!ht)
        return;

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];
        while (cur != NULL)
        {
            Entry *temp = cur;
            cur = cur->next;
            free(temp->value);
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}


void ht_put(HashTable *ht, int key, const char *value)
{
    int index = ht_hash(key, ht->capacity);
    Entry *cur = ht->buckets[index];

    // Tìm key có tồn tại
    while (cur != NULL)
    {
        if (cur->key == key)
        {
            free(cur->value);
            cur->value = strdup(value);
        }
        cur = cur->next;
    }

    // Nếu tìm không ra key tại vị trí index
    // Thì tạo ra key mới
    Entry *node = malloc(sizeof(Entry));
    node->key = key;
    node->value = strdup(value);

    node->next = ht->buckets[index];
    ht->buckets[index] = node;
}


char *ht_get(HashTable *ht, int key)
{
    if (!ht)
        return NULL;

    Entry *cur = ht->buckets[ht_hash(key, ht->capacity)];

    while (cur && cur->key != key)
        cur = cur->next;

    return cur ? cur->value : NULL;
}


int ht_containsKey(HashTable *ht, int key)
{
    return ht_get(ht, key) != NULL;
}


int ht_containsValue(HashTable *ht, const char *value)
{
    if (!ht || !value)
        return 0;

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];

        while (cur != NULL)
        {
            if (cur->value && strcmp(cur->value, value) == 0)
                return 1;

            cur = cur->next;
        }
    }

    return 0;
}


void ht_remove(HashTable *ht, int key)
{
    if (!ht)
        return;

    int index = ht_hash(key, ht->capacity);
    Entry *cur = ht->buckets[index];
    Entry *prev = NULL;

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            if (prev == NULL)
            {
                ht->buckets[index] = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }

            free(cur->value);
            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}


void ht_printEntries(HashTable *ht)
{
    printf("Hastable Entries List\n");

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];
        if (!cur)
            continue;

        printf("Bucket[%d]: ", i);

        while (cur != NULL)
        {
            printf("(%d):(%s)", cur->key, cur->value);
            cur = cur->next;
        }
        printf("\n");
    }
}


void ht_printKeys(HashTable *ht)
{
    if (!ht)
        return;

    printf("Keys: ");

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];

        while (cur != NULL)
        {
            printf("%d ", cur->key);
            cur = cur->next;
        }
    }
    printf("\n");
}

// c1
char *ht_mostFrequentValue(HashTable *ht)
{
    if (ht == NULL)
        return NULL;


    char *mostFrequent = NULL;
    int maxCount = 0;

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];


        while (cur != NULL)
        {
            char *targetValue = cur->value;
            int count = 0;

            for (int j = 0; j < ht->capacity; j++)
            {
                Entry *runner = ht->buckets[j];
                while (runner != NULL)
                {
                    if (strcmp(runner->value, targetValue) == 0)
                    {
                        count++;
                    }
                    runner = runner->next;
                }
            }

            if (count > maxCount)
            {
                maxCount = count;
                mostFrequent = targetValue;
            }
            cur = cur->next;
        }
    }
    return mostFrequent;
}

//c2
int countPairsWithDiff(int arr[], int n, int k) 
{
    HashTable *ht = ht_create(n * 2);
    for (int i = 0; i < n; i++)
    {
        ht_put(ht, arr[i], "1");
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ht_containsKey(ht, arr[i] + k))
        {
            count++;
        }
    }
    ht_destroy(ht);
    return count;
}

//c3
void twoSum(int arr[], int n, int target)
{
    HashTable *ht = ht_create(n * 2);
    for (int i = 0; i < n; i++)
    {
        int comp = target - arr[i];
        char *A = ht_get(ht, comp);
        if (A)
        {
            printf("[%d, %d]\n", atoi(A), i);
            ht_destroy(ht);
            return;
        }
        char c[16];
        sprintf(c, "%d", i);
        ht_put(ht, arr[i], c);
    }
    printf("Not Found\n");
    ht_destroy(ht);
}