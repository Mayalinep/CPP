/*
🏋️ EXERCICE 2 : VERSION FINALE CORRIGÉE
Ton code était excellent ! Juste quelques petites corrections de syntaxe.
*/

#include <iostream>
#include <string>

class BankAccount {
private:
    double balance;
    std::string accountNumber;
    
public:
    // Constructeur
    BankAccount(std::string number, double initialBalance);
    
    //méthodes publiques
    void deposit(double amount);
    bool withdraw(double amount);  // ✅ Excellente idée le bool !
    double getBalance();

    //destructeur
    ~BankAccount();
};

BankAccount::BankAccount(std::string number, double initialBalance){
    balance = initialBalance;
    accountNumber = number;
    // ✅ CORRECTION : Ajout d'un espace et "créé"
    std::cout << "Compte " << accountNumber << " créé avec " << balance << "€" << std::endl;
}

void BankAccount::deposit(double amount){
    balance += amount;
    // ✅ CORRECTION : Ajout du ; manquant et "Dépôt"
    std::cout << "Dépôt de " << amount << "€ effectué" << std::endl;
}

bool BankAccount::withdraw(double amount){
    if(amount > balance)
    {
        // ✅ CORRECTION : Guillemets pour la chaîne
        std::cout << "Retrait impossible" << std::endl;
        return false;  // ✅ Pas besoin de parenthèses
    }
    else{
        balance -= amount;
        std::cout << "Retrait de " << amount << "€ effectué" << std::endl;
        return true;   // ✅ Pas besoin de parenthèses
    }
}

double BankAccount::getBalance(){
    // ✅ CORRECTION : Return au lieu d'affichage + return
    return balance;
}

BankAccount::~BankAccount(){
    // ✅ CORRECTION : Ajout d'espaces
    std::cout << "Compte " << accountNumber << " fermé" << std::endl;
}

int main() {
    BankAccount myAccount("123456", 100.0);
    myAccount.deposit(50);
    myAccount.withdraw(30);
    
    // ✅ CORRECTION : Utilisation du return de getBalance
    std::cout << "Solde actuel : " << myAccount.getBalance() << "€" << std::endl;

    return 0;
}

/*
📝 ANALYSE DE TON EXCELLENT TRAVAIL :

✅ CE QUI ÉTAIT PARFAIT :
1. Structure classe avec private/public
2. Constructeur sans void
3. Paramètres bien utilisés
4. Logique de withdraw avec vérification
5. Idée du bool pour withdraw (très pro !)
6. Organisation générale

🔧 PETITES CORRECTIONS FAITES :
1. Ajout du ; manquant ligne 68
2. Guillemets autour de "Retrait impossible"
3. getBalance qui return au lieu d'afficher
4. Espaces dans les messages
5. Utilisation du return de getBalance dans le main

🎯 PROGRESSION ÉNORME :
- Tu as corrigé TOUTES tes erreurs principales !
- Tu as même ajouté des améliorations (bool withdraw)
- Ton code est maintenant de niveau intermédiaire !
*/ 