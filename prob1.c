//m-am folosit de ASCII
#include <stdio.h>

int toNumber(char s[]){
    int nr = 0, i = 0;

    while(s[i] >= '0' && s[i] <= '9'){
        nr = nr * 10 + (s[i] - '0');
        i++;
    }
    return nr;
}

int main(){
    FILE *f = fopen("ini.txt", "r");

    if(f == NULL){
        printf("nu exista fisier de citire");
        return 0;
    }

    long suma = 0;
    char linie[100];

    while(fgets(linie, 100, f)) {
        suma = suma + toNumber(linie);
    }

    printf("suma numerelor din fisier este: %ld\n", suma);

    fclose(f);

    return 0;
}
