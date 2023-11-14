#include <stdio.h>
int main(void){
    int larg, altu, num, divisor, valor = 0;
    char cor;
    scanf("%i %i %c", &larg, &num, &cor);
    divisor = larg / 3;
    altu = 2 * larg / 3;
    int num2 = num;
    int reset = num2;
    switch(cor){
        case 'G': num++;
            break;
        case 'Y': num += 2;
            break;
        case 'R': num += 3;
            break;
    }
    int bandeira[larg][altu];

    for (int j = 0; j < altu; j++){
        num2 = reset;
        for (int i = 0; i < larg; i++){
            bandeira[i][j] = num2 + 1;
            if ((i + 1) % divisor == 0){
                num2++;
            }
        }
    }

    for (int i = 0; i < altu; i++){
        for (int j = 0; j < larg; j++){
            if (bandeira[j][i] == num){
                valor += num;
            }   
        }
    }
    printf("%i", valor);
}