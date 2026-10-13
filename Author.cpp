#include "Author.h"
#include "Book.h"
#include <algorithm>

Author::Author(std::string n, std::string c)
    : name(n), country(c) {}

Author::~Author() {
    for (Book* book : books) {
        if (book != nullptr) {
            book->setAuthor(nullptr);
        }
    }
    books.clear();
}

std::string Author::getName() const    { return name; }
std::string Author::getCountry() const { return country; }

void Author::ajouterLivre(Book* b) {
    if (b != nullptr) {
        books.push_back(b);
        b->setAuthor(this);
    }
}

void Author::retirerLivre(Book* b) {
    auto it = std::find(books.begin(), books.end(), b);
    if (it != books.end()) {
        (*it)->setAuthor(nullptr);
        books.erase(it);
    }
}

int Author::getNombreLivres() const {
    return static_cast<int>(books.size());
}

void Author::afficherInfo() const {
    std::cout << "Auteur : " << name << " (" << country << ")\n";
    std::cout << "  Nombre de livres : " << books.size() << "\n";
}

void Author::afficherTous() const {
    std::cout << "Livres de " << name << " :\n";
    for (const auto* b : books) {
        std::cout << "  - " << b->getTitle()
                  << " (moyenne : " << b->calculerNoteMoyenne() << ")\n";
    }
}