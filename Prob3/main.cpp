#include <bits/stdc++.h>
#include "global.h"

using namespace std;

int main() {
    Movie* ep5 = new Movie();
    ep5->set_name("star wars, ep 13");
    ep5->set_score(8.7);
    ep5->set_year(1980);
    ep5->set_length(124);

    Movie* ep4 = new Movie();
    ep4->set_name("star wars, ep 5");
    ep4->set_score(8.6);
    ep4->set_year(1977);
    ep4->set_length(121);

    Movie* ep6 = new Movie();
    ep6->set_name("star wars, ep 8");
    ep6->set_score(8.3);
    ep6->set_year(1983);
    ep6->set_length(131);

    printf(
          R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
    movie_compare_name(*ep4, *ep5),
    movie_compare_year(*ep4, *ep5),
    movie_compare_score(*ep4, *ep5),
    movie_compare_length(*ep4, *ep5),
    movie_compare_passed_years(*ep4, *ep5));

    MovieSeries series;
    series.init();
    series.addMovie(ep4);
    series.addMovie(ep5);
    series.addMovie(ep6);

    printf("\nInainte de sortare:\n");
    series.print();

    series.sortByRelease();

    printf("\nDupa sortare:\n");
    series.print();

    return 0;
}