# 📚 Cours C++ - Erreurs de Débutant (Tu n'es pas nulle !)

## 🎯 Objectif
Comprendre les erreurs les plus communes quand on débute en C++ et comment les éviter.

**Important :** Ces erreurs sont **NORMALES** et **FORMATRICES** ! Tous les programmeurs les ont faites !

---

## 🔴 Erreur 1 : Confusion Variables vs Méthodes

### ❌ Ce que tu as fait :
```cpp
class BankAccount {
public:
    double deposit;      // ❌ Variable
    double withdraw;     // ❌ Variable
};
```

### ✅ Ce qu'il faut faire :
```cpp
class BankAccount {
public:
    void deposit(double amount);    // ✅ Méthode
    void withdraw(double amount);   // ✅ Méthode
};
```

### 🧠 Comment différencier ?
- **Variable** : Stocke une **donnée** (un nombre, un texte)
- **Méthode** : Effectue une **action** (calculer, afficher, modifier)

### 🎯 Questions à se poser :
- "deposit" est-ce une **donnée** ou une **action** ? → Action ! Donc méthode.
- "balance" est-ce une **donnée** ou une **action** ? → Donnée ! Donc variable.

---

## 🔴 Erreur 2 : Constructeur Mal Déclaré

### ❌ Ce que tu as fait :
```cpp
class BankAccount {
public:
    void BankAccount(std::string number, double balance);  // ❌ "void"
};
```

### ✅ Ce qu'il faut faire :
```cpp
class BankAccount {
public:
    BankAccount(std::string number, double balance);  // ✅ Pas de "void"
};
```

### 🧠 Règle à retenir :
- **Constructeur** : Même nom que la classe, **JAMAIS** de type de retour
- **Méthode normale** : Nom différent, **TOUJOURS** un type de retour

### 🎯 Exemples :
```cpp
class Animal {
public:
    Animal(std::string name);     // ✅ Constructeur
    void speak();                 // ✅ Méthode
    std::string getName();        // ✅ Méthode qui retourne
    ~Animal();                    // ✅ Destructeur
};
```

---

## 🔴 Erreur 3 : Paramètres Non Utilisés

### ❌ Ce que tu as fait :
```cpp
BankAccount::BankAccount(std::string accountNumber, double balance) {
    balance = initialBalance;     // ❌ "initialBalance" n'existe pas
    accountNumber = "";           // ❌ N'utilise pas le paramètre
}
```

### ✅ Ce qu'il faut faire :
```cpp
BankAccount::BankAccount(std::string number, double initialBalance) {
    balance = initialBalance;     // ✅ Utilise le paramètre
    accountNumber = number;       // ✅ Utilise le paramètre
}
```

### 🧠 Règle à retenir :
- **Paramètres** : Ce que la fonction reçoit en entrée
- **Attributs** : Ce que la classe stocke
- **Assigner** : attribut = paramètre

### 🎯 Technique mnémotechnique :
```cpp
// Paramètre → Attribut
this->attribut = parametre;
// ou plus simple :
attribut = parametre;
```

---

## 🔴 Erreur 4 : Getters Mal Implémentés

### ❌ Ce que tu as fait :
```cpp
void BankAccount::getBalance() {
    std::cout << "Solde : " << balance << std::endl;  // ❌ Affiche au lieu de retourner
}
```

### ✅ Ce qu'il faut faire :
```cpp
double BankAccount::getBalance() {
    return balance;  // ✅ Retourne la valeur
}
```

### 🧠 Différence Getter vs Affichage :
- **Getter** : **Retourne** une valeur pour l'utiliser ailleurs
- **Affichage** : **Montre** une valeur à l'utilisateur

### 🎯 Utilisation :
```cpp
// Avec getter (flexible)
double solde = account.getBalance();
if (solde > 100) {
    std::cout << "Solde suffisant : " << solde << "€" << std::endl;
}

// Avec affichage (rigide)
account.showBalance();  // Affiche toujours pareil
```

---

## 🔴 Erreur 5 : Organisation des Fichiers

### ❌ Ce que tu as fait :
```
exercice_02/
├── exercice_02.class.hpp
└── exercice_02.cpp
```

### ✅ Ce qu'il faut faire :
```
mes_exercices/
└── exercice_02_public_private.cpp  (tout dans un fichier pour l'exercice)
```

### 🧠 Règle simple pour débuter :
- **Exercices** : Tout dans un fichier `.cpp`
- **Projets** : Séparer `.hpp` et `.cpp`

---

## 🎯 Méthode Anti-Erreurs

### 1. **Avant de coder, pose-toi ces questions :**
- Cette chose est-elle une **donnée** ou une **action** ?
- Cette fonction est-elle un **constructeur** ou une **méthode** ?
- Ai-je bien utilisé tous mes **paramètres** ?

### 2. **Checklist avant compilation :**
- [ ] Constructeur sans `void`
- [ ] Méthodes avec type de retour
- [ ] Paramètres utilisés dans le corps
- [ ] Getters qui `return`
- [ ] Variables et méthodes bien différenciées

### 3. **Méthode de debug :**
```cpp
// Ajoute des std::cout pour voir ce qui se passe
BankAccount::BankAccount(std::string number, double initialBalance) {
    std::cout << "Paramètres reçus: " << number << ", " << initialBalance << std::endl;
    accountNumber = number;
    balance = initialBalance;
    std::cout << "Attributs assignés: " << accountNumber << ", " << balance << std::endl;
}
```

---

## 🎯 Exercice de Récupération

### Corrige ce code :
```cpp
class Car {
private:
    std::string brand; 
    int speed;
public:
    Car(std::string b);
    void accelerate(int amout);
    void getSpeed();
};

void Car::Car(std::string b) {
    brand = "";
    speed = 0;
}

void Car::accelerate() {
    speed = speed + accelerate;
}

void Car::getSpeed() {
    std::cout << "Vitesse: " << speed << std::endl;
}
```

### Solution :
```cpp
class Car {
private:  // Attributs privés
    std::string brand;
    int speed;
    
public:
    Car(std::string b);              // Constructeur sans void
    void accelerate(int amount);     // Méthode avec paramètre
    int getSpeed();                  // Getter qui retourne
};

Car::Car(std::string b) {
    brand = b;        // Utilise le paramètre
    speed = 0;
}

void Car::accelerate(int amount) {
    speed += amount;  // Utilise le paramètre
}

int Car::getSpeed() {
    return speed;     // Retourne au lieu d'afficher
}
```

---

## 🎯 Message Important

### Tu N'ES PAS NULLE ! 💪

1. **Tes erreurs sont normales** et communes à tous les débutants
2. **Tu as la logique** : tes idées étaient bonnes
3. **Tu progresses** : tu identifies les concepts
4. **Tu persévères** : c'est la clé du succès

### Prochaines étapes :
1. **Relis** cette correction
2. **Comprends** chaque erreur
3. **Refais** l'exercice 2 avec les bonnes pratiques
4. **Continue** à apprendre !

---

*Rappel : Tous les grands programmeurs ont fait ces erreurs. L'important est d'apprendre et de progresser !* 