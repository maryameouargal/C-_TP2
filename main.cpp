#include <iostream>
#include "Book.h"
// FOR EX 2 
#include "Author.h" 
int main() {
    //  Livre 1 : constructeur par défaut + setters
    Book b1;
    b1.setTitle("Twisted Love");                 
    b1.setIsbn("978-1-234");
    b1.setRating1(9.5);   
    b1.setRating2(8.0);  
    b1.setRating3(9.0);   

    std::cout << "Livre 1 : " << b1.getTitle() << std::endl;
    std::cout << "Note moyenne : " << b1.calculerNoteMoyenne() << std::endl;

    //Test de validation
    std::cout << "\nTest de validation :" << std::endl;
    b1.setRating1(15.0);   // Doit échouer (max = 10)
    std::cout << "Rating1 après tentative : " << b1.getRating1() << std::endl;

    // Livre 2 : constructeur paramétré 
    Book b2("Twisted Games", "978-9-234", 10.0, 9.5, 10.0);
    std::cout << "\nLivre 2 : " << b2.getTitle() << std::endl;
    std::cout << "Note moyenne : " << b2.calculerNoteMoyenne() << std::endl;

    //  Livre 3 : Rina Kent 
    Book b3("Twisted Hate", "978-5-234", 9.0, 9.8, 9.2);
    std::cout << "\nLivre 3 : " << b3.getTitle() << std::endl;
    std::cout << "Note moyenne : " << b3.calculerNoteMoyenne() << std::endl;

  // EXERCICE 2 : Association Book ↔ Author (1-N)
    

    std::cout << "\n EXERCICE 2 \n" << std::endl;

    //  Création de l'auteur 
    Author* rinaKent = new Author("Rina Kent", "UK");

    //Création des livres (avec new, pour l'association) 
    Book* bk1 = new Book("Twisted Love",  "978-1-234", 9.5, 8.0, 9.0);
    Book* bk2 = new Book("Twisted Games", "978-9-234", 10.0, 9.5, 10.0);
    Book* bk3 = new Book("Twisted Hate",  "978-5-234", 9.0, 9.8, 9.2);

    //  Ajout des livres à l'auteur (association 1-N) 
    rinaKent->ajouterLivre(bk1);
    rinaKent->ajouterLivre(bk2);
    rinaKent->ajouterLivre(bk3);

    // Affichage 
    rinaKent->afficherInfo();
    rinaKent->afficherTous();
    std::cout << "Nombre de livres : " << rinaKent->getNombreLivres() << "\n";

    // Vérification réciproque 
    std::cout << "\nVerification reciproque :\n";
    std::cout << "Le livre \"" << bk1->getTitle()
              << "\" a pour auteur : "
              << bk1->getAuthor()->getName() << "\n";

    // Retrait d'un livre 
    rinaKent->retirerLivre(bk2);
    std::cout << "\nApres retrait de \"Twisted Games\" :\n";
    rinaKent->afficherTous();

    //  Nettoyage 
    delete bk1;
    delete bk2;
    delete bk3;
    delete rinaKent;

    return 0;
}
