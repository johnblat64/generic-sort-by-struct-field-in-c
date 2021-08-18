#include <stdlib.h>
#include <stdio.h>

typedef struct FakeStruct {
    int x;
    int y; 
    int z;
    int w;
    int h;
    int textureId;
} FakeStruct;

#define sortStruct(arr, T, len, fieldSortBy) \
({ \
    for( int i = 0; i < len; i++ ) { \
        int j = i - 1; \
        T tempVal = arr[i]; \
        while( ( j >= 0) && (arr[j].fieldSortBy > tempVal.fieldSortBy ) ) { \
            arr[j + 1] = arr[j]; \
            j--; \
        } \
        arr[j+1] = tempVal; \
    } \
})


int
main() {
    FakeStruct arr[8];
    arr[0] = (FakeStruct){0,0,7,10,10,1};
    arr[1] = (FakeStruct){1,10,15,10,10,1};
    arr[2] = (FakeStruct){0,0,20,10,50,1};
    arr[3] = (FakeStruct){60,2,-5,15,10,1};
    arr[4] = (FakeStruct){7,3,8,10,3,1};
    arr[5] = (FakeStruct){5,-8,-50,10,17,1};
    arr[6] = (FakeStruct){20,30,17,10,16,1};
    arr[7] = (FakeStruct){0,0,6,10,18,1};

    sortStruct(arr, FakeStruct, 8, z);

    for(int i = 0; i < 8; i++) {
        fprintf(stdout, "x=%d, y=%d, z=%d, w=%d, h=%d, tId=%d\n", arr[i].x, arr[i].y, arr[i].z, arr[i].w, arr[i].h, arr[i].textureId);
    }
    

    exit(0);
}