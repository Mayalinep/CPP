# 🎯 Exercice d'Entraînement - Tableaux d'Objets

## 🎯 **Objectif**
Créer une classe `Student` et manipuler un tableau d'étudiants pour bien maîtriser les concepts de l'ex01.

---

## 📋 **Énoncé**

### **Partie 1 : Classe Student**
Crée une classe `Student` avec :
- **Attribut privé** : `std::string name`
- **Constructeur par défaut** : initialise name à ""
- **Constructeur avec paramètre** : `Student(std::string name)`
- **Setter** : `void setName(std::string name)`
- **Getter** : `std::string getName()`
- **Méthode** : `void introduce()` qui affiche "Je suis [name]"
- **Destructeur** : affiche "[name] a quitté l'école"

### **Partie 2 : Fonction createClass**
Crée une fonction globale :
```cpp
Student* createClass(int size, std::string defaultName);
```

Cette fonction doit :
1. Créer un tableau de `size` étudiants
2. Donner le nom `defaultName` à tous les étudiants
3. Retourner le pointeur vers le tableau

### **Partie 3 : Main de test**
Dans le main, teste :
1. Crée une classe de 3 étudiants nommés "Étudiant"
2. Change le nom du premier en "Alice"
3. Change le nom du deuxième en "Bob"
4. Fais que tous les étudiants se présentent
5. Libère la mémoire correctement

---

## 🎯 **Résultat Attendu**
```
Je suis Alice
Je suis Bob
Je suis Étudiant
Étudiant a quitté l'école
Bob a quitté l'école
Alice a quitté l'école
```
*Note : L'ordre des destructeurs est inversé (normal en C++)*

---

## 📁 **Structure des Fichiers**
Crée dans `mes_exercices/exercice_tableaux/` :
- `Student.hpp`
- `Student.cpp`
- `main.cpp`
- `Makefile`

---

## 🎯 **Points à Vérifier**

### **Checklist Technique**
- [ ] Constructeur par défaut implémenté
- [ ] Constructeur avec paramètre implémenté
- [ ] Utilisation de `new Student[size]`
- [ ] Utilisation de `delete[]` (pas `delete`)
- [ ] Boucle for pour parcourir le tableau
- [ ] Pas de fuites mémoire

### **Checklist Compréhension**
- [ ] Je comprends pourquoi il faut un constructeur par défaut
- [ ] Je sais quand utiliser `delete[]`
- [ ] Je comprends l'initialisation en deux étapes
- [ ] Je sais accéder aux éléments du tableau

---

## 🚀 **Bonus (optionnel)**

Si tu veux aller plus loin :
1. Ajoute un attribut `int age` avec getter/setter
2. Crée une méthode `void celebrateBirthday()` qui incrémente l'âge
3. Modifie `introduce()` pour afficher aussi l'âge

---

## 💡 **Conseils**

1. **Commence par le header** : définis bien ta classe
2. **Implémente étape par étape** : constructeurs, puis méthodes
3. **Teste au fur et à mesure** : compile après chaque étape
4. **N'oublie pas les includes** : `<iostream>` et `<string>`

---

## 🎯 **Quand tu as fini**

1. **Teste que ça compile** sans erreur
2. **Vérifie le résultat** correspond à l'attendu
3. **Coche les checklists** ci-dessus
4. **Dis-moi si tu as des questions** !

---

**C'est parti ! Tu vas maîtriser ces concepts ! 💪** 