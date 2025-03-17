#include <stdio.h>

struct miniHomePage{
    int id;
    int visitor;
};

int main() {
    struct miniHomePage mini[10];
    int inputID;

    for(int i = 0; i < 10; i++) {
        mini[i].id = 100 + i;
        mini[i].visitor = 0;
    }

    while(1) {
        scanf("%d", &inputID);
        if(inputID < 0) {
            break;
        }

        for(int i = 0; i < 10; i++) {
            if(mini[i].id == inputID) {
                mini[i].visitor ++;
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("%d:%d\n", mini[i].id, mini[i].visitor);
    }

    return 0;
}
