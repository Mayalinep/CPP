# 🧟‍♂️ RAPPEL EXERCICE 00 - BraiiiiiiinnnzzzZ

## 🎯 **Objectifs pédagogiques**
Cet exercice t'introduit aux concepts fondamentaux de la **Programmation Orientée Objet (POO)** en C++:
- Création d'une classe simple
- Constructeur et destructeur 
- Méthodes de classe
- **Allocation mémoire** (stack vs heap)
- Gestion de la mémoire avec `new`/`delete`

---

## 🏗️ **Architecture du projet**

### Structure des fichiers
```
ex00/
├── Zombie.class.hpp    # Déclaration de la classe
├── Zombie.cpp          # Implémentation de la classe  
├── newZombie.cpp       # Fonction d'allocation dynamique
├── randomChump.cpp     # Fonction d'allocation automatique
├── main.cpp           # Point d'entrée du programme
└── Makefile           # Compilation
```

---

## 📋 **Analyse détaillée du code**

### 1. **La classe Zombie** (`Zombie.class.hpp`)

```cpp
class Zombie{
    private:
        std::string name;  // Attribut privé

    public:
        Zombie(std::string name);  // Constructeur
        void announce();           // Méthode publique
        ~Zombie();                // Destructeur
};
```

**Points clés :**
- **Encapsulation** : `name` est privé → protection des données
- **Interface publique** : constructeur, méthode `announce()`, destructeur
- **Prototypes des fonctions** externes déclarés dans le header

### 2. **Implémentation** (`Zombie.cpp`)

```cpp
// Constructeur - initialise l'objet
Zombie::Zombie(std::string name) : name(name) {
    // Liste d'initialisation recommandée (voir guide dédié)
}

// Méthode pour faire parler le zombie
void Zombie::announce(){
    std::cout << name <<" : BraiiiiiiinnnzzzZ..."<< std::endl;
}

// Destructeur - appelé à la destruction
Zombie::~Zombie(){
    std::cout << name << " détruit!" << std::endl;
}
```

**Points clés :**
- **Liste d'initialisation** `: name(name)` est préférée (voir 📄 `GUIDE_LISTES_INITIALISATION.md`)
- Le **destructeur** affiche un message → trace de la destruction
- **Portée** : `Zombie::` indique l'appartenance à la classe

---

## 🧠 **Concepts fondamentaux**

### **Allocation Automatique vs Dynamique**

#### **randomChump()** - Allocation automatique (Stack)
```cpp
void randomChump(std::string name){
    Zombie zombie(name);  // Objet créé sur la pile
    zombie.announce();    
    return;  // Destructeur appelé automatiquement ici
}
```

✅ **Avantages :**
- Gestion automatique de la mémoire
- Destruction automatique en fin de portée
- Plus sûr (pas de fuite mémoire)

❌ **Inconvénients :**  
- Objet détruit à la fin de la fonction
- Impossible de retourner l'objet

#### **newZombie()** - Allocation dynamique (Heap)
```cpp
Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie(name);  // Allocation sur le tas
    return (zombie);  // Retourne le pointeur
}
```

✅ **Avantages :**
- Objet survit à la fonction
- Peut être retourné et utilisé ailleurs
- Contrôle total sur la durée de vie

❌ **Inconvénients :**
- **OBLIGATION** d'appeler `delete` 
- Risque de fuite mémoire
- Plus d'erreurs possibles

### **Usage dans main()**
```cpp
int main(){
    randomChump("Bob");           // Destruction automatique
    Zombie* zombie = newZombie("audrey");  // Allocation dynamique
    zombie->announce();           // Utilisation du pointeur
    delete zombie;                // ⚠️ OBLIGATOIRE !
    return (0);
}
```

---

## 🔍 **Points techniques importants**

### **1. Syntaxe des pointeurs**
```cpp
zombie->announce();  // Équivalent à (*zombie).announce()
```

### **2. Gestion mémoire**
- `new` → allocation sur le **heap**
- `delete` → libération mémoire **OBLIGATOIRE**
- Oubli de `delete` = **fuite mémoire**

### **3. Destructeur**
- Appelé **automatiquement** pour les objets de la pile
- Appelé lors du `delete` pour les objets alloués dynamiquement
- Permet de "voir" quand les objets sont détruits

### **4. Encapsulation**
- Attributs privés → protection des données
- Interface publique → contrôle de l'accès

---

## 🚀 **Ce que tu dois retenir**

### **Règles d'or :**
1. **Tout `new` doit avoir son `delete`** correspondant
2. Les objets sur la **pile** sont plus sûrs
3. Les objets sur le **tas** sont plus flexibles
4. Le **destructeur** trace la destruction des objets
5. `this->` référence l'objet courant
6. **TOUJOURS utiliser la liste d'initialisation** dans les constructeurs ✨

### **Quand utiliser quoi ?**
- **Allocation automatique** : objets temporaires, usage local
- **Allocation dynamique** : objets à retourner, durée de vie flexible

---

## 📚 **Guides complémentaires**
- 📄 **`GUIDE_LISTES_INITIALISATION.md`** → Guide complet sur les listes d'initialisation
- 📄 **`EVALUATION_PROGRESSION.md`** → Critères d'évaluation

---

## **Prochaines étapes :**
Cet exercice pose les bases pour :
- ex01 : Allocation de tableaux d'objets
- ex02 : Pointeurs vs références  
- Concepts plus avancés de la POO

---

## 💡 **Questions de réflexion**
1. Que se passerait-il si on oubliait le `delete` ?
2. Pourquoi le destructeur affiche-t-il un message ?
3. Quelle est la différence entre `.` et `->` ?
4. Pourquoi `name` est-il privé ?
5. Quand utiliser allocation automatique vs dynamique ?

**Bravo pour ton travail ! 🎉 Tu maîtrises maintenant les bases de la POO en C++** 