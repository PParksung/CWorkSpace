#include <stdio.h>

int main(){
    char map[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf(" %c", &map[i][j]);
        }
    }

    int dx[4] = {-1, 0, 0, 1}; // 상하 확인
    int dy[4] = {0, -1, 1, 0}; // 좌우 확인
    int count = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            count = 0;
            if(map[i][j] == '.'){
                for(int k = 0; k < 4; k++){ // 4방향 확인
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx][ny] == '*'){
                        count++;
                    }
                }
                
                if(count == 0){
                    printf("_");
                }else{
                    printf("%d", count);
                }
            }else if(map[i][j] == '*'){
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
