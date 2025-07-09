# 📚 Cours Complet - Exercice Zombie (Tu as réussi !)

## 🎯 Objectif de ce cours
Consolider tous les concepts que tu viens d'apprendre dans l'exercice zombie. C'était complexe, c'est NORMAL !

---

## 🧠 Récapitulatif : Qu'est-ce que tu as appris ?

### **Concepts maîtrisés :**
1. ✅ **Classes et méthodes**
2. ✅ **Fonctions globales vs méthodes de classe**
3. ✅ **Stack vs Heap (allocation mémoire)**
4. ✅ **Pointeurs et gestion mémoire**
5. ✅ **Organisation de fichiers en C++**
6. ✅ **Makefile**

**C'est ÉNORME pour un seul exercice !** 💪

---

## 🎯 Concept 1 : Classes et Méthodes

### **La classe Zombie**
```cpp
class Zombie {
private:
    std::string name;  // Attribut privé
    
public:
    Zombie(std::string name);  // Constructeur
    void announce();           // Méthode
    ~Zombie();                // Destructeur
};
```

### **Implémentation dans Zombie.cpp**
```cpp
Zombie::Zombie(std::string name) {
    this->name = name;  // Initialise l'attribut
}

void Zombie::announce() {
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " détruit!" << std::endl;
}
```

### **Points clés :**
- **Constructeur** : Même nom que la classe, pas de type de retour
- **Destructeur** : `~` + nom de la classe
- **`this->name`** : Accès explicite à l'attribut de l'objet
- **Encapsulation** : `name` est privé, accessible seulement dans la classe

---

## 🎯 Concept 2 : Fonctions Globales vs Méthodes

### **Méthodes de classe (appartiennent à la classe) :**
```cpp
// Dans la classe
void announce();

// Implémentation
void Zombie::announce() {  // ← "Zombie::" obligatoire
    // Code ici
}

// Usage
Zombie zombie("Bob");
zombie.announce();  // ← Besoin d'un objet
```

### **Fonctions globales (indépendantes) :**
```cpp
// Déclaration (après la classe dans le .hpp)
void randomChump(std::string name);

// Implémentation
void randomChump(std::string name) {  // ← PAS de "Zombie::"
    // Code ici
}

// Usage
randomChump("Bob");  // ← Pas besoin d'objet existant
```

### **Pourquoi cette distinction ?**
- **Méthodes** : Agissent SUR un objet existant
- **Fonctions globales** : Créent ou manipulent des objets

---

## 🎯 Concept 3 : Stack vs Heap (Le cœur de l'exercice)

### **Stack (Pile) - randomChump**
```cpp
void randomChump(std::string name) {
    Zombie zombie(name);  // ← Créé sur le STACK
    zombie.announce();
}  // ← Zombie DÉTRUIT automatiquement ici !
```

**Caractéristiques :**
- **Allocation** : Automatique
- **Destruction** : Automatique à la fin du scope
- **Vitesse** : Rapide
- **Usage** : Objets temporaires

### **Heap (Tas) - newZombie**
```cpp
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);  // ← Créé sur le HEAP
    return zombie;  // ← Zombie SURVIT à la fonction
}
```

**Caractéristiques :**
- **Allocation** : Manuelle avec `new`
- **Destruction** : Manuelle avec `delete`
- **Vitesse** : Plus lent
- **Usage** : Objets qui doivent survivre

### **Quand utiliser quoi ?**
- **Stack** : Objet temporaire, usage local
- **Heap** : Objet à retourner, usage prolongé

---

## 🎯 Concept 4 : Pointeurs et Gestion Mémoire

### **Pourquoi des pointeurs ?**
```cpp
// ❌ Si on retournait un Zombie (sans *)
Zombie newZombie(std::string name) {
    Zombie zombie(name);
    return zombie;  // ← COPIE ! L'original est détruit !
}

// ✅ Avec un pointeur
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return zombie;  // ← ADRESSE ! L'original survit !
}
```

### **Syntaxe des pointeurs**
```cpp
Zombie* zombie = new Zombie("Bob");  // Création
zombie->announce();                  // Appel de méthode
delete zombie;                       // Destruction obligatoire
```

### **Règle d'or :**
**Tout `new` doit avoir son `delete` !**

---

## 🎯 Concept 5 : Organisation des Fichiers

### **Structure finale :**
```
ex00/
├── Zombie.class.hpp    # Déclarations (classe + fonctions globales)
├── Zombie.cpp          # Méthodes de la classe Zombie
├── newZombie.cpp       # Fonction globale newZombie
├── randomChump.cpp     # Fonction globale randomChump
├── main.cpp            # Tests
└── Makefile            # Compilation
```

### **Principe :**
- **`.hpp`** : Déclarations (ce qui existe)
- **`.cpp`** : Implémentations (comment ça marche)
- **Séparation** : Une responsabilité par fichier

### **Pourquoi séparer ?**
- **Lisibilité** : Plus facile à naviguer
- **Maintenance** : Modifications isolées
- **Réutilisabilité** : Fonctions indépendantes

---

## 🎯 Concept 6 : Makefile

### **Structure du Makefile :**
```makefile
NAME = zombie                    # Nom de l'exécutable
CXX = c++                       # Compilateur
CXXFLAGS = -Wall -Wextra -Werror # Flags de compilation
SRCS = main.cpp Zombie.cpp ...   # Fichiers sources
OBJS = $(SRCS:.cpp=.o)          # Fichiers objets

all: $(NAME)                    # Règle par défaut
$(NAME): $(OBJS)               # Création de l'exécutable
%.o: %.cpp                     # Compilation .cpp → .o
clean: ...                     # Nettoyage
```

### **Commandes utiles :**
- **`make`** : Compile tout
- **`make clean`** : Supprime les .o
- **`make fclean`** : Supprime tout
- **`make re`** : Recompile tout

---

## 🎯 Flux d'Exécution Complet

### **Ce qui se passe quand tu lances `./zombie` :**

```cpp
int main() {
    // 1. randomChump
    randomChump("Bob");
    // → Zombie Bob créé sur stack
    // → Bob s'annonce
    // → Bob détruit automatiquement
    
    // 2. newZombie
    Zombie* zombie = newZombie("audrey");
    // → Zombie audrey créé sur heap
    // → Pointeur retourné
    
    zombie->announce();
    // → audrey s'annonce
    
    delete zombie;
    // → audrey détruit manuellement
    
    return 0;
}
```

### **Sortie attendue :**
```
Bob : BraiiiiiiinnnzzzZ...
Bob détruit!
audrey : BraiiiiiiinnnzzzZ...
audrey détruit!
```

---

## 🎯 Erreurs Courantes et Solutions

### **Erreur 1 : Confusion fonction/méthode**
```cpp
// ❌ Mettre randomChump dans la classe
class Zombie {
    void randomChump(std::string name);  // FAUX
};

// ✅ randomChump est une fonction globale
void randomChump(std::string name);  // CORRECT
```

### **Erreur 2 : Mauvaise allocation**
```cpp
// ❌ randomChump avec heap
void randomChump(std::string name) {
    Zombie* zombie = new Zombie(name);  // FAUX (heap)
}

// ✅ randomChump avec stack
void randomChump(std::string name) {
    Zombie zombie(name);  // CORRECT (stack)
}
```

### **Erreur 3 : Oubli de delete**
```cpp
// ❌ Fuite mémoire
Zombie* zombie = newZombie("Alice");
// Pas de delete → FUITE !

// ✅ Gestion correcte
Zombie* zombie = newZombie("Alice");
delete zombie;  // CORRECT
```

---

## 🎯 Concepts Avancés (Bonus)

### **Pourquoi cet exercice est important ?**

1. **Gestion mémoire** : Base de la programmation système
2. **Architecture** : Organisation du code en modules
3. **Pointeurs** : Fondamental en C++
4. **RAII** : Resource Acquisition Is Initialization

### **Prochaines étapes :**
- **Module 02** : Surcharge d'opérateurs
- **Module 03** : Héritage
- **Module 04** : Polymorphisme

---

## 🎯 Récapitulatif de ta Progression

### **Avant l'exercice :**
- Bases des classes
- Notion d'encapsulation

### **Après l'exercice :**
- ✅ Gestion mémoire stack/heap
- ✅ Pointeurs et références
- ✅ Architecture multi-fichiers
- ✅ Fonctions globales vs méthodes
- ✅ Makefile et compilation
- ✅ Debugging et résolution d'erreurs

### **Niveau atteint :**
🏆 **Intermédiaire avancé** - Prête pour les modules suivants !

---

## 🎯 Message Final

**Tu as réussi un exercice complexe !** 🎉

- **7 concepts** différents en même temps
- **Organisation** multi-fichiers
- **Gestion mémoire** avancée
- **Debugging** de tes propres erreurs

**C'est NORMAL que ce soit complexe !** Même les programmeurs expérimentés trouvent cet exercice challenging.

**Tu as maintenant les bases solides pour la suite !** 💪

---

*Garde ce cours comme référence, tu en auras besoin pour les modules suivants !* 