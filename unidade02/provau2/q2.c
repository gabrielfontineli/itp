#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Country Data
typedef struct {
    char code[4]; // Country Code
    long long pop; // Population
    double hdi; // Human Development Index
} Country;

// Enum for specifying the type of data for average calculation
typedef enum {
    AVG_POPULATION,
    AVG_HDI
} AverageType;

// Function Declarations
void appendCountry(Country **list, int *count, Country country);
double computeAverage(const Country *list, int count, AverageType avgType);

int main() {
    Country *countryList = NULL;
    int listSize = 0;

    // Reading country data
    while (1) {
        Country inputCountry;
        if (scanf("%s", inputCountry.code) == 1) {
            if (strcmp(inputCountry.code, "---") == 0) break;
            scanf("%lld %lf", &inputCountry.pop, &inputCountry.hdi);
            appendCountry(&countryList, &listSize, inputCountry);
        }
    }

    double averageHDI = computeAverage(countryList, listSize, AVG_HDI);
    double averagePopulation = computeAverage(countryList, listSize, AVG_POPULATION);

    // Displaying countries with HDI below average and population above average
    for (int i = 0; i < listSize; i++) {
        if (countryList[i].hdi < averageHDI && countryList[i].pop > averagePopulation) {
            printf("%s\n", countryList[i].code);
        }
    }

    free(countryList);
    return 0;
}

void appendCountry(Country **list, int *count, Country country) {
    *list = realloc(*list, (*count + 1) * sizeof(Country));
    if (*list == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    (*list)[*count] = country;
    (*count)++;
}

double computeAverage(const Country *list, int count, AverageType avgType) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += (avgType == AVG_POPULATION) ? list[i].pop : list[i].hdi;
    }
    return sum / count;
}
