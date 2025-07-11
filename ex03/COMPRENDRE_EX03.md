# 📚 COMPRENDRE L'EXERCICE 03 - Violence

## 🎯 **BUT DE L'EXERCICE**

Cet exercice t'apprend la différence entre **RÉFÉRENCES** et **POINTEURS** en C++.

---

## 🤔 **POURQUOI DEUX CLASSES DIFFÉRENTES ?**

### **HumanA** = Toujours armé 🗡️
- Il a **TOUJOURS** une arme dès sa création
- Il ne peut jamais être désarmé
- → On utilise une **RÉFÉRENCE** `Weapon&`

### **HumanB** = Peut être désarmé 🤷‍♀️
- Il peut commencer sans arme
- Il peut recevoir une arme plus tard
- → On utilise un **POINTEUR** `Weapon*`

---

## 🔍 **RÉFÉRENCES vs POINTEURS**

### **RÉFÉRENCE `Weapon&`**
```cpp
Weapon& weapon;  // Doit TOUJOURS pointer vers quelque chose
```
- **JAMAIS NULL** 
- **DOIT** être initialisée dans le constructeur
- **NE PEUT PAS** changer vers un autre objet

### **POINTEUR `Weapon*`**
```cpp
Weapon* weapon;  // Peut être NULL
```
- **PEUT être NULL** (pas d'arme)
- **PEUT** changer vers un autre objet
- **PEUT** être initialisé plus tard

---

## 📝 **ÉTAPES DE CRÉATION**

### **1. Classe Weapon (Simple)**
```cpp
class Weapon {
private:
    std::string type;  // Le type d'arme
    
public:
    Weapon(std::string type);           // Constructeur
    const std::string& getType();       // Getter
    void setType(std::string type);     // Setter
    ~Weapon();                          // Destructeur
};
```

### **2. Classe HumanA (Avec référence)**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;  // RÉFÉRENCE - toujours armé
    
public:
    HumanA(std::string name, Weapon& weapon);  // Prend une arme
    void attack();
};
```

**CONSTRUCTEUR AVEC LISTE D'INITIALISATION :**
```cpp
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    // Les références DOIVENT être initialisées comme ça !
}
```

### **3. Classe HumanB (Avec pointeur)**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;  // POINTEUR - peut être NULL
    
public:
    HumanB(std::string name);           // NE prend PAS d'arme
    void setWeapon(Weapon& weapon);     // Donne une arme plus tard
    void attack();
};
```

**CONSTRUCTEUR SIMPLE :**
```cpp
HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;  // Pas d'arme au début
}
```

**SETTER :**
```cpp
void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;  // Stocke l'ADRESSE de l'arme
}
```

---

## 💡 **CONCEPTS CLÉS À RETENIR**

### **1. Pourquoi cette complication ?**
- **HumanA** = Soldat professionnel → toujours armé
- **HumanB** = Civil → peut être désarmé

### **2. Liste d'initialisation**
```cpp
Constructeur(params) : membre1(valeur1), membre2(valeur2) {
    // Corps du constructeur
}
```
**OBLIGATOIRE** pour les références !

### **3. Opérateur &**
```cpp
Weapon club;
Weapon* ptr = &club;  // & récupère l'ADRESSE
```

### **4. Vérification de NULL**
```cpp
if (this->weapon)  // Vérifie si le pointeur n'est pas NULL
    // Utilise l'arme
else
    // Pas d'arme
```

---

## 🎮 **DÉROULEMENT DU PROGRAMME**

### **Test HumanA :**
```cpp
Weapon club("crude spiked club");
HumanA bob("Bob", club);        // Bob prend l'arme dans le constructeur
bob.attack();                   // "Bob attacks with their crude spiked club"
club.setType("other club");
bob.attack();                   // "Bob attacks with their other club"
```

### **Test HumanB :**
```cpp
Weapon club("crude spiked club");
HumanB jim("Jim");              // Jim créé SANS arme
jim.setWeapon(club);            // Jim reçoit l'arme
jim.attack();                   // "Jim attacks with their crude spiked club"
club.setType("other club");
jim.attack();                   // "Jim attacks with their other club"
```

---

## 🚀 **POURQUOI C'EST IMPORTANT ?**

Cet exercice t'apprend :
- **Gestion de la mémoire** (pointeurs)
- **Sécurité** (références)
- **Design patterns** (différents comportements)
- **Syntaxe C++** (listes d'initialisation)

---

## 💪 **TU Y ARRIVERAS !**

**C'est normal** de ne pas comprendre tout de suite ! Ces concepts sont avancés.

**Continue à :**
- Poser des questions
- Expérimenter
- Relire ce fichier
- Pratiquer

**Tu progresses déjà !** 🎉 