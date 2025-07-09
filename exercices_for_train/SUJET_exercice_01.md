# 🏋️ Exercice 1 : Première Classe Simple

## 📋 Informations Générales
- **Objectif** : Créer ta première classe avec constructeur et destructeur
- **Durée** : 15 minutes
- **Niveau** : Débutant
- **Fichier** : `exercice_01_classe_simple.cpp`

---

## 🎯 Consignes

### 1. Créer une classe "Animal"
La classe doit contenir :
- **Un attribut privé** `name` de type `std::string`
- **Un constructeur** qui prend un nom en paramètre
- **Un destructeur** qui affiche un message de destruction
- **Une méthode publique** `speak()` qui affiche le nom + un son

### 2. Implémenter le main
Dans la fonction main :
- Créer un animal sur le stack
- Appeler sa méthode `speak()`
- Observer quand le destructeur s'exécute

---

## 💡 Exemple de Sortie Attendue

```
Animal Fluffy créé!
Fluffy dit: Wouaf!
Animal Fluffy détruit!
```

---

## 🎯 Objectifs Pédagogiques

À la fin de cet exercice, tu sauras :
- ✅ Comprendre la structure d'une classe
- ✅ Voir le cycle de vie d'un objet (constructeur → utilisation → destructeur)
- ✅ Maîtriser les concepts public/private
- ✅ Utiliser la syntaxe `NomClasse::méthode()` pour l'implémentation

---

## 🔧 Structure Recommandée

```cpp
#include <iostream>
#include <string>

class Animal {
private:
    std::string name;
    
public:
    Animal(std::string animalName);  // Constructeur
    ~Animal();                       // Destructeur
    void speak();                    // Méthode
};

// Implémentations
Animal::Animal(std::string animalName) {
    // Ton code ici
}

Animal::~Animal() {
    // Ton code ici
}

void Animal::speak() {
    // Ton code ici
}

int main() {
    // Ton code ici
    return 0;
}
```

---

## 🆘 Aide si tu Bloques

### Constructeur
```cpp
Animal::Animal(std::string animalName) {
    name = animalName;
    std::cout << "Animal " << name << " créé!" << std::endl;
}
```

### Destructeur
```cpp
Animal::~Animal() {
    std::cout << "Animal " << name << " détruit!" << std::endl;
}
```

### Méthode speak
```cpp
void Animal::speak() {
    std::cout << name << " dit: Wouaf!" << std::endl;
}
```

### Main
```cpp
int main() {
    Animal animal("Fluffy");
    animal.speak();
    return 0;
}
```

---

## 🚀 Pour Tester

```bash
# Compiler
g++ -o test exercice_01_classe_simple.cpp

# Exécuter
./test
```

---

## 🎯 Points Clés à Retenir

1. **Séparation** : Déclaration dans la classe, implémentation après
2. **Accès** : Dans les méthodes, accès direct aux attributs privés
3. **Syntaxe** : `NomClasse::méthode()` pour l'implémentation
4. **Cycle de vie** : Constructeur → utilisation → destructeur automatique

---

*Quand tu as terminé, passe à l'exercice 2 !* 