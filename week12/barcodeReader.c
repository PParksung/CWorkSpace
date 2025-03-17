#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct barcode{
    char num[7];
    int decimal;
} Barcode;

int binary(char *num) {
    int decimal = 0;
    int length = strlen(num);
    for (int i = 0; i < length; i++) {
        if (num[i] == '1') {
            decimal += (int)pow(2, length-1-i);
        }
    }
    return decimal;
}

int main() {
    int n;
    scanf("%d", &n);

    Barcode barcodes[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", barcodes[i].num);
        barcodes[i].decimal = binary(barcodes[i].num);
    }

    int index;
    scanf("%d", &index);

    printf("%d\n", barcodes[index - 1].decimal);

    return 0;
}
