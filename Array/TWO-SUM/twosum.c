// O(n^2) solution
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *out = calloc(2,sizeof(int));
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        
        for ( int j = i + 1; j < numsSize; j++ ) {

            if ( j >= numsSize ) {
                break;
            }

            int sum = nums[i] + nums[j];

            if( sum == target )
            {
                *returnSize = 2;
                out[0] = i;
                out[1] = j;
                break;
            }
        }
    }

    return out;
}

//O(nlogn)
typedef struct {
    int val;
    int index;
} Pair;

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return ((Pair *)a)->val - ((Pair *)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].val = nums[i];
        pairs[i].index = i;
    }

    // Sort the pairs based on values
    qsort(pairs, numsSize, sizeof(Pair), compare);

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int sum = pairs[left].val + pairs[right].val;
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = pairs[left].index;
            result[1] = pairs[right].index;
            *returnSize = 2;
            free(pairs);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    free(pairs);
    return NULL;
}

//O(n) solution
// Structure to store element-index pairs
typedef struct {
    int val;
    int index;
} Pair;

// Hash table implementation
typedef struct {
    Pair* data;     // Array of element-index pairs
    int size;       // Size of the hash table
} HashTable;

// Function to initialize a hash table
HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->data = (Pair*)malloc(size * sizeof(Pair));
    for (int i = 0; i < size; i++) {
        table->data[i].val = -1;    // Initialize with -1 (indicating empty)
        table->data[i].index = -1;
    }
    table->size = size;
    return table;
}

// Function to insert an element-index pair into the hash table
void insert(HashTable* table, int val, int index) {
    int hash = abs(val) % table->size;
    while (table->data[hash].index != -1) {
        hash = (hash + 1) % table->size;    // Linear probing for collision resolution
    }
    table->data[hash].val = val;
    table->data[hash].index = index;
}

// Function to retrieve the index of an element from the hash table
int find(HashTable* table, int val) {
    int hash = abs(val) % table->size;
    while (table->data[hash].val != val && table->data[hash].index != -1) {
        hash = (hash + 1) % table->size;    // Linear probing for collision resolution
    }
    if (table->data[hash].val == val) {
        return table->data[hash].index;
    }
    return -1;  // Element not found
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* table = createHashTable(numsSize * 2); // Double the size to reduce collisions
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = find(table, complement);
        if (complementIndex != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            free(table->data);
            free(table);
            return result;
        }
        insert(table, nums[i], i);
    }
    *returnSize = 0; // No solution found
    free(table->data);
    free(table);
    return NULL;
}
