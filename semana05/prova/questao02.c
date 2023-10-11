//nao ta certo ainda

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char texto[51], padrao[51];
    bool caracteres_no_padrao[256] = {false}; // tabela ASCII

    // Ler entrada
    scanf("%s", texto);
    scanf("%s", padrao);

    int lenTexto = strlen(texto);
    int lenPadrao = strlen(padrao);

    // Marcar os caracteres que aparecem no padrão
    for (int i = 0; i < lenPadrao; i++) {
        caracteres_no_padrao[(int) padrao[i]] = true;
    }

    int i = 0;
    bool encontrou = false;
    while (i <= lenTexto - lenPadrao) {
        // Verificar se o primeiro caractere da subsequência está na tabela
        if (!caracteres_no_padrao[(int) texto[i]]) {
            printf("%c não\n", texto[i]);
            i++;
            continue;
        }

        bool casou = true;
        for (int j = 0; j < lenPadrao; j++) {
            printf("%c ", texto[i + j]);
            if (texto[i + j] != padrao[j]) {
                casou = false;
                printf("não\n");
                break;
            }
        }

        if (casou) {
            printf("sim\n");
            encontrou = true;
            break;
        }

        i++;
    }

    if (encontrou) {
        printf("Achei o padrão no índice %d\n", i);
    } else {
        printf("Não achei o padrão\n");
    }

    return 0;
}
