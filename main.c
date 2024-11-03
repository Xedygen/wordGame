#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LEN 20
#define MAX_WORDS (26 * LEN)

bool isOkay(char *string, char lastChar);
void getWord();
int getData();
void writeWord();
bool containsNonAlphanumeric();

char word[LEN];
char cWord[LEN];
char data[MAX_WORDS][LEN];
int wordCount = 0;
char lastCharacterFromComputerWord;

int main() {
    srand(time(NULL));

    int result = getData();
    if (result != 0) {
        printf("There's something wrong with the Python file.\n");
        return 0;
    }

    printf("Welcome.\nHow this game works?\n\tIn this game, the player starts by writing a word.\nAfter that, the player writes a word that starts with the last character of the computer's last word.\nGame keeps going in turns until one of the players loses.\n\n\tWrite '0' (zero) to exit.\n\n\tLet's play.\n");

    while (true) {
        getWord();
        printf("Your word count is %d. Let's continue playing.\n", wordCount);
    }

    return 0;
}

void getWord() {
    memset(word, 0, sizeof(word));

    printf("Your word: ");
    scanf("%19s", word);

    if (strcmp(word, "0") == 0) {
        printf("Exiting the game. Thank you for playing!\n");
        exit(0);
    } else if (containsNonAlphanumeric(word)) {
        printf("%s contains non-alphabetic characters. Please enter a valid word.\n", word);
        return;
    } else {
        if (wordCount > 0 && !isOkay(word, lastCharacterFromComputerWord)) {
            printf("You have lost. Your word '%s' does not start with '%c'.\n", word, lastCharacterFromComputerWord);
            exit(0);
        }

        lastCharacterFromComputerWord = word[strlen(word) - 1];
        writeWord();
        wordCount++;
    }
}

bool containsNonAlphanumeric(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isalpha(string[i])) {
            return true;
        }
    }
    return false;
}

bool isOkay(char *string, char lastChar) {
    return string[0] == lastChar;
}

void writeWord() {
    char dummy[10][LEN];
    int dummyCount = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (data[i][0] == lastCharacterFromComputerWord) {
            strcpy(dummy[dummyCount], data[i]);
            dummyCount++;
            if (dummyCount == 10) break;
        }
    }

    if (dummyCount > 0) {
        int randomIndex = rand() % dummyCount;
        strcpy(cWord, dummy[randomIndex]);
        printf("My word: %s\n", cWord);
        lastCharacterFromComputerWord = cWord[strlen(cWord) - 1];
    } else {
        printf("I can't find a word. You win!\n");
        exit(0);
    }
}

int getData() {
    int result = system("python word_generator.py");
    int count = 0;

    FILE *file = fopen("data.txt", "r");
    while (file == NULL && count < 3) {
        count++;
        file = fopen("data.txt", "r");
    }

    if (file == NULL) {
        printf("Error reading the file...\n");
        return 1;
    } else {
        int line = 0;
        char buffer[LEN + 5];
        while (fgets(buffer, LEN + 5, file) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(data[line], buffer);
            line++;
        }
        fclose(file);
        printf("Loaded %d words from data file.\n", line);
    }

    return result;
}
