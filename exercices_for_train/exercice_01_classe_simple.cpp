/*
🏋️ EXERCICE 1 : Première classe simple
Objectif : Créer ta première classe avec constructeur et destructeur
Durée : 15 minutes
Niveau : Débutant

📋 CONSIGNES :
1. Crée une classe "Animal" avec :
   - Un attribut privé "name" (string)
   - Un constructeur qui prend un nom en paramètre
   - Un destructeur qui affiche un message
   - Une méthode publique "speak()" qui affiche le nom + un son

2. Dans le main :
   - Crée un animal sur le stack
   - Appelle sa méthode speak()
   - Observe quand le destructeur s'exécute

💡 EXEMPLE DE SORTIE ATTENDUE :
Animal Fluffy créé!
Fluffy dit: Wouaf!
Animal Fluffy détruit!

🎯 OBJECTIF PÉDAGOGIQUE :
- Comprendre la structure d'une classe
- Voir le cycle de vie d'un objet (constructeur -> utilisation -> destructeur)
- Maîtriser les concepts public/private
*/

#include <iostream>
#include <string>

// 🔧 TON CODE ICI : Crée la classe Animal
class Animal {
    private:
        std::string name;

    public:
    
    Animal(std::string animalName)
     //method
     void speak();

     ~Animal();
};

constructeur:
Animal::Animal(std::string name){
    this->name
    std::cout << "Animal " << animal.name << "crée!" << std::endl;
}
void Animal::speak(){
    std::cout << animal.name << "dit Wouaf" << std::endl;
}

destructeur:
~Animal(){
    std:cout << "Animal " << animal.name << "détruit!" << std::endl;
}

// 🔧 TON CODE ICI : Implémente le main
int main() {
    // Crée un animal et teste sa méthode speak()
    Animal animal("Fluffy");
    
    animal.speak();
    return 0;
}

/*
🎯 AIDE SI TU BLOQUES :

Structure de classe :
class Animal {
private:
    std::string name;
    
public:
    Animal(std::string animalName);  // Constructeur
    ~Animal();                       // Destructeur
    void speak();                    // Méthode
};

Constructeur :
Animal::Animal(std::string animalName) {
    name = animalName;
    std::cout << "Animal " << name << " créé!" << std::endl;
}

Destructeur :
Animal::~Animal() {
    std::cout << "Animal " << name << " détruit!" << std::endl;
}

Méthode speak :
void Animal::speak() {
    std::cout << name << " dit: Wouaf!" << std::endl;
}
*/ 