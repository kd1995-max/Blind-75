// nive
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
