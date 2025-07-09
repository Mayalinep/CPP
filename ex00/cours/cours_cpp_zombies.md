# Cours C++ - Exercice Zombies (Module 01)

## 📚 Plan d'apprentissage

### Objectif de ce cours
Comprendre les concepts C++ nécessaires pour réussir l'exercice des zombies et développer une logique de programmation solide.

---

## 🎯 Thématique 1 : Les Classes en C++

### Qu'est-ce qu'une classe ?
Une classe est un **plan** ou un **moule** qui définit :
- **Les données** (attributs) que l'objet contient
- **Les actions** (méthodes) que l'objet peut faire

**Analogie :** Une classe est comme un plan de maison. Le plan définit les pièces (attributs) et ce qu'on peut faire dans chaque pièce (méthodes).

### Structure de base d'une classe
```cpp
class NomDeLaClasse {
private:
    // Attributs privés - seulement la classe peut y accéder
    type nomAttribut;
    
public:
    // Méthodes publiques - accessibles de l'extérieur
    void nomMethode();
    
    // Constructeur - s'exécute à la création
    NomDeLaClasse();
    
    // Destructeur - s'exécute à la destruction
    ~NomDeLaClasse();
};
```

### Public vs Private
- **Private** : Seule la classe elle-même peut accéder
- **Public** : Tout le monde peut accéder

**Pourquoi cette distinction ?**
- **Sécurité** : Protéger les données sensibles
- **Contrôle** : Forcer l'utilisation des méthodes appropriées

---

## 🎯 Thématique 2 : Gestion de la Mémoire

### Stack vs Heap - Les deux types de mémoire

#### Stack (Pile)
- **Allocation automatique**
- **Destruction automatique** à la fin de la fonction
- **Plus rapide**
- **Taille limitée**

```cpp
void fonction() {
    Zombie zombie("Bob");  // Créé sur le stack
    // zombie est automatiquement détruit à la fin de la fonction
}
```

#### Heap (Tas)
- **Allocation manuelle** avec `new`
- **Destruction manuelle** avec `delete`
- **Plus lent**
- **Taille illimitée** (selon la RAM)

```cpp
void fonction() {
    Zombie* zombie = new Zombie("Bob");  // Créé sur le heap
    // zombie doit être détruit manuellement avec delete
    delete zombie;
}
```

### Pourquoi cette distinction est importante ?
- **Stack** : Pour les objets temporaires
- **Heap** : Pour les objets qui doivent survivre à la fonction

---

## 🎯 Thématique 3 : Constructeurs et Destructeurs

### Constructeur
- **Fonction spéciale** qui s'exécute à la création
- **Même nom** que la classe
- **Initialise** les attributs

```cpp
class Zombie {
private:
    std::string name;
    
public:
    Zombie(std::string zombieName) {
        name = zombieName;
        std::cout << "Zombie " << name << " créé!" << std::endl;
    }
};
```

### Destructeur
- **Fonction spéciale** qui s'exécute à la destruction
- **Même nom** que la classe avec `~`
- **Nettoie** la mémoire

```cpp
class Zombie {
public:
    ~Zombie() {
        std::cout << "Zombie " << name << " détruit!" << std::endl;
    }
};
```

---

## 🎯 Thématique 4 : Pointeurs

### Qu'est-ce qu'un pointeur ?
Un pointeur est une **adresse mémoire** qui pointe vers une donnée.

```cpp
int nombre = 42;
int* pointeur = &nombre;  // pointeur contient l'adresse de nombre
```

### Pointeurs et objets
```cpp
Zombie* zombiePtr = new Zombie("Bob");  // Crée un zombie sur le heap
zombiePtr->announce();  // Accède à la méthode via le pointeur
delete zombiePtr;  // Détruit le zombie
```

### Pourquoi utiliser des pointeurs ?
- **Retourner** des objets créés sur le heap
- **Éviter** la copie de gros objets
- **Gérer** la durée de vie manuellement

---

## 🎯 Thématique 5 : Logique de Programmation

### Plan d'action pour résoudre un problème

#### 1. Analyser le problème
- **Que** doit faire le programme ?
- **Quels** sont les inputs/outputs ?
- **Quelles** sont les contraintes ?

#### 2. Décomposer en sous-problèmes
- **Diviser** le problème en parties plus petites
- **Identifier** les composants nécessaires

#### 3. Planifier l'architecture
- **Quelles** classes créer ?
- **Quelles** méthodes implémenter ?
- **Comment** organiser le code ?

#### 4. Implémenter étape par étape
- **Commencer** par le plus simple
- **Tester** à chaque étape
- **Itérer** et améliorer

---

## 🎯 Application à l'exercice Zombies

### Analyse du problème
1. **Créer** une classe Zombie avec un nom
2. **Implémenter** une méthode announce()
3. **Créer** deux fonctions avec des stratégies différentes
4. **Comprendre** quand utiliser stack vs heap

### Plan d'implémentation
1. **Étape 1** : Créer la classe Zombie (constructeur, destructeur, announce)
2. **Étape 2** : Implémenter randomChump (stack)
3. **Étape 3** : Implémenter newZombie (heap)
4. **Étape 4** : Créer le main pour tester
5. **Étape 5** : Créer le Makefile

### Questions clés à se poser
- **Quand** le destructeur de randomChump s'exécute-t-il ?
- **Qui** doit détruire le zombie de newZombie ?
- **Pourquoi** newZombie retourne-t-il un pointeur ?

---

## 🎯 Prochaines étapes

1. **Lire** et comprendre ce cours
2. **Poser** des questions sur les concepts flous
3. **Commencer** l'implémentation étape par étape
4. **Tester** à chaque étape

### Conseils pour réussir
- **Ne pas** se précipiter
- **Tester** chaque petite partie
- **Comprendre** avant de copier
- **Poser** des questions !

---

*Ce cours sera mis à jour au fur et à mesure de notre progression !* 