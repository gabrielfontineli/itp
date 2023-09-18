#include <stdio.h>

void verificar(float, float, float, float, float, float, float, float);

int main() {
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    while(1) {
        float x3, y3, x4, y4;
        scanf("%f %f %f %f", &x3, &y3, &x4, &y4);
      
        if(x3 == 0.0 && y3 == 0.0 && x4 == 0.0 && y4 == 0.0) {
            break;
        }

        verificar(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    return 0;
}

void verificar(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    if(x1 == x3 && y1 == y3 && x2 == x4 && y2 == y4) {
        printf("Nao posso afirmar!\n");
    } else if(x1 <= x3 && y1 <= y3 && x2 >= x4 && y2 >= y4){
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", x1, y1, x2, y2, x3, y3, x4, y4);
    } else if(x1 >= x3 && y1 >= y3 && x2 <= x4 && y2 <= y4) {
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", x3, y3, x4, y4, x1, y1, x2, y2);
    } else {
        printf("Nao posso afirmar!\n");
    }
}