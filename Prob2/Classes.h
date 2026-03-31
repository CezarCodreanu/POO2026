#pragma once
#include <iostream>

class JsonValue {
    protected:
        void printIndents(std::ostream& os, int indents) const;
    
    public:
        virtual ~JsonValue() {};

        virtual void print(std::ostream& os, int indents = 0) const = 0;
};

class NullValue : public JsonValue {
    public:
        void print(std::ostream& os, int indents = 0) const override;  
};

class NumberValue : public JsonValue {
    private:
        int value;

    public:
        NumberValue(int value);
        void print(std::ostream& os, int indents = 0) const override;
};

class BoolValue : public JsonValue {
    private:
        bool value;
    
    public:
        BoolValue(bool value);
        void print(std::ostream& os, int indents = 0) const override;
};

class StringValue : public JsonValue {
    private:
        char* string;
    
    public: 
        StringValue(const char* string);
        ~StringValue();

        void print(std::ostream& os, int indents = 0) const override;
};

class ArrayValue : public JsonValue {
    private:
        JsonValue** values;
        int valueCount;
        int capacity;

        void Resize();

    public:
        ArrayValue();
        ~ArrayValue();

        void add(JsonValue* value);
        void print(std::ostream& os, int indents = 0) const override;
};

class ObjectValue : public JsonValue {
    private:
        struct Pair {
            char* name;
            JsonValue* value;
        };

        Pair* pairs;
        int capacity;
        int pairCount;
        void Resize();

    public:
        ObjectValue();
        ~ObjectValue();

        operator unsigned() const;

    void add(const char* name, JsonValue* value);
    void print(std::ostream& os, int indents = 0) const override;
};