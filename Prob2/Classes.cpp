#include "Classes.h"
#include <stdio.h>
#include <string.h>

void JsonValue::printIndents(std::ostream& os, int indents) const {
    int spaces = indents * 4;
    for (int i = 0; i < spaces; i++)
        os << " ";
}

void NullValue::print(std::ostream& os, int indents) const {
    os << "null";
}

NumberValue::NumberValue(int value) {
    this->value = value;
}

void NumberValue::print(std::ostream& os, int indents) const {
    os << this->value;
}

BoolValue::BoolValue(bool value) {
    this->value = value;
}

void BoolValue::print(std::ostream& os, int indents) const {
    if (this->value == 1)
        os << "true";
    else
        os << "false";
}

StringValue::StringValue(const char* string) {
    int size = 0;
    while (string[size] != '\0' && size < 255)
        size++;
    
    this->string = new char[size+1];
    memcpy(this->string, string, size);   
    this->string[size] = '\0';
}

StringValue::~StringValue() {
    delete[] this->string;
}

void StringValue::print(std::ostream& os, int indents) const {
    os << "\"" << this->string << "\"";
}

ArrayValue::ArrayValue() {
    valueCount = 0;
    capacity = 4;

    this->values = new JsonValue*[capacity];
    for (int i = 0; i < capacity; i++)
        values[i] = nullptr;
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < valueCount; i++)
        delete values[i];
        
    delete[] values;
}

void ArrayValue::Resize() {
    capacity *= 2;
    JsonValue** tmp = new JsonValue*[capacity];

    for (int i = 0; i < valueCount; i++)
        tmp[i] = values[i];

    delete[] values;
    values = tmp;
}

void ArrayValue::add(JsonValue* value) {
    if (valueCount >= 16)
        return;

    if (valueCount >= capacity)
        Resize();

    values[valueCount++] = value;
}

void ArrayValue::print(std::ostream& os, int indents) const {
    os << "[\n";
    for (int i = 0; i < valueCount; i++) {
        printIndents(os, indents+1);
        values[i]->print(os, indents);
        if (i < valueCount - 1)
            os << ",";
        os << "\n";
    }
    printIndents(os, indents);
    os << "]";
}

ObjectValue::ObjectValue() {
    capacity = 4;
    pairCount = 0;

    pairs = new Pair[capacity];
    for (int i = 0 ; i < capacity; i++)
        pairs[i].name = nullptr, pairs[i].value = nullptr;
}

ObjectValue::~ObjectValue() {
    for (int i = 0; i < pairCount; i++) {
        delete pairs[i].name;
        delete pairs[i].value;
    }

    delete[] pairs;
}

void ObjectValue::Resize() {
    capacity = capacity * 2;
    Pair* tmp = new Pair[capacity];
    for (int i = 0; i < pairCount; i++)
        tmp[i] = pairs[i];

    delete[] pairs;
    pairs = tmp;
}

ObjectValue::operator unsigned() const {
    return pairCount;
}

void ObjectValue::add(const char* name, JsonValue* value) {
    if (pairCount >= 16)
        return;

    if (pairCount >= capacity)
        Resize();

    int len = 0;
    while (name[len] != '\0')
        len++;
    pairs[pairCount].name = new char[len+1];

    for (int i = 0; name[i] != '\0'; i++)
        pairs[pairCount].name[i] = name[i];
    pairs[pairCount].name[len] = '\0';

    pairs[pairCount].value = value;
    pairCount++;
}

void ObjectValue::print(std::ostream& os, int indents) const {
    os << "{\n";
    for (int i = 0; i < pairCount; i++) {
        printIndents(os, indents+1);
        os << "\"" << pairs[i].name << "\": ";
        pairs[i].value->print(os, indents+1);

        if (i < pairCount - 1)
            os << ",\n";
        else
            os << "\n";
    }

    printIndents(os, indents);
    os << "}";
}