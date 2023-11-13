#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char gender; // 'M', 'F', or 'N'
} Person;

// Function prototypes
Person createPerson(const char *name, int age, char gender);
void addPerson(Person **array, int *size, Person newPerson);
int arePersonsEqual(Person person1, Person person2);
void removePerson(Person **array, int *size, Person target);
void displayPersons(Person *array, int size);
void freeMemory(Person *array, int size);

int main() {
    Person *peopleArray = NULL;
    int arraySize = 0;
    char action;

    while (scanf(" %c", &action) && action != 'p') {
        if (action == 'i') {
            char nameBuffer[1024];
            int age;
            char gender;

            scanf(" %[^\n]s", nameBuffer);
            scanf("%d %c", &age, &gender);

            Person newPerson = createPerson(nameBuffer, age, gender);
            addPerson(&peopleArray, &arraySize, newPerson);
        } else if (action == 'd') {
            char nameBuffer[1024];
            int age;
            char gender;

            scanf(" %[^\n]s", nameBuffer);
            scanf("%d %c", &age, &gender);

            Person targetPerson = createPerson(nameBuffer, age, gender);
            removePerson(&peopleArray, &arraySize, targetPerson);
            free(targetPerson.name); // Free memory allocated for the name
        }
    }

    displayPersons(peopleArray, arraySize);
    freeMemory(peopleArray, arraySize);

    return 0;
}

Person createPerson(const char *name, int age, char gender) {
    Person newPerson;
    newPerson.name = strdup(name); // Allocate and copy the name
    newPerson.age = age;
    newPerson.gender = gender;
    return newPerson;
}

void addPerson(Person **array, int *size, Person newPerson) {
    *array = realloc(*array, (*size + 1) * sizeof(Person));
    (*array)[*size] = newPerson;
    (*size)++;
}

int arePersonsEqual(Person person1, Person person2) {
    return strcmp(person1.name, person2.name) == 0 && person1.age == person2.age && person1.gender == person2.gender;
}

void removePerson(Person **array, int *size, Person target) {
    for (int i = 0; i < *size; i++) {
        if (arePersonsEqual((*array)[i], target)) {
            free((*array)[i].name); // Free memory of the name
            for (int j = i; j < *size - 1; j++) {
                (*array)[j] = (*array)[j + 1];
            }
            *array = realloc(*array, (*size - 1) * sizeof(Person));
            (*size)--;
            break;
        }
    }
}

void displayPersons(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s,%d,%c\n", array[i].name, array[i].age, array[i].gender);
    }
}

void freeMemory(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i].name);
    }
    free(array);
}
