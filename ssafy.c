#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void command(int id, char command_list[4][32], char history[1024][32], int *idx);
int isCommand(char input[32], char command_list[4][32]);

int main(void) {
    char input[32];
    char history[1024][32];
    char command_list[4][32] = {"date", "ls", "uptime", "log"};
    int idx = 1;
    while (1) {
        printf("SSAFY > ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        int id = isCommand(input, command_list);
        if (id >= 0) {
            command(id, command_list, history, &idx);
            continue;
        }
        else if (strcmp(input, "history") == 0) {
            for (int i = 1; i < idx; i++)
                printf("%d %s\n", i, history[i]);
            continue;
        }
        else if (input[0] == '!') {
            int num = atoi(input + 1);
            strcpy(input, history[num]);
            command(isCommand(input, command_list), command_list, history, &idx);
            continue;
        }
        else if (strcmp(input, "hclear") == 0) {
            idx = 1;
            continue;
        }
        else {
            printf("ERROR\n");
            continue;
        }
    }
}