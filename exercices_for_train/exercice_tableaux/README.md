# 🎯 Guide de l'Exercice - Tableaux d'Objets

## 🎯 **Objectif**
Cet exercice te permet de t'entraîner sur les concepts de l'ex01 avec un exemple différent mais similaire.

---

## 📋 **Étapes à Suivre**

### **Étape 1 : Créer Student.hpp**
```cpp
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student {
    // À toi de compléter !
};

// Déclaration de la fonction globale
Student* createClass(int size, std::string defaultName);

#endif
```

### **Étape 2 : Implémenter Student.cpp**
- Implémente tous les constructeurs
- Implémente toutes les méthodes
- N'oublie pas les messages du destructeur

### **Étape 3 : Créer main.cpp**
- Teste la création d'une classe de 3 étudiants
- Modifie les noms comme demandé
- Fais les présentations
- Libère la mémoire

### **Étape 4 : Créer le Makefile**
- Compile `Student.cpp` et `main.cpp`
- Nom de l'exécutable : `students`

---

## 🎯 **Concepts Clés à Réviser**

1. **Constructeur par défaut** : Pourquoi nécessaire ?
2. **new[]** : Comment créer un tableau d'objets ?
3. **delete[]** : Comment libérer un tableau ?
4. **Initialisation** : Création puis modification

---

## 🚀 **Commandes Utiles**

```bash
# Compiler
make

# Exécuter
./students

# Nettoyer
make clean
```

---

**Lance-toi ! Tu peux le faire ! 💪** 