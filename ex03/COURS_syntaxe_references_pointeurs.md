# 📚 Cours - Syntaxe Références et Pointeurs dans les Classes

## 🎯 **Objectif**
Maîtriser la syntaxe pour utiliser des références et pointeurs comme attributs de classe.

---

## 🔍 **1. Rappel : Références vs Pointeurs**

### **Variables simples :**
```cpp
int x = 42;

// Pointeur
int* ptr = &x;        // ptr contient l'adresse de x
*ptr = 100;           // Modifier x via le pointeur

// Référence  
int& ref = x;         // ref est un alias de x
ref = 200;            // Modifier x directement
```

### **Différences clés :**
| Pointeur                         | Référence                             |
|----------------------------------|---------------------------------------|
| Peut être NULL                   | Ne peut pas être NULL                 |
| Peut changer de cible            | Ne peut pas changer de cible          |
| Syntaxe `*ptr` pour accéder      | Syntaxe directe                       |
| Peut être déclaré puis initialisé| Doit être initialisé à la déclaration |

---

## 🔧 **2. Syntaxe dans les Classes**

### **Classe avec pointeur :**
```cpp
class MyClass {
private:
    int* ptr;           // Pointeur vers un int

public:
    MyClass() {
        ptr = nullptr;  // Peut être NULL
    }
    
    MyClass(int& value) {
        ptr = &value;   // Pointe vers value
    }
    
    void setValue(int& value) {
        ptr = &value;   // Peut changer de cible
    }
    
    void useValue() {
        if (ptr != nullptr) {
            std::cout << *ptr << std::endl;  // Déréférencement
        }
    }
};
```

### **Classe avec référence :**
```cpp
class MyClass {
private:
    int& ref;           // Référence vers un int

public:
    // OBLIGATOIRE : initialiser dans la liste d'initialisation
    MyClass(int& value) : ref(value) {
        // ref est maintenant un alias de value
    }
    
    void useValue() {
        std::cout << ref << std::endl;  // Accès direct, pas de *
    }
    
    // IMPOSSIBLE : pas de setter pour changer la cible
    // void setRef(int& newValue) { ref = newValue; }  // ← Ça change la VALEUR, pas la cible
};
```

---

## 💡 **POINT CRUCIAL : Pourquoi `ref = newValue` ne change pas la cible ?**

### **Le problème avec les références :**
```cpp
int a = 10;
int b = 20;

class Test {
private:
    int& ref;

public:
    Test(int& value) : ref(value) { }
    
    // ❌ Cette fonction ne fait PAS ce qu'on croit !
    void setRef(int& newValue) {
        ref = newValue;  // Qu'est-ce que ça fait VRAIMENT ?
    }
};

// Test :
Test test(a);        // ref est maintenant un alias de 'a'
std::cout << a;      // Affiche : 10

test.setRef(b);      // On pense que ref pointe vers 'b' maintenant...
std::cout << a;      // Affiche : 20 (!!)
std::cout << b;      // Affiche : 20
```

### **🔍 Explication détaillée :**

**Ce qu'on CROIT que `ref = newValue` fait :**
```cpp
// On pense que ref devient un alias de newValue
ref = newValue;  // "ref pointe maintenant vers newValue"
```

**Ce que `ref = newValue` fait VRAIMENT :**
```cpp
// ref est DÉJÀ un alias de quelque chose
// Donc ref = newValue signifie : "copie la valeur de newValue dans ref"
// Qui est équivalent à :
ref = newValue;  // ← Ça copie la VALEUR, pas l'adresse !
```

### **Comparaison avec un pointeur :**
```cpp
class TestPointer {
private:
    int* ptr;

public:
    TestPointer(int& value) : ptr(&value) { }
    
    // ✅ Avec un pointeur, on PEUT changer la cible
    void setPtr(int& newValue) {
        ptr = &newValue;  // ptr pointe maintenant vers newValue
    }
};

class TestReference {
private:
    int& ref;

public:
    TestReference(int& value) : ref(value) { }
    
    // ❌ Avec une référence, on NE PEUT PAS changer la cible
    void setRef(int& newValue) {
        ref = newValue;  // Copie la VALEUR de newValue dans ref
    }
};
```

### **🎯 Exemple concret :**
```cpp
int x = 100;
int y = 200;

// Avec référence :
TestReference testRef(x);  // ref est un alias de x
testRef.setRef(y);         // x devient 200 (copie de y)
std::cout << x;            // Affiche : 200
std::cout << y;            // Affiche : 200

// Avec pointeur :
TestPointer testPtr(x);    // ptr pointe vers x
testPtr.setPtr(y);         // ptr pointe maintenant vers y
std::cout << x;            // Affiche : 100 (inchangé)
std::cout << y;            // Affiche : 200
```

### **🔑 Règle à retenir :**
> **Une référence est un ALIAS permanent. Une fois créée, elle ne peut plus être "réassignée" à un autre objet. Toute tentative de "réassignation" copie en fait la valeur.**

---

## 🎯 **DÉMONSTRATION avec les ADRESSES MÉMOIRE**

### **Exemple 1 : Ce qui se passe VRAIMENT avec setRef**
```cpp
#include <iostream>

int main() {
    int a = 10;      // a est à l'adresse 0x1000 (exemple)
    int b = 20;      // b est à l'adresse 0x2000 (exemple)
    
    std::cout << "=== AVANT ===" << std::endl;
    std::cout << "a = " << a << " (adresse: " << &a << ")" << std::endl;
    std::cout << "b = " << b << " (adresse: " << &b << ")" << std::endl;
    
    // Créer une référence
    int& ref = a;    // ref est un alias de 'a'
    
    std::cout << "\n=== APRÈS création de ref ===" << std::endl;
    std::cout << "ref = " << ref << " (adresse: " << &ref << ")" << std::endl;
    std::cout << "a = " << a << " (adresse: " << &a << ")" << std::endl;
    // ☝️ ref et a ont la MÊME adresse !
    
    // Maintenant on fait : ref = b
    ref = b;         // Qu'est-ce qui se passe ?
    
    std::cout << "\n=== APRÈS ref = b ===" << std::endl;
    std::cout << "ref = " << ref << " (adresse: " << &ref << ")" << std::endl;
    std::cout << "a = " << a << " (adresse: " << &a << ")" << std::endl;
    std::cout << "b = " << b << " (adresse: " << &b << ")" << std::endl;
    
    // RÉSULTAT :
    // ref = 20 (adresse: 0x1000) ← MÊME adresse qu'avant !
    // a = 20 (adresse: 0x1000)   ← a a changé de valeur
    // b = 20 (adresse: 0x2000)   ← b n'a pas changé
}
```

### **🔍 Analyse du résultat :**
- **L'adresse de `ref` ne change JAMAIS** (toujours 0x1000)
- **`ref = b`** a copié la valeur de `b` dans `a`
- **`ref` reste un alias de `a`** pour toujours

### **Exemple 2 : Avec setRef dans une classe**
```cpp
class Test {
private:
    int& ref;

public:
    Test(int& value) : ref(value) { }
    
    void setRef(int& newValue) {
        ref = newValue;  // Copie la valeur, ne change pas la cible
    }
    
    void showInfo() {
        std::cout << "ref = " << ref << " (adresse: " << &ref << ")" << std::endl;
    }
};

int main() {
    int x = 100;     // x à l'adresse 0x3000
    int y = 200;     // y à l'adresse 0x4000
    
    Test test(x);    // ref est un alias de x
    
    std::cout << "=== AVANT setRef ===" << std::endl;
    test.showInfo();           // ref = 100 (adresse: 0x3000)
    std::cout << "x = " << x << " (adresse: " << &x << ")" << std::endl;
    
    test.setRef(y);  // Appelle ref = y
    
    std::cout << "\n=== APRÈS setRef ===" << std::endl;
    test.showInfo();           // ref = 200 (adresse: 0x3000) ← MÊME adresse !
    std::cout << "x = " << x << " (adresse: " << &x << ")" << std::endl;
    std::cout << "y = " << y << " (adresse: " << &y << ")" << std::endl;
    
    // RÉSULTAT :
    // ref pointe toujours vers x (adresse 0x3000)
    // x = 200 (sa valeur a changé)
    // y = 200 (inchangé)
}
```

### **🆚 Comparaison avec un pointeur :**
```cpp
class TestPointer {
private:
    int* ptr;

public:
    TestPointer(int& value) : ptr(&value) { }
    
    void setPtr(int& newValue) {
        ptr = &newValue;  // Change l'adresse stockée dans ptr
    }
    
    void showInfo() {
        std::cout << "ptr pointe vers " << ptr << " (valeur: " << *ptr << ")" << std::endl;
    }
};

int main() {
    int x = 100;     // x à l'adresse 0x3000
    int y = 200;     // y à l'adresse 0x4000
    
    TestPointer test(x);  // ptr = 0x3000
    
    std::cout << "=== AVANT setPtr ===" << std::endl;
    test.showInfo();      // ptr pointe vers 0x3000 (valeur: 100)
    
    test.setPtr(y);       // ptr = &y
    
    std::cout << "\n=== APRÈS setPtr ===" << std::endl;
    test.showInfo();      // ptr pointe vers 0x4000 (valeur: 200)
    std::cout << "x = " << x << std::endl;  // x = 100 (inchangé)
    
    // RÉSULTAT :
    // ptr pointe maintenant vers y (adresse 0x4000)
    // x = 100 (inchangé)
}
```

### **🎯 RÉPONSE à ta question :**

**Q: "Si je fais setRef, l'adresse et la valeur peuvent être changées ?"**

**R: NON !** 
- ❌ **L'adresse ne change JAMAIS** (ref reste toujours un alias du même objet)
- ✅ **Seule la valeur change** (la valeur de l'objet référencé)

**Q: "Ça agit comme int& ref = q ?"**

**R: NON !**
- `int& ref = q` → **Création** d'une référence (change la cible)
- `ref = q` → **Assignation** de valeur (copie la valeur, garde la même cible)

---

## 🎯 **3. Liste d'Initialisation (IMPORTANT !)**

### **Pourquoi obligatoire pour les références ?**
```cpp
class Test {
private:
    int& ref;

public:
    // ❌ ERREUR : Ne compile pas
    Test(int& value) {
        ref = value;  // Impossible ! ref doit être initialisé à la déclaration
    }
    
    // ✅ CORRECT : Liste d'initialisation
    Test(int& value) : ref(value) {
        // Maintenant ref est initialisé
    }
};
```

### **Syntaxe de la liste d'initialisation :**
```cpp
class MyClass {
private:
    std::string name;
    int& number;
    Weapon& weapon;

public:
    // Syntaxe : Constructeur(params) : attribut1(valeur1), attribut2(valeur2) { }
    MyClass(std::string n, int& num, Weapon& w) : name(n), number(num), weapon(w) {
        // Corps du constructeur (peut être vide)
    }
};
```

---

## 🔧 **4. Syntaxe pour l'exercice 03**

### **Classe Weapon :**
```cpp
class Weapon {
private:
    std::string type;

public:
    Weapon(std::string weaponType) : type(weaponType) { }
    
    // Référence constante en retour
    const std::string& getType() const {
        return type;  // Retourne une référence vers type
    }
    
    void setType(std::string newType) {
        type = newType;
    }
};
```

### **HumanA (avec référence) :**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;     // Référence vers une Weapon

public:
    // Liste d'initialisation OBLIGATOIRE pour weapon
    HumanA(std::string humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon) {
        // weapon est maintenant un alias de humanWeapon
    }
    
    void attack() {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
        //                                            ↑ Accès direct, pas de ->
    }
};
```

### **HumanB (avec pointeur) :**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;     // Pointeur vers une Weapon

public:
    HumanB(std::string humanName) : name(humanName), weapon(nullptr) {
        // weapon est NULL au début
    }
    
    void setWeapon(Weapon& humanWeapon) {
        weapon = &humanWeapon;  // weapon pointe maintenant vers humanWeapon
    }
    
    void attack() {
        if (weapon != nullptr) {
            std::cout << name << " attacks with their " << weapon->getType() << std::endl;
            //                                            ↑ Flèche pour les pointeurs
        }
    }
};
```

---

## 🎯 **5. Syntaxes importantes à retenir**

### **Déclaration :**
```cpp
// Dans la classe
Weapon& weapon;     // Référence
Weapon* weapon;     // Pointeur
```

### **Initialisation :**
```cpp
// Constructeur avec référence
HumanA(std::string name, Weapon& w) : weapon(w) { }

// Constructeur avec pointeur
HumanB(std::string name) : weapon(nullptr) { }
```

### **Utilisation :**
```cpp
// Avec référence
weapon.getType()    // Accès direct

// Avec pointeur
weapon->getType()   // Flèche
(*weapon).getType() // Ou déréférencement puis point
```

### **Modification :**
```cpp
// Pointeur : peut changer de cible
weapon = &autreWeapon;

// Référence : ne peut PAS changer de cible
// weapon = autreWeapon;  // ← Ça change la VALEUR, pas la cible
```

---

## 🔍 **6. Erreurs courantes**

### **❌ Erreur 1 : Référence non initialisée**
```cpp
class Test {
    int& ref;
public:
    Test() { }  // ERREUR ! ref n'est pas initialisé
};
```

### **❌ Erreur 2 : Mauvaise syntaxe d'accès**
```cpp
Weapon* weapon;
weapon.getType();   // ERREUR ! C'est un pointeur, utilise ->
```

### **❌ Erreur 3 : Confusion référence/pointeur**
```cpp
Weapon& weapon;
weapon = &autreWeapon;  // ERREUR ! weapon est une référence, pas un pointeur
```

---

## 🎯 **7. Exercices de syntaxe**

### **Exercice 1 : Complète le code**
```cpp
class Student {
private:
    std::string name;
    Book& _______;        // Référence vers Book

public:
    Student(std::string n, Book& b) : _______, _______ {
        // Initialise name et book
    }
    
    void read() {
        std::cout << book._______ << std::endl;  // Appelle getTitle()
    }
};
```

### **Exercice 2 : Corrige les erreurs**
```cpp
class Car {
private:
    Engine* engine;

public:
    Car() {
        engine = null;      // Erreur 1
    }
    
    void start() {
        engine.start();     // Erreur 2
    }
};
```

---

## 🏆 **Résumé de la syntaxe**

| Opération | Référence | Pointeur |
|-----------|-----------|----------|
| **Déclaration** | `Type& ref` | `Type* ptr` |
| **Initialisation** | `: ref(value)` | `= &value` ou `= nullptr` |
| **Accès** | `ref.method()` | `ptr->method()` |
| **Vérification** | Pas besoin | `if (ptr != nullptr)` |
| **Changement** | Impossible | `ptr = &autreObjet` |

---

**Maintenant tu as toute la syntaxe ! Prêt à corriger ton code ?** 🚀 