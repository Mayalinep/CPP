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