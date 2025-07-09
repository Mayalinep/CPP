# 🏋️ Exercice 2 : Public vs Private - Encapsulation

## 📋 Informations Générales
- **Objectif** : Comprendre l'encapsulation et pourquoi c'est important
- **Durée** : 10 minutes
- **Niveau** : Débutant
- **Fichier** : `exercice_02_public_private.cpp`

---

## 🎯 Consignes

### 1. Créer une classe "BankAccount" (compte bancaire)
La classe doit contenir :
- **Un attribut privé** `balance` (solde) de type `double`
- **Un attribut privé** `accountNumber` (numéro de compte) de type `std::string`
- **Un constructeur** qui prend le numéro de compte et un solde initial
- **Une méthode publique** `deposit(double amount)` pour déposer de l'argent
- **Une méthode publique** `withdraw(double amount)` pour retirer de l'argent
- **Une méthode publique** `getBalance()` pour consulter le solde
- **Un destructeur** qui affiche un message de fermeture du compte

### 2. Implémenter le main
Dans la fonction main :
- Créer un compte avec 100€ de solde initial
- Déposer 50€
- Retirer 30€
- Afficher le solde final
- Observer quand le destructeur s'exécute

---

## 💡 Exemple de Sortie Attendue

```
Compte 123456 créé avec 100€
Dépôt de 50€ effectué
Retrait de 30€ effectué
Solde actuel : 120€
Compte 123456 fermé
```

---

## 🎯 Objectifs Pédagogiques

À la fin de cet exercice, tu sauras :
- ✅ Comprendre pourquoi `balance` doit être privé (sécurité)
- ✅ Utiliser des méthodes publiques pour contrôler l'accès
- ✅ Voir l'encapsulation en action
- ✅ Implémenter des getters/setters simples

---

## 🔧 Structure Recommandée

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    double balance;
    std::string accountNumber;
    
public:
    BankAccount(std::string number, double initialBalance);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    ~BankAccount();
};

// Implémentations
BankAccount::BankAccount(std::string number, double initialBalance) {
    // Ton code ici
}

void BankAccount::deposit(double amount) {
    // Ton code ici
}

void BankAccount::withdraw(double amount) {
    // Ton code ici
}

double BankAccount::getBalance() {
    // Ton code ici
}

BankAccount::~BankAccount() {
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
BankAccount::BankAccount(std::string number, double initialBalance) {
    accountNumber = number;
    balance = initialBalance;
    std::cout << "Compte " << accountNumber << " créé avec " << balance << "€" << std::endl;
}
```

### Méthode deposit
```cpp
void BankAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Dépôt de " << amount << "€ effectué" << std::endl;
}
```

### Méthode withdraw
```cpp
void BankAccount::withdraw(double amount) {
    balance -= amount;
    std::cout << "Retrait de " << amount << "€ effectué" << std::endl;
}
```

### Méthode getBalance
```cpp
double BankAccount::getBalance() {
    return balance;
}
```

### Destructeur
```cpp
BankAccount::~BankAccount() {
    std::cout << "Compte " << accountNumber << " fermé" << std::endl;
}
```

### Main
```cpp
int main() {
    BankAccount account("123456", 100.0);
    account.deposit(50.0);
    account.withdraw(30.0);
    std::cout << "Solde actuel : " << account.getBalance() << "€" << std::endl;
    return 0;
}
```

---

## 🤔 Réflexion Importante

### Pourquoi `balance` est-il privé ?
- **Sans encapsulation** : `account.balance = 1000000;` (fraude possible !)
- **Avec encapsulation** : On contrôle via `deposit()` et `withdraw()`
- **Sécurité** : Impossible de modifier directement le solde
- **Contrôle** : On peut ajouter des vérifications (solde négatif, etc.)

### Exemple de danger sans encapsulation :
```cpp
// Si balance était public :
BankAccount account("123", 100.0);
account.balance = 999999.99;  // 😱 Fraude !

// Avec encapsulation :
BankAccount account("123", 100.0);
// account.balance = 999999.99;  // ❌ ERREUR de compilation !
account.deposit(50.0);  // ✅ Seule façon légale
```

---

## 🎯 Bonus (Optionnel)

Ajoute une vérification dans `withdraw` pour éviter les soldes négatifs :

```cpp
void BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Retrait de " << amount << "€ effectué" << std::endl;
    } else {
        std::cout << "Solde insuffisant pour retirer " << amount << "€" << std::endl;
    }
}
```

---

## 🚀 Pour Tester

```bash
# Compiler
g++ -o test exercice_02_public_private.cpp

# Exécuter
./test
```

---

## 🎯 Points Clés à Retenir

1. **Encapsulation** : Attributs privés, méthodes publiques pour y accéder
2. **Sécurité** : Impossible de modifier directement les données sensibles
3. **Contrôle** : Les méthodes peuvent ajouter des vérifications
4. **Getters** : Méthodes pour consulter les attributs privés
5. **Setters** : Méthodes pour modifier les attributs privés (ici deposit/withdraw)

---

*Quand tu as terminé, passe à l'exercice 3 ou à l'exercice zombie !* 