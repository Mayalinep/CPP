# 🧟 Exercice Principal : Zombies (Module 01)

## 📋 Informations Générales
- **Objectif** : Comprendre la différence entre allocation stack et heap
- **Durée** : 45 minutes
- **Niveau** : Intermédiaire
- **Fichiers** : `Zombie.hpp`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`, `Makefile`

---

## 🎯 Consignes Principales

### 1. Créer une classe Zombie
La classe doit contenir :
- **Un attribut privé** `name` de type `std::string`
- **Une méthode publique** `void announce(void)` qui affiche :
  ```
  <name>: BraiiiiiiinnnzzzZ...
  ```
- **Un destructeur** qui affiche un message avec le nom du zombie

### 2. Implémenter deux fonctions globales

#### Fonction `newZombie`
```cpp
Zombie* newZombie(std::string name);
```
- Crée un zombie sur le **heap**
- Lui donne un nom
- **Retourne** le zombie pour utilisation externe

#### Fonction `randomChump`
```cpp
void randomChump(std::string name);
```
- Crée un zombie sur le **stack**
- Lui donne un nom
- Le fait s'annoncer directement

### 3. Tester dans le main
- Utiliser les deux fonctions
- Observer les différences de comportement
- Comprendre quand utiliser chaque méthode

---

## 💡 Exemple de Sortie Attendue

```
=== Test newZombie ===
Alice: BraiiiiiiinnnzzzZ...
Alice détruite
=== Test randomChump ===
Bob: BraiiiiiiinnnzzzZ...
Bob détruit
```

---

## 🎯 Objectifs Pédagogiques

À la fin de cet exercice, tu sauras :
- ✅ Différencier allocation stack et heap
- ✅ Comprendre quand utiliser `new` et `delete`
- ✅ Gérer la durée de vie des objets
- ✅ Utiliser les pointeurs avec des objets
- ✅ Comprendre les fuites mémoire

---

## 🔧 Structure des Fichiers

### Zombie.hpp
```cpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;
    
public:
    Zombie(std::string zombieName);
    ~Zombie();
    void announce(void);
};

// Déclarations des fonctions globales
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
```

### Zombie.cpp
```cpp
#include "Zombie.hpp"

// Implémente constructeur, destructeur et announce
```

### newZombie.cpp
```cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    // Crée un zombie sur le heap et le retourne
}
```

### randomChump.cpp
```cpp
#include "Zombie.hpp"

void randomChump(std::string name) {
    // Crée un zombie sur le stack et le fait s'annoncer
}
```

### main.cpp
```cpp
#include "Zombie.hpp"

int main() {
    // Teste les deux fonctions
    return 0;
}
```

---

## 🆘 Aide si tu Bloques

### Constructeur Zombie
```cpp
Zombie::Zombie(std::string zombieName) {
    name = zombieName;
    std::cout << name << " créé" << std::endl;
}
```

### Destructeur Zombie
```cpp
Zombie::~Zombie() {
    std::cout << name << " détruit" << std::endl;
}
```

### Méthode announce
```cpp
void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

### Fonction newZombie
```cpp
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);  // Heap
    return zombie;
}
```

### Fonction randomChump
```cpp
void randomChump(std::string name) {
    Zombie zombie(name);  // Stack
    zombie.announce();
}  // Destructeur appelé automatiquement ici
```

### Main exemple
```cpp
int main() {
    // Test newZombie (heap)
    Zombie* heapZombie = newZombie("Alice");
    heapZombie->announce();
    delete heapZombie;  // Important !
    
    // Test randomChump (stack)
    randomChump("Bob");
    
    return 0;
}
```

---

## 🤔 Réflexion Importante

### Quand utiliser newZombie (heap) ?
- Quand l'objet doit **survivre** à la fonction
- Quand on veut **contrôler** la durée de vie
- Quand on a besoin de **beaucoup d'objets**

### Quand utiliser randomChump (stack) ?
- Quand l'objet est **temporaire**
- Quand on veut une **destruction automatique**
- Quand c'est **plus simple** et **plus sûr**

### Dangers à éviter
- **Fuite mémoire** : Oublier `delete` après `new`
- **Double delete** : Appeler `delete` deux fois
- **Dangling pointer** : Utiliser un pointeur après `delete`

---

## 🎯 Questions de Réflexion

1. **Pourquoi** `newZombie` retourne-t-il un pointeur ?
2. **Quand** le destructeur de `randomChump` s'exécute-t-il ?
3. **Que se passe-t-il** si on oublie `delete` ?
4. **Pourquoi** ne pas toujours utiliser le heap ?

---

## 🚀 Pour Compiler et Tester

### Makefile
```makefile
NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Commandes
```bash
# Compiler
make

# Exécuter
./zombie

# Nettoyer
make clean
```

---

## 🎯 Points Clés à Retenir

1. **Stack** : Allocation automatique, destruction automatique
2. **Heap** : Allocation avec `new`, destruction avec `delete`
3. **Pointeurs** : Nécessaires pour retourner des objets heap
4. **Gestion mémoire** : Toujours `delete` ce qu'on `new`
5. **Choix** : Stack pour temporaire, heap pour persistant

---

*Cet exercice est la base de la gestion mémoire en C++ !* 