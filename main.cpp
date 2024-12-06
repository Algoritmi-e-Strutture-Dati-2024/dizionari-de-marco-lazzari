#include "DizionarioEsteso.cpp"
int main() {
    DizionarioEsteso<std::string> dict;

    // Inserimento di alcune coppie chiave-valore
    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("pen", "stationery");
    dict.inserisci("cat", "animal"); // Possibile collisione con "apple"
    dict.inserisci("act", "action"); // Possibile collisione con "cat"

    // Test di recupero
    std::cout << "Value for 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Value for 'car': " << dict.recupera("car") << "\n";
    std::cout << "Value for 'pen': " << dict.recupera("pen") << "\n";
    std::cout << "Value for 'cat': " << dict.recupera("cat") << "\n";
    std::cout << "Value for 'act': " << dict.recupera("act") << "\n";  // Collisions test

    // Verifica se una chiave appartiene al dizionario
    std::cout << "Appartiene 'book'? " << (dict.appartiene("book") ? "Si" : "No") << "\n";
    std::cout << "Appartiene 'pen'? " << (dict.appartiene("pen") ? "Si" : "No") << "\n";

    // Cancellazione della chiave "car"
    dict.cancella("car");

    // Tentativo di recupero di "car" dopo la cancellazione
    std::cout << "Value for 'car' after deletion: " << dict.recupera("car") << "\n";

    // Stampa del dizionario
    dict.stampa();

    return 0;
}