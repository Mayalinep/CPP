# ⚔️ Analyse du Sujet - Exercice 03 : Weapon & Humans

## 📋 **Traduction du Sujet**

### **Fichiers à rendre :**
- `Makefile`, `main.cpp`
- `Weapon.{h,hpp}`, `Weapon.cpp`
- `HumanA.{h,hpp}`, `HumanA.cpp`
- `HumanB.{h,hpp}`, `HumanB.cpp`

### **Ce qu'il faut faire :**

#### **1. Classe Weapon**
- **Attribut privé** : `type` (string)
- **getType()** : retourne une référence constante vers type
- **setType()** : modifie le type avec la nouvelle valeur

#### **2. Classes HumanA et HumanB**
- **Attributs** : name (string) et weapon
- **Méthode attack()** : affiche `<name> attacks with their <weapon type>`

#### **3. Différences importantes :**
- **HumanA** : Prend la Weapon dans son constructeur, toujours armé
- **HumanB** : Ne prend pas la Weapon dans le constructeur, peut ne pas avoir d'arme

---

## 🎯 **Ce que cet exercice veut t'apprendre**

### **Notions principales :**
1. **Références vs Pointeurs** (suite de l'ex02)
2. **Références constantes** (`const std::string&`)
3. **Composition de classes** (une classe qui contient une autre)
4. **Différents designs** selon les besoins

### **Question clé du sujet :**
> "Dans quel cas utiliser un pointeur vers Weapon ? Et une référence vers Weapon ?"

---

## 🔍 **Analyse du code de test**

### **Test HumanA :**
```cpp
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);              // ← Weapon passée au constructeur
bob.attack();
club.setType("some other type of club");
bob.attack();                         // ← Doit afficher le nouveau type !
```

### **Test HumanB :**
```cpp
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");                    // ← Pas de weapon au constructeur
jim.setWeapon(club);                  // ← Weapon ajoutée après
jim.attack();
club.setType("some other type of club");
jim.attack();                         // ← Doit afficher le nouveau type !
```

---

## 🤔 **Questions pour vérifier ta compréhension**

### **Question 1 :** Pourquoi HumanA doit-il utiliser une référence ?

**Réponse :**
```
il doit utiliser une reference car c est un alias de weapon et qu il est tjrd armer
[À compléter par Maya]
```

### **Question 2 :** Pourquoi HumanB doit-il utiliser un pointeur ?

**Réponse :**
```  
il utilise un pointeur pour pouvoir s armer par la suite et donc utiliser en temps voulu le weapon. et qd on va set modifier de maniere indirect l arme 
[À compléter par Maya]
```

### **Question 3 :** Que signifie "référence constante" dans getType() ?

**Réponse :**
```
cq signifie que getType va retourner un alias de la constante type de la class Weapon
[À compléter par Maya]
```

### **Question 4 :** Pourquoi les deux attaques doivent-elles afficher des types différents ?

**Réponse :**
```
je sais pas
[À compléter par Maya]
```

---

## 🎯 **Design à comprendre AVANT de coder**

### **HumanA (toujours armé)**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;        // ← Référence ! Toujours valide

public:
    HumanA(std::string name, Weapon& weapon);  // ← Weapon obligatoire
    void attack();
};
```

### **HumanB (parfois armé)**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;        // ← Pointeur ! Peut être NULL

public:
    HumanB(std::string name);                   // ← Pas de weapon
    void setWeapon(Weapon& weapon);
    void attack();
};
```

---

## 🔧 **Erreurs dans ton code actuel**

### **1. Héritage incorrect :**
```cpp
class HumanA : private Weapon  // ← ERREUR ! Pas d'héritage ici
```
**Correction :** HumanA **CONTIENT** une Weapon, ne **HÉRITE** pas de Weapon

### **2. Référence mal initialisée :**
```cpp
std::string &club = Type;  // ← ERREUR ! Type est privé dans Weapon
```
**Correction :** Référence vers un objet Weapon, pas vers son attribut

### **3. Type de retour manquant :**
```cpp
attack();  // ← ERREUR ! Manque "void"
```

---

## 🎯 **Structure correcte**

### **Weapon.hpp**
```cpp
class Weapon {
private:
    std::string type;

public:
    Weapon(std::string type);
    const std::string& getType() const;  // ← Référence constante
    void setType(std::string newType);
};
```

### **HumanA.hpp**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;        // ← Référence vers Weapon

public:
    HumanA(std::string name, Weapon& weapon);
    void attack();
};
```

### **HumanB.hpp**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;        // ← Pointeur vers Weapon

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};
```

---

## 🚀 **Plan d'Action**

1. **Réponds aux questions** ci-dessus
2. **Comprends la différence** référence vs pointeur ici
3. **Corrige tes headers** avec la bonne structure
4. **Implémente étape par étape** avec moi
5. **Teste** avec le code fourni

---

**Dis-moi : comprends-tu pourquoi HumanA utilise une référence et HumanB un pointeur ?** 🤔 