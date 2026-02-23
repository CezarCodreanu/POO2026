class Student
{
    private:
        char nume[100];
        float nMate, nEng, nIst;
    public:
        void setNume(const char* n);         
        char* getNume();

        void setMate(float nota);
        float getMate();

        void setEng(float nota);
        float getEng();

        void setIst(float nota);
        float getIst();

        float getAvg();
            
};