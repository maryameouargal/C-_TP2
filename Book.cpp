#include "Book.h"
#include "Author.h"    // FOR EX 2 — nécessaire pour utiliser les méthodes d'Author

//  Constructeur par defalte
Book::Book()
    : title("Titre Inconnu"),
      isbn("000-0-000"),
      rating1(0), rating2(0), rating3(0),
      author(nullptr) {}     // FOR EX 2 — initialiser à nullptr

// Constructeur paramétré
Book::Book(std::string t, std::string i, double r1, double r2, double r3)
    : title(t), isbn(i), rating1(r1), rating2(r2), rating3(r3),
      author(nullptr) {}     // FOR EX 2

// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getIsbn()  const { return isbn; }
double Book::getRating1()    const { return rating1; }
double Book::getRating2()    const { return rating2; }
double Book::getRating3()    const { return rating3; }

// FOR EX 2
Author* Book::getAuthor() const { return author; }

// and Setters avec validation
void Book::setTitle(std::string t) {
    if (!t.empty())
        title = t;
    else
        std::cerr << "Titre invalide (vide).\n";
}

void Book::setIsbn(std::string i) {
    if (i.length() >= 10)
        isbn = i;
    else
        std::cerr << "ISBN trop court : " << i << "\n";
}

void Book::setRating1(double r) {
    if (r >= 0 && r <= 10)
        rating1 = r;
    else
        std::cerr << "Note invalide : " << r
                  << " ( il doit Etre entre 0 et 10)\n";
}

void Book::setRating2(double r) {
    if (r >= 0 && r <= 10)
        rating2 = r;
    else
        std::cerr << "Note invalide : " << r << "\n";
}

void Book::setRating3(double r) {
    if (r >= 0 && r <= 10)
        rating3 = r;
    else
        std::cerr << "Note invalide : " << r << "\n";
}

// FOR EXERCISE 2 — Association
void Book::setAuthor(Author* a) { author = a; }

//  Méthode métier
double Book::calculerNoteMoyenne() const {
    return (rating1 + rating2 + rating3) / 3.0;
}