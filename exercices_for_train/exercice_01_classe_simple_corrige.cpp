 /*
🏋️ EXERCICE 1 : Première classe simple - VERSION CORRIGÉE
Analyse de ton code avec corrections et explications
*/

#include <iostream>
#include <string>

// ✅ CORRECTION DE TA CLASSE Animal
class Animal {
private:
    std::string name;

public:
    // ✅ CORRECTION : Déclaration du constructeur (pas d'implémentation ici)
    Animal(std::string animalName);
    
    // ✅ CORRECTION : Déclaration de la méthode
    void speak();
    
    // ✅ CORRECTION : Déclaration du destructeur
    ~Animal();
};

// ✅ CORRECTION : Implémentation du constructeur
Animal::Animal(std::string animalName) {
    // ❌ TON ERREUR : "this->name" était incomplet
    // ✅ CORRECTION : Assigner la valeur
    name = animalName;  // ou this->name = animalName;
    
    // ❌ TON ERREUR : "animal.name" n'existe pas ici
    // ✅ CORRECTION : Utiliser directement "name"
    std::cout << "Animal " << name << " créé!" << std::endl;
}

// ✅ CORRECTION : Implémentation de la méthode speak
void Animal::speak() {
    // ❌ TON ERREUR : "animal.name" n'existe pas
    // ✅ CORRECTION : Utiliser directement "name"
    std::cout << name << " dit: Wouaf!" << std::endl;
}

// ✅ CORRECTION : Implémentation du destructeur
Animal::~Animal() {
    // ❌ TON ERREUR : "std:cout" (manque un :)
    // ❌ TON ERREUR : "animal.name" n'existe pas
    // ✅ CORRECTION : 
    std::cout << "Animal " << name << " détruit!" << std::endl;
}

// ✅ TON MAIN ÉTAIT PARFAIT !
int main() {
    Animal animal("Fluffy");
    animal.speak();
    return 0;
}

/*
📝 ANALYSE DE TES ERREURS :

🔴 ERREUR 1 : Confusion entre déclaration et implémentation
- Dans la classe, tu mets SEULEMENT les déclarations
- L'implémentation se fait APRÈS avec ::

🔴 ERREUR 2 : "animal.name" au lieu de "name"
- Dans les méthodes de la classe, tu accèdes directement à "name"
- Pas besoin de "animal.name"

🔴 ERREUR 3 : Syntaxe du destructeur
- Tu avais écrit "~Animal()" au lieu de "Animal::~Animal()"
- Et "std:cout" au lieu de "std::cout"

🔴 ERREUR 4 : Constructeur incomplet
- "this->name" était incomplet, il fallait "this->name = animalName"

✅ CE QUI ÉTAIT BIEN :
- Structure générale de la classe
- Idée du private/public
- Main parfaitement écrit
- Logique générale correcte

🎯 SORTIE ATTENDUE :
Animal Fluffy créé!
Fluffy dit: Wouaf!
Animal Fluffy détruit!
*/