#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 10; // Dimensione della tabella hash
    struct Entry {
        char key[50]; // Array di caratteri per la chiave
        T value;
        bool isOccupied = false; // Indica se lo slot è occupato
    };

    Entry table[TABLE_SIZE];

    // Funzione hash
    int hashFunction(const char* key) const {
        int hash = 0;
        for (int i = 0; key[i] != '\0'; ++i) {
            hash += static_cast<int>(key[i]);
        }
        return hash % TABLE_SIZE;
    }

public:
    // Metodo per aggiungere una coppia chiave-valore
    void inserisci(const char* key, const T& value) {
        int index = hashFunction(key);

        // Linear probing per gestire le collisioni
        while (table[index].isOccupied) {
            index = (index + 1) % TABLE_SIZE; // Passa al prossimo indice
        }

        // Copia della chiave
        for (int i = 0; key[i] != '\0'; ++i) {
            table[index].key[i] = key[i];
        }
        table[index].value = value;
        table[index].isOccupied = true;

        std::cout << "Inserted (" << key << " => " << value << ") at index " << index << "\n";
    }

    // Metodo per ottenere il valore associato a una chiave
    T recupera(const char* key) const {
        int index = hashFunction(key);

        // Linear probing per cercare la chiave
        while (table[index].isOccupied) {
            if (compareKeys(table[index].key, key)) {
                return table[index].value;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        // Se la chiave non viene trovata, restituisce un valore predefinito di tipo T
        return T(); // Valore di default per il tipo T
    }

    // Metodo per rimuovere una coppia chiave-valore
    void cancella(const char* key) {
        int index = hashFunction(key);

        // Linear probing per cercare la chiave da cancellare
        while (table[index].isOccupied) {
            if (compareKeys(table[index].key, key)) {
                table[index].isOccupied = false;
                std::cout << "Cancellato: " << key << " at index " << index << "\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        std::cout << "Chiave non trovata: " << key << "\n";
    }

    // Metodo per verificare se una chiave è presente
    bool appartiene(const char* key) const {
        int index = hashFunction(key);

        // Linear probing per cercare la chiave
        while (table[index].isOccupied) {
            if (compareKeys(table[index].key, key)) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return false;
    }

    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }

private:
    // Funzione per confrontare due chiavi
    bool compareKeys(const char* key1, const char* key2) const {
        int i = 0;
        while (key1[i] != '\0' && key2[i] != '\0') {
            if (key1[i] != key2[i]) {
                return false;
            }
            ++i;
        }
        return key1[i] == key2[i]; // Entrambe le stringhe devono essere uguali
    }
};

