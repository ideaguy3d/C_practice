#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *getField(char *line, int num) {
    const char *tok;
    char *next_token1 = NULL;
    char *next_token2 = NULL;

    for (tok = strtok_s(line, ";", &next_token1); tok && *tok;
         tok = strtok_s(NULL, ";\n", &next_token2)) {
        if (!--num) {
            return tok;
        }
    }

    return NULL;
}


int main() {

    //printf("\n\n _Hello, World! ^_^/ \n\n");

    FILE *fp = fopen("j8mil.csv", "r");

    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *tmp = _strdup(line);
        printf("Field 3 would be %s \n", getField(tmp, 3));
        free(tmp);
    }

    return 0;

}





//