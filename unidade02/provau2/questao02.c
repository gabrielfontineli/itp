#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char acronym[4]; 
    long long population; 
    double idh; 
} Country;

typedef enum {
    POPULATION,
    IDH
} DataType;

void addCountry(Country **countries, int *size, Country newCountry);
double calculateAverage(Country *countries, int size, DataType type);

int main() {
    int size = 0;
    Country *countries = NULL;

    while (1) {
        Country newCountry;
        if (scanf("%s", newCountry.acronym) == 1) {
            if (strcmp(newCountry.acronym, "---") == 0) break;
            scanf("%lld %lf", &newCountry.population, &newCountry.idh);
            addCountry(&countries, &size, newCountry);
        }
    }

    double avgIDH = calculateAverage(countries, size, IDH);
    double avgPopulation = calculateAverage(countries, size, POPULATION);

    for (int i = 0; i < size; i++) {
        if (countries[i].idh < avgIDH && countries[i].population > avgPopulation) {
            printf("%s\n", countries[i].acronym);
        }
    }

    free(countries);
    return 0;
}

void addCountry(Country **countries, int *size, Country newCountry) {
    *countries = realloc(*countries, (*size + 1) * sizeof(Country));
    if (*countries == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    (*countries)[*size] = newCountry;
    (*size)++;
}

double calculateAverage(Country *countries, int size, DataType type) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (type == POPULATION) ? countries[i].population : countries[i].idh;
    }
    return sum / size;
}
