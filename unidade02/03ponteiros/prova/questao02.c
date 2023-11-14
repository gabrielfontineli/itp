int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    // Inicializando os índices
    *left_index = -1;
    *right_index = -1;

    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if (cells[mid] == user) {
            *left_index = mid;
            *right_index = mid;
            break;
        } else if (cells[mid] < user) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Ajustando o índice esquerdo
    int temp = mid;
    while(temp >= 0 && user - cells[temp] <= distance) {
        *left_index = temp;
        temp--;
    }

    // Ajustando o índice direito
    temp = mid;
    while(temp < n && cells[temp] - user <= distance) {
        *right_index = temp;
        temp++;
    }

    return (*right_index - *left_index) + 1;
}
#include <stdio.h>

int main() {
    int N, D, U;
    scanf("%d %d %d", &N, &D, &U);
    
    int cells[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &cells[i]);
    }

    int left_index, right_index;
    int count = get_range(N, cells, D, U, &left_index, &right_index);

    if(count == 0 || left_index == -1 || right_index == -1) {
        printf("USUARIO DESCONECTADO\n");
    } else {
        for(int i = left_index; i <= right_index; i++) {
            printf("%d ", cells[i]);
        }
        printf("\n");
    }

    return 0;
}
