#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <string>
#include <vector>

class Book;   

class Author {
private:
    std::string name;
    std::string country;

    // Association 1-N
    std::vector<Book*> books;

public:
    Author(std::string n, std::string c);
    ~Author();

    std::string getName() const;
    std::string getCountry() const;

    void ajouterLivre(Book* b);
    void retirerLivre(Book* b);
    int  getNombreLivres() const;

    void afficherInfo() const;
    void afficherTous() const;
};

#endif