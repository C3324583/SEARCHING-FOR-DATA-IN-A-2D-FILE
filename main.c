#include<stdio.h>

int main(){
    FILE *file;
    file = fopen("data", "r");
    int datastorage [3][3];
    int max;
    int row, column;
    
    for(int x=0; x<3; x++){
        for(int i=0; i<3; i++){
            int a;
            fscanf(file, "%d", &a);
            datastorage [x][i] = a;
        }
    }
    
    for(int x=0; x<3; x++){
        for(int i=0; i<3; i++){
            if(datastorage[x][i]>max){
                max = datastorage[x][i];
                row = x;
                column = i;
            }
        }
    }
    printf ("row: %d \ncolumn: %d\nmax int: %d", row, column, max);
    return 0;
}
