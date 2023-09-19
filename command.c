#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void command(int id, char commands[4][32], char history[1024][32], int *idx) {
    char command_list[4][32] = {"date", "ls -al", "uptime", "sudo dmesg"};
    system(command_list[id]);
    strcpy(history[*idx], commands[id]);
    (*idx)++;
}