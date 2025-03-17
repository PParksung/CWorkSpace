#include <stdio.h>
typedef unsigned char *pointer;

void show_bytes(pointer start, int len){
    int i;
    for(i=0; i<len; i++){
        printf("0x%p\t0x%.2x\n", start+i, start[i]);
        printf("\n");
    }
}
int main(){
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1); /* A */
    show_bytes(valp, 2); /* B */
}