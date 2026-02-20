#include <stdio.h>
#include <string.h>

int main(){

    char cuv[100][50];
    int n = 0;
    printf("sir: ");
    while(scanf("%s", cuv[n]) == 1){
        n++;

        char c = getchar(); 
        if (c == '\n') {
            break;
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            //lungime
            if(strlen(cuv[i]) < strlen(cuv[j])) {
                char aux[50];
                strcpy(aux, cuv[i]);
                strcpy(cuv[i], cuv[j]);
                strcpy(cuv[j], aux);
            }
            //egale
            else if(strlen(cuv[i]) == strlen(cuv[j])) { 
                if(strcmp(cuv[i], cuv[j]) > 0) {
                    char aux[50];
                    strcpy(aux, cuv[i]);
                    strcpy(cuv[i], cuv[j]);
                    strcpy(cuv[j], aux);
                }
            }
        }
    }
    printf("Afisare: ");
    for(int i = 0; i < n; i++)
        printf("%s\n", cuv[i]);

    


    return 0;
}