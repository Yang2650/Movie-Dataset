#include "movies.h"
using namespace std;

// for Part 1
void construct_map(map<string, double>& MovieMap, string MovieName, double MovieRating) {
    MovieMap[MovieName] = MovieRating;
}

// for Part 2
void store_prefix(vector<Movie>& m, map<string, double>& MovieMap, string prefix) {
    auto it = MovieMap.lower_bound(prefix);
    while (it != MovieMap.end() && it->first.find(prefix) == 0) {
        m.push_back(Movie(it->first, it->second));
        ++it;
    }
}

bool compare(const Movie a, const Movie b) {
    if (a.rating == b.rating) {
        return a.name < b.name;
    }
    if (a.rating > b.rating) return true;
    else return false;
}

void order_m(vector<Movie>& m) {
    sort(m.begin(), m.end(), compare);
}