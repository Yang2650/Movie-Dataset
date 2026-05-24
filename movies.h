// Jingyang Liu
// 2026.5.23

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void construct_map(map<string, double>& MovieMap, string MovieName, double MovieRating);

class Movie {
public:
    string name;
    double rating;
    Movie(string n, double r) : name(n), rating(r) {}
};

void store_prefix(vector<Movie>& m, map<string, double>& MovieMap, string prefix);

bool compare(Movie a, Movie b);

void order_m(vector<Movie>& m);