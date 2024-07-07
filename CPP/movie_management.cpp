#include <bits/stdc++.h>

using namespace std;

class Movie {
    private:
    string id;
    string title;
    string genre;
    string director;
    bool isRented;

    public:
    string GetId(){
        return this->id;
    }
    string GetTitle(){
        return title;
    }

    string GetGenre(){
        return this->genre;
    }

    string GetDirector(){
        return this->director;
    }

    bool IsRented(){
        return this->isRented;
    }

    void MarkRented(){
        this->isRented = true;
    }

    void MarkReturn(){
        this->isRented = false;
    }

    Movie(string title, string genre, string director){
        this->title = title;
        this->genre = genre;
        this->director = director;
        this->isRented = false;
    }
};

class MovieStorage {
    public:
    virtual void AddMovie(Movie* movie) = 0;
    virtual Movie* GetMovie(string id) = 0;
    virtual vector<Movie*> GetAllMovies() = 0;
};

class VectorMovieStorage: public MovieStorage {
    private:
    vector<Movie*> movies;

    public:
    void AddMovie(Movie* movie){
        movies.push_back(movie);
    }

    Movie* GetMovie(string id){
        for(auto m:movies){
            if (m->GetId() == id){
                return m;
            }
        }

        return NULL;
    }

    vector<Movie*> GetAllMovies() {
        return this->movies;
    }
};

class MovieFinder {
    public:
    virtual vector<Movie*> GetByKey(vector<Movie*> movieList, string key) = 0;
};

class MovieFinderByGenre:MovieFinder {
    public:
    vector<Movie*> GetByKey(vector<Movie*> movieList, string key){
        vector<Movie*> result;
        for(auto m:movieList){
            if(m->GetGenre() == key && !m->IsRented()){
                result.push_back(m);
            }
        }

        return result;
    }
};
// extend this interface further to implement different finding mechanisms

class MovieRentalManager {
    public:
    bool CanRentMovie(string movieId, MovieStorage storage){
        return !storage.GetMovie(movieId)->IsRented();
    }

    void RentMovie(string movieId, MovieStorage storage){
        storage.GetMovie(movieId)->MarkRented();
    }

    void ReturnMovie(string movieId, MovieStorage storgae){
        storgae.GetMovie(movieId)->MarkReturn();
    }
};