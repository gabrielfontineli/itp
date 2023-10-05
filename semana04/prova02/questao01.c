#include <stdio.h>
int main(void){
    int n, m;
    int classem = 0, hostil = 0, aquatico = 0, desertico = 0, selvagem = 0, inospito = 0;
    scanf("%i %i", &n, &m);
    int total = n * m;
    char terreno[n][m];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < m; j++){
            scanf("%c", &terreno[i][j]);
            switch (terreno[i][j]){
                case '~': aquatico++;
                    break;
                case 'X': hostil = 1;
                    break;
                case '^': desertico++;
                    break;
                case '*': selvagem++;
                    break;
            }
        }
    }
    if (total * 85 / 100 <= aquatico){
        aquatico = 1;
        desertico = 0;
        selvagem = 0;
    }
    else if (total * 60 / 100 <= desertico){
        desertico = 1;
        aquatico = 0;
        selvagem = 0;
    }
    else if (total * 65 / 100 < selvagem){
        selvagem = 1;
        aquatico = 0;
        desertico = 0;
    }
    else if ((total / 2 <= aquatico) && (total / 5 <= selvagem) && (hostil == 0.0)){
        classem = 1;
        aquatico = 0;
        selvagem = 0;
        desertico = 0;
        inospito = 0;
    }
    else if (hostil){
        classem = 0;
        aquatico = 0;
        selvagem = 0;
        desertico = 0;
        inospito = 0;
    }
    else{
        inospito = 1;
        aquatico = 0;
        desertico = 0;
        selvagem = 0;
    }
    int tipos[6] = {classem, hostil, aquatico, desertico, selvagem, inospito};
    char* plan[6];
    plan[0] = "Classe M";
    plan[1] = "Hostil";
    plan[2] = "Aquático";
    plan[3] = "Desértico";
    plan[4] = "Selvagem";
    plan[5] = "Inóspito";
    for (int k = 0; k < 6; k++){
      if (tipos[k]){
        printf("Planeta %s\n", plan[k]);
        break;
      }
    }
}