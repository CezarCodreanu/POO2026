class Number
{
private:
    int digits;
    int base;

public:
   Number(const char * value, int base);
   ~Number();

   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); 
   int  GetBase(); 
};