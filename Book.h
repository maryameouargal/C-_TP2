#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

// FOR EXERCISE 2
class Author;

class Book {
private:
    std::string title;
    std::string isbn;
    double rating1;
    double rating2;
    double rating3;

    // ADDED FOR EX 2 — ASSOCIATION
    Author* author;

public:
    // Constructeurs
    Book();
    Book(std::string t, std::string i, double r1, double r2, double r3);

    // Getters
    std::string getTitle() const;
    std::string getIsbn() const;
    double getRating1() const;
    double getRating2() const;
    double getRating3() const;

    // FOR EX 2
    Author* getAuthor() const;

    // Setters avec validation
    void setTitle(std::string t);
    void setIsbn(std::string i);
    void setRating1(double r);
    void setRating2(double r);
    void setRating3(double r);

    // FOR EXERCISE 2
    void setAuthor(Author* a);

    // Méthode métier
    double calculerNoteMoyenne() const;
};

#endif