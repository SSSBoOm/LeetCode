double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    float IndexFine = ((nums1Size + nums2Size + 1) / 2.00) - 1.00;
    int IndexN1 = 0, IndexN2 = 0;
    // ค่าตรงกลาง
    if((IndexFine * 10) - ((int)IndexFine) * 10 == 0 ) {
        for(int i = 0; i <= IndexFine; i++) {
            // เหลือ 2Arr
            if(IndexN1 < nums1Size && IndexN2 < nums2Size) {
                if(nums1[IndexN1] < nums2[IndexN2]) {
                    if(i == IndexFine) {
                        return nums1[IndexN1];
                    }
                    IndexN1++;
                }
                else {
                    if(i == IndexFine) {
                        return nums2[IndexN2];
                    }
                    IndexN2++;
                }
            }
            // เหลือ Arr1
            else if(IndexN1 < nums1Size && IndexN2 == nums2Size) {
                if(i == IndexFine) {
                    return nums1[IndexN1];
                }
                IndexN1++;
            }
            // เหลือ Arr2
            else if(IndexN1 == nums1Size && IndexN2 < nums2Size) {
                if(i == IndexFine) {
                    return nums2[IndexN2];
                }
                IndexN2++;
            }
        }
    }

    // เฉลี่ย
    else {
        int *newArr = calloc(sizeof(int), (int)IndexFine + 2);
        for(int i = 0; i <= (int)IndexFine + 1; i++) {
            // เหลือ 2Arr
            if(IndexN1 < nums1Size && IndexN2 < nums2Size) {
                if(nums1[IndexN1] < nums2[IndexN2]) {
                    newArr[i] = (int)nums1[IndexN1];
                    IndexN1++;
                }
                else {
                    newArr[i] = (int)nums2[IndexN2];
                    IndexN2++;
                }
            }
            // เหลือ Arr1
            else if(IndexN1 < nums1Size && IndexN2 == nums2Size) {
                newArr[i] = (int)nums1[IndexN1];
                IndexN1++;
            }
            // เหลือ Arr2
            else if(IndexN1 == nums1Size && IndexN2 < nums2Size) {
                newArr[i] = (int)nums2[IndexN2];
                IndexN2++;
            }
        }
        return (double)((newArr[(int)IndexFine] + newArr[(int)IndexFine + 1]) / 2.00);
    }
    return 0;
}