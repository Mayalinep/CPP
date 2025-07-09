/*
🏋️ EXERCICE 2 : Public vs Private - Encapsulation
Objectif : Comprendre l'encapsulation et pourquoi c'est important
Durée : 10 minutes
Niveau : Débutant

📋 CONSIGNES :
1. Crée une classe "BankAccount" (compte bancaire) avec :
   - Un attribut privé "balance" (solde) de type double
   - Un attribut privé "accountNumber" (numéro de compte) de type string
   - Un constructeur qui prend le numéro de compte et un solde initial
   - Une méthode publique "deposit(double amount)" pour déposer de l'argent
   - Une méthode publique "withdraw(double amount)" pour retirer de l'argent
   - Une méthode publique "getBalance()" pour consulter le solde
   - Un destructeur qui affiche un message

2. Dans le main :
   - Crée un compte avec 100€ de solde initial
   - Dépose 50€
   - Retire 30€
   - Affiche le solde final
   - Essaie de comprendre pourquoi balance est privé !

💡 EXEMPLE DE SORTIE ATTENDUE :
Compte 123456 créé avec 100€
Dépôt de 50€ effectué
Retrait de 30€ effectué
Solde actuel : 120€
Compte 123456 fermé

🎯 OBJECTIF PÉDAGOGIQUE :
- Comprendre pourquoi balance doit être privé (sécurité)
- Utiliser des méthodes publiques pour contrôler l'accès
- Voir l'encapsulation en action
*/

#include <iostream>
#include <string>

// 🔧 TON CODE ICI : Crée la classe BankAccount
class BankAccount {
private:
    double balance;
    std::string accountNumber;
    
public:
    // Constructeur
    BankAccount(std::string number, double initialBalance);
    
    //méthodes publiques
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance();

    //destructeur
    ~BankAccount();
    
};

BankAccount::BankAccount(std::string number, double initialBalance){
    balance = initialBalance;
    accountNumber = number;
    std::cout <<" Compte " << accountNumber << "cree avec " << balance << " €" << std::endl;
}
// 🔧 TON CODE ICI : Implémente les méthodes
void BankAccount::deposit(double amount){
    balance += amount;
    std::cout << " Depot de " << amount << " € effectué"
}

bool BankAccount::withdraw(double amount){
    if(amount > balance)
    {
        std::cout << Retrait impossible << std::endl;
        return (false);
    }
    else{
        balance -= amount;
        std::cout << "Retrait de " << amount << " € effectué" << std::endl;
        return (true);
    }
}

double BankAccount::getBalance(){
    std::cout << "Solde actuel : " << balance <<" €" << std::endl;
}

BankAccount::~BankAccount(){
    std::cout << "Compte " << accountNumber << "fermé"<<std::endl;
}

// 🔧 TON CODE ICI : Implémente le main
int main() {
    // Crée un compte, teste les dépôts/retraits
    BankAccount myAccount("123456", 100.0);
    myAccount.deposit(50);
    myAccount.withdraw(30);
    myAccount.getBalance();

    return 0;
}

/*
🎯 AIDE SI TU BLOQUES :

Structure de la classe :
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

Exemple de méthode deposit :
void BankAccount::deposit(double amount) {
    balance += amount;  // On peut accéder à balance car on est dans la classe
    std::cout << "Dépôt de " << amount << "€ effectué" << std::endl;
}

🤔 RÉFLEXION IMPORTANTE :
Pourquoi balance est-il privé ?
- Si balance était public, on pourrait faire : account.balance = 1000000;
- Avec les méthodes, on contrôle les opérations
- On peut ajouter des vérifications (solde négatif, etc.)

🎯 BONUS : Essaie d'ajouter une vérification dans withdraw pour éviter 
les soldes négatifs !
*/ 