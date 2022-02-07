//
// Created by Julius Hernandez on 2/5/22.
//


float expenses[13];
int count;
float year_expenses = 0;

// declare & init an int var
int var = 1;
// declare a pointer
int *ptr;

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

int openCsv() {

    FILE *fp = fopen("j8mil.csv", "r");

    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *tmp = _strdup(line);
        printf("Field 3 would be %s \n", getField(tmp, 3));
        free(tmp);
    }

    return 0;
}


void pointersOne() {
    int a = 1;
    char *m = "Hello";
    int *ptrToA = &a;
    int b = 2;
    int rate = 25;
    int *p_rate;
    int *ptrB = &b;

    printf("\nThe value of a = %d\n", a);
    printf("\nval of pointToA = %d\n", *ptrToA);
    printf("\nval of message = %s\n", m);

    b += 1;
    *ptrB += 2;

    // p_rate = memory address
    // *p_rate = contents of memory address
    // *p_rate AND rate will both = 25
    // p_rate AND &rate point to the address of rate
    p_rate = &b;

    printf("\n val b = %d, ptrB = %d \n", b, *ptrB);
    printf(
            "\ndirect access rate = %d, indierect access *p_rate = %d\n",
            rate, *p_rate
    );

    // ptr = mem address of var
    ptr = &var;
    printf("\n__> direct access var = %d\n", var);
    printf("\n__> indirect access var = %d\n", *ptr);
    printf("\n__> mem address of var = %p\n", &var);
    printf("\n__> mem address of var = %p\n", ptr);
}

void getInput() {
    for (count = 1; count < 13; count++) {
        printf("\nEnter expenses for month %d: ", count);
        scanf("%f", &expenses[count]);
    }

    for (count = 1; count < 13; count++) {
        printf("\nMonth %d = $%.2f\n", count, expenses[count]);
    }
}


void ptr2() {
    int h = 1;
    int *ptrH = &h;
    int array[4][3] = {
            // cost | sales_price | in_stock
            {12, 36, 500},
            {2, 12, 300},
            {5, 20, 400},
            {7, 28, 200}
    };

    *ptrH += 1;

    printf("\n_> h = %d", h);
    printf("\n_> ptrH = %p", ptrH);
    printf("\n_> *ptrH = %d", *ptrH);
}