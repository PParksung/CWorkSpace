#include <stdio.h>

int main() {
    char board[10][10];
    int sec;  
    

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            board[i][j] = '.';
        }
    }
    
    scanf("%d", &sec);
    int pathLength = 0; 
    int layer = 0;
    
   
    for(int size = 10; size > 0; size -= 2) {
        if(pathLength == sec+1) {
            break;
        }

        for(int x = 0; x < size; x++) {
            if(pathLength == sec+1) {
                break;
            }
            board[layer][layer+x] = '#';
            pathLength++;
        }

        for(int y = 1; y < size; y++) {
            if(pathLength == sec+1) {
                break;
            }
            board[layer+y][10-layer-1] = '#';
            pathLength++;
        }
        for(int x = 1; x < size; x++) {
            if(pathLength == sec+1) {
                break;
            }
            board[layer+size-1][10-layer-x-1] = '#';
            pathLength++;
        }
        for(int y = 1; y < size-1; y++) {
            if(pathLength == sec+1) {
                break;
            }
            board[10-layer-y-1][layer] = '#';
            pathLength++;
        }
        layer++;
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}