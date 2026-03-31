#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Classes.h"

int main(int argc, char** argv) {
    char ch;
    char filePath[255];
    int file = -1;

    if (argc == 1) {
        printf("Doriti sa printati in fisier sau la consola? (f/c): ");
        scanf("%c", &ch);
        if (ch == 'f') {
            printf("Introduceti path-ul catre fisier: ");
            scanf("%254s", filePath);
        }
    }
    else if (argc == 2) {
        ch = argv[1][0];
        if (ch == 'f') {
            printf("Introduceti path-ul catre fisier: ");
            scanf("%254s", filePath);
        }
    } 
    else if (argc == 3){
        ch = argv[1][0];
        strcpy(filePath, argv[2]);
    }
    else {
        perror("Prea multe argumente\n");
        exit(1);
    }

    if (ch != 'f' && ch != 'c') {
        perror("Caracter invalid\n");
        exit(2);
    }

    if (ch == 'f') {
        file = open(filePath, O_WRONLY);
        if (file == -1) {
            perror("Fisier invalid\n");
            exit(3);
        }

        close(file);
        if (freopen(filePath, "w", stdout) == NULL) {
            perror("Eroare la redirectare cu freopen\n");
            exit(4);
        }
    }

    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    std::cout << "Top node has " << (unsigned) *object << " subnodes\n";

    object->print(std::cout);
    delete object;
    printf("\n");
}