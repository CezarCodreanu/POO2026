class Movie {
    private:
        char nume[100];
        int year, min;
        double score;

    public:
        void set_name(const char* n);
        char* getName();

        void set_year(const int y);
        int* getYear();

        void set_score(const double* s);
        double* getScore();

        void set_length(const int* m);
        int* getLenght();


};