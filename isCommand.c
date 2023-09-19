#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCommand(char input[32], char command_list[4][32]) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(input, command_list[i]) == 0)
            return i;
    }
    return -1;
}