#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    float image[5][5][3];
    float MAXr=0.000000, MAXb=0.000000, MAXg=0.000000, temp;
    int x, y;
    FILE *data;
    data = fopen("data.txt", "w+");
    
    srand(0);
    
    for(y = 0; y < 5; y++) {
        for(x = 0; x < 5; x++) {
            image[x][y][0] = (float)rand()/(float)INT_MAX;
            image[x][y][1] = (float)rand()/(float)INT_MAX;
            image[x][y][2] = (float)rand()/(float)INT_MAX;
        }
    }
    
    // ----------------------------------------
    // Write your code below this comment block
    // ----------------------------------------
    
    //printing all data to the screen
    for(y = 0; y < 5; y++) {
        for(x = 0; x < 5; x++) {
            printf("red: %f blue: %f green: %f\n", image[x][y][0], image[x][y][1], image[x][y][2]);
        }
    }
    
    
    for(y = 0; y < 5; y++) {
        for(x = 0; x < 5; x++) {
            fprintf(data, "%f\n%f\n%f\n", image[x][y][0], image[x][y][1], image[x][y][2]);
        }
    }
    
    rewind(data);
    
    for(y = 0; y < 5; y++) {
        for(x = 0; x < 5; x++) {
            fscanf(data, "%f", &temp);
            if(temp>MAXr){
                MAXr=temp;
            }
            fscanf(data, "%f", &temp);
            if(temp>MAXb){
                MAXb=temp;
            }
            fscanf(data, "%f", &temp);
            if(temp>MAXg){
                MAXg=temp;
            }
        }
    }
    
    fclose(data);
    
    printf("maximum red: %f maximum blue: %f maximum green: %f\n", MAXr, MAXb, MAXg);
    
    return 0;
}
