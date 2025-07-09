/*
🏋️ EXERCICE 2 : CORRECTION DÉTAILLÉE
Analysons tes erreurs pour t'aider à progresser !
*/

#include <iostream>
#include <string>

// ✅ CORRECTION DE TA CLASSE BankAccount
class BankAccount {
private:
    double balance;
    std::string accountNumber;
    // ❌ TON ERREUR : Tu avais ajouté "double initialBalance" (pas nécessaire)
    // ❌ TON ERREUR : Tu avais "double deposit" et "double withdraw" (ce sont des méthodes, pas des variables)
    
public:
    // ✅ CORRECTION : Constructeur (pas "void BankAccount")
    BankAccount(std::string number, double initialBalance);
    
    // ✅ CORRECTION : Méthodes (pas des variables)
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    
    // ✅ CORRECTION : Destructeur
    ~BankAccount();
};

// ✅ CORRECTION : Implémentation du constructeur
BankAccount::BankAccount(std::string number, double initialBalance) {
    // ❌ TON ERREUR : Tu avais "balance = initialBalance" mais "initialBalance" n'était pas le paramètre
    // ❌ TON ERREUR : Tu avais "accountNumber = """ au lieu d'utiliser le paramètre
    
    accountNumber = number;        // ✅ Utilise le paramètre
    balance = initialBalance;      // ✅ Utilise le paramètre
    
    std::cout << "Compte " << accountNumber << " créé avec " << balance << "€" << std::endl;
}

// ✅ CORRECTION : Méthode deposit
void BankAccount::deposit(double amount) {
    // ❌ TON ERREUR : Tu utilisais une variable "deposit" qui n'existait pas
    // ✅ CORRECTION : Utilise le paramètre "amount"
    
    balance += amount;  // ou balance = balance + amount
    std::cout << "Dépôt de " << amount << "€ effectué" << std::endl;
}

// ✅ CORRECTION : Méthode withdraw
void BankAccount::withdraw(double amount) {
    // ❌ TON ERREUR : Tu utilisais une variable "withdraw" qui n'existait pas
    // ✅ CORRECTION : Utilise le paramètre "amount"
    
    if (amount > balance) {
        std::cout << "Solde insuffisant pour retirer " << amount << "€" << std::endl;
    } else {
        balance -= amount;  // ou balance = balance - amount
        std::cout << "Retrait de " << amount << "€ effectué" << std::endl;
    }
}

// ✅ CORRECTION : Méthode getBalance
double BankAccount::getBalance() {
    // ❌ TON ERREUR : Tu avais "void getBalance()" et tu affichais au lieu de retourner
    // ✅ CORRECTION : Retourne la valeur
    
    return balance;
}

// ✅ CORRECTION : Destructeur
BankAccount::~BankAccount() {
    // ❌ TON ERREUR : Tu avais oublié un espace avant "fermé"
    std::cout << "Compte " << accountNumber << " fermé" << std::endl;
}

// ✅ CORRECTION : Main
int main() {
    BankAccount account("123456", 100.0);
    account.deposit(50.0);
    account.withdraw(30.0);
    std::cout << "Solde actuel : " << account.getBalance() << "€" << std::endl;
    
    return 0;
}

/*
📝 ANALYSE DE TES ERREURS (TRÈS COMMUNES !) :

🔴 ERREUR 1 : Confusion variables/méthodes
- Tu avais : double deposit; double withdraw;
- Correct : void deposit(double amount); void withdraw(double amount);
- Pourquoi : deposit et withdraw sont des ACTIONS, pas des DONNÉES

🔴 ERREUR 2 : Constructeur mal déclaré
- Tu avais : void BankAccount(...)
- Correct : BankAccount(...)
- Pourquoi : Un constructeur n'a jamais de type de retour

🔴 ERREUR 3 : Paramètres non utilisés
- Tu avais : balance = initialBalance (mais initialBalance n'était pas le paramètre)
- Correct : balance = initialBalance (où initialBalance est le paramètre)

🔴 ERREUR 4 : getBalance mal implémenté
- Tu avais : void getBalance() qui affiche
- Correct : double getBalance() qui retourne
- Pourquoi : Un getter RETOURNE une valeur, il ne l'affiche pas

✅ CE QUI ÉTAIT BIEN :
- Idée générale de la classe
- Logique des vérifications dans withdraw
- Structure générale du code
- Tu as essayé et c'est le plus important !

🎯 SORTIE ATTENDUE :
Compte 123456 créé avec 100€
Dépôt de 50€ effectué
Retrait de 30€ effectué
Solde actuel : 120€
Compte 123456 fermé
*/ 