/*
Um dos principais algoritmos na área de computação gráfica é o algoritmo de recorte utilizado para determinar quais partes de um objeto devem ser exibidos na tela. Você deve desenvolver uma versão simplificada utilizada num programa de processamento de retângulos indicando se um retângulo está dentro de outro. Neste programa, os retângulos são representados por dois pontos: <esquerdo, inferior> e o <direito, superior>.

O programa deve iniciar recebendo as informações do retângulo da tela representando a área visível e para cada retângulo subsequente ele deve determinar se ele está contido, contém ou possui uma interseção com a área visível, ou seja, necessita de um tratamento para exibição. A entrada encerra com os valores 0,0,0,0. Você deve implementar uma função para efetuar essa verificação, ou seja, dados dois retângulos, determinar se o primeiro contém o segundo, ou se o segundo contém o primeiro, ou se nada pode ser afirmado. Desse modo, você deve identificar quais são os parâmetros, o retorno e como ela será aplicada no programa principal.

Por exemplo, na figura abaixo, a tela (retângulo A) é especificada pelos pontos <5,5> e <10,10> e o retângulo B pelos pontos <7,7> e <8,8>, neste caso, o retângulo B se encontra dentro do A.




Já na imagem abaixo, não podemos afirmar se A contém B ou se B contém A.


Observe o formato de entrada e saída nos casos de teste para indicar quando um retângulo contém ou está contido em relação ao retângulo da área visível.

A solução deve apresentar uma função e não deve ter variáveis globais.

Exemplo de entrada	
10 10 20 20
0 0 30 30
0 0 0 0
Exemplo de saída
(<0.00,0.00>,<30.00,30.00>) contem (<10.00,10.00>,<20.00,20.00>).
Exemplo de entrada
0 0 1 1
0 0 1 1
0 0 0 0	
Exemplo de saída
Nao posso afirmar!
*/

#include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto esqInf;
    Ponto dirSup;
} Retangulo;

int contem(Retangulo r1, Retangulo r2) {
    if (r1.esqInf.x < r2.esqInf.x 
    && r1.esqInf.y < r2.esqInf.y 
    && r1.dirSup.x > r2.dirSup.x 
    && r1.dirSup.y > r2.dirSup.y)
    {
        return 1;
    } 
    else if (r2.esqInf.x < r1.esqInf.x 
    && r2.esqInf.y < r1.esqInf.y 
    && r2.dirSup.x > r1.dirSup.x 
    && r2.dirSup.y > r1.dirSup.y)
    {
        return 2;
    } 
    else 
    {
        return 0;
    }
}

int main() {
    Retangulo r1, r2;
    int contido;
    scanf("%f %f %f %f", &r1.esqInf.x, &r1.esqInf.y, &r1.dirSup.x, &r1.dirSup.y);
    while (r1.esqInf.x != 0 || r1.esqInf.y != 0 || r1.dirSup.x != 0 || r1.dirSup.y != 0) {
        scanf("%f %f %f %f", &r2.esqInf.x, &r2.esqInf.y, &r2.dirSup.x, &r2.dirSup.y);
        contido = contem(r1, r2);
        if (contido == 1) {
            printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", r1.esqInf.x, r1.esqInf.y, r1.dirSup.x, r1.dirSup.y, r2.esqInf.x, r2.esqInf.y, r2.dirSup.x, r2.dirSup.y);
        } else if (contido == 2) {
            printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", r2.esqInf.x, r2.esqInf.y, r2.dirSup.x, r2.dirSup.y, r1.esqInf.x, r1.esqInf.y, r1.dirSup.x, r1.dirSup.y);
        } else {
            printf("Nao posso afirmar!\n");
        }
        scanf("%f %f %f %f", &r1.esqInf.x, &r1.esqInf.y, &r1.dirSup.x, &r1.dirSup.y);
    }
    return 0;
}
