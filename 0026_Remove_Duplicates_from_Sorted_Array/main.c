int removeDuplicates(int* nums, int numsSize){
    int *numsTemp = calloc(sizeof(int), numsSize);
    int *numsTempPtr1 = nums;
    int *numsTempPtr2 = numsTemp;
    int temp = *nums;
    int k = 1;
    *numsTemp = *nums;
    numsTemp++, nums++;
    for(int i = 1; i < numsSize; i++) {
        if(*nums != temp) {
            *numsTemp++ = *nums;
            temp = *nums;
            k++;
        }
        nums++;
    }
    for(int i = 0; i < k; i++) {
        *numsTempPtr1 = *numsTempPtr2;
        numsTempPtr1++;
        numsTempPtr2++;
    }

    return k;
}