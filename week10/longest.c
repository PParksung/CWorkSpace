#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 16

int maxstr(char str[][ARRAY_SIZE], int N)
{
    int max_length = 0;
    int max_index = 0;

    for(int i=0; i<N; i++){
        int length = strlen(str[i]);
        if(length>max_length){
            max_length = length;
            max_index = i;
        }
    }

    return max_index;
}

int main()
{
    int N;
    scanf("%d", &N);
    char str[N][16];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", str[i]);
    }

    int index = maxstr(str, N);

    printf("%s\n", str[index]);

}