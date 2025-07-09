# 🧟‍♂️ Cours Complet - Exercice 01 : Zombie Horde

## 🎯 **Objectif de l'Exercice**
Créer une **horde de zombies** (tableau de zombies) avec une seule allocation mémoire.

**Ce que tu vas apprendre :**
- Constructeur par défaut
- Allocation de tableaux d'objets
- Différence `delete` vs `delete[]`
- Initialisation post-création
- Gestion mémoire avancée

---

## 🔥 **Nouvelles Notions Importantes**

### 1. **Constructeur par Défaut**
```cpp
class Zombie {
public:
    Zombie();                    // ← Constructeur par défaut
    Zombie(std::string name);    // ← Constructeur avec paramètres
};
```

**Pourquoi c'est important ?**
- Quand tu fais `new Zombie[N]`, C++ appelle le constructeur par défaut pour chaque zombie
- Si tu n'en as pas, ça ne compile pas !

### 2. **Allocation de Tableaux**
```cpp
// Allocation d'un seul objet
Zombie* zombie = new Zombie();

// Allocation d'un tableau d'objets
Zombie* zombies = new Zombie[5];  // 5 zombies créés avec constructeur par défaut
```

### 3. **Libération Mémoire : delete vs delete[]**
```cpp
// Pour un seul objet
Zombie* zombie = new Zombie();
delete zombie;

// Pour un tableau
Zombie* zombies = new Zombie[5];
delete[] zombies;  // ← OBLIGATOIRE le [] pour les tableaux !
```

**⚠️ TRÈS IMPORTANT :**
- `new` → `delete`
- `new[]` → `delete[]`
- **Mélanger les deux = comportement indéfini !**

### 4. **Initialisation en Deux Étapes**
```cpp
// Étape 1 : Créer les objets (constructeur par défaut)
Zombie* zombies = new Zombie[N];

// Étape 2 : Les initialiser (setter)
for (int i = 0; i < N; i++) {
    zombies[i].setName("Bob");
}
```

**Pourquoi cette approche ?**
- Les tableaux d'objets nécessitent un constructeur par défaut
- On peut ensuite personnaliser chaque objet individuellement

---

## 🎯 **Analyse de Tes Erreurs**

### ❌ **Erreur 1 : Pas de constructeur par défaut**
```cpp
// Ton code actuel
Zombie* zombie = new Zombie[N];  // ← ERREUR !
```

**Problème** : Tu as seulement `Zombie(int N, std::string name)` mais pas `Zombie()`.

**Solutions possibles :**
1. Ajouter un constructeur par défaut
2. Utiliser une approche différente

### ❌ **Erreur 2 : Confusion dans le main**
```cpp
// Ton code actuel
Zombie* zombieHorde = Zombie(4, "Bob");  // ← ERREUR !
```

**Problème** : Tu crées un objet `Zombie` au lieu d'appeler la fonction `zombieHorde()`.

**Correction :**
```cpp
Zombie* horde = zombieHorde(4, "Bob");  // ← Appel de fonction
```

---

## 🛠️ **Solution Recommandée**

### **Approche 1 : Constructeur par défaut + setName**

#### **Zombie.class.hpp**
```cpp
class Zombie {
private:
    std::string name;

public:
    Zombie();                    // ← Constructeur par défaut
    Zombie(std::string name);    // ← Constructeur avec nom
    void setName(std::string name);
    void announce();
    ~Zombie();
};
```

#### **Zombie.cpp**
```cpp
// Constructeur par défaut
Zombie::Zombie() {
    this->name = "";
}

// Constructeur avec nom
Zombie::Zombie(std::string name) {
    this->name = name;
}

// Setter pour le nom
void Zombie::setName(std::string name) {
    this->name = name;
}

// Announce avec le nom
void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructeur avec nom
Zombie::~Zombie() {
    std::cout << this->name << " détruit!" << std::endl;
}
```

#### **zombieHorde.cpp**
```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];  // ← Maintenant ça marche !
    
    for (int i = 0; i < N; i++) {
        zombies[i].setName(name);
    }
    
    return zombies;
}
```

#### **main.cpp**
```cpp
int main() {
    int N = 4;
    Zombie* horde = zombieHorde(N, "Bob");  // ← Appel de fonction
    
    // Test chaque zombie
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    delete[] horde;  // ← IMPORTANT : delete[] pour tableau !
    return 0;
}
```

---

## 🎯 **Concepts Avancés**

### **Pourquoi cette approche ?**
1. **Flexibilité** : On peut créer des zombies vides puis les nommer
2. **Compatibilité** : Marche avec les tableaux
3. **Clarté** : Séparation création/initialisation

### **Alternative : Constructeur avec paramètres par défaut**
```cpp
class Zombie {
public:
    Zombie(std::string name = "");  // ← Paramètre par défaut
};
```

---

## 🔍 **Points Importants**

### **1. Gestion Mémoire**
```cpp
Zombie* horde = zombieHorde(5, "Bob");
// ... utilisation ...
delete[] horde;  // ← Ne pas oublier !
```

### **2. Accès aux Éléments**
```cpp
horde[0].announce();  // Premier zombie
horde[1].announce();  // Deuxième zombie
// ou
for (int i = 0; i < N; i++) {
    horde[i].announce();
}
```

### **3. Différence avec l'Ex00**
- **Ex00** : Un zombie à la fois (`new Zombie`)
- **Ex01** : Plusieurs zombies d'un coup (`new Zombie[N]`)

---

## 🎯 **Exercices de Compréhension**

### **Question 1 : Que fait ce code ?**
```cpp
Zombie* zombies = new Zombie[3];
zombies[0].setName("Alice");
zombies[1].setName("Bob");
zombies[2].setName("Charlie");
```
**Réponse :** Crée 3 zombies avec constructeur par défaut, puis leur donne des noms différents.

### **Question 2 : Erreur à éviter**
```cpp
Zombie* zombies = new Zombie[5];
// ... utilisation ...
delete zombies;  // ← ERREUR ! Que manque-t-il ?
```
**Réponse :** Il manque les `[]` ! Ça devrait être `delete[] zombies;`

### **Question 3 : Prédiction**
```cpp
Zombie* horde = zombieHorde(2, "Test");
horde[0].announce();
horde[1].announce();
delete[] horde;
```
**Que va s'afficher ?**
```
Test: BraiiiiiiinnnzzzZ...
Test: BraiiiiiiinnnzzzZ...
Test détruit!
Test détruit!
```

### **Question 4 : Analyse d'erreur**
**Pourquoi ce code ne compile pas ?**
```cpp
class Zombie {
public:
    Zombie(std::string name);  // Seulement constructeur avec paramètre
};

Zombie* zombies = new Zombie[5];  // ← ERREUR !
```
**Réponse :** `new Zombie[5]` cherche un constructeur par défaut `Zombie()` qui n'existe pas.

---

## 🏆 **Résumé des Nouvelles Notions**

1. **Constructeur par défaut** : Nécessaire pour `new Type[N]`
2. **Allocation tableau** : `new Type[N]` crée N objets
3. **Libération tableau** : `delete[]` obligatoire (pas `delete`)
4. **Initialisation post-création** : Utiliser des setters
5. **Accès indexé** : `array[i]` pour accéder aux éléments

---

## 🎯 **Checklist de Maîtrise**

**Coche quand tu te sens à l'aise :**

- [x] Je comprends pourquoi il faut un constructeur par défaut
- [x] Je sais la différence entre `delete` et `delete[]`
- [x] Je comprends l'initialisation en deux étapes
- [x] Je sais accéder aux éléments d'un tableau d'objets
- [ ] Je comprends la logique de `zombieHorde()`

---

## 🚀 **Prochaines Étapes**

1. **Lis bien ce cours** pour comprendre les concepts
2. **Analyse tes erreurs** en comparant avec les explications
3. **Corrige ton code** étape par étape
4. **Teste** que ça compile et fonctionne
5. **Passe à l'exercice suivant** quand tu maîtrises !

---

**Tu découvres des concepts importants ! Continue comme ça !** 🎉

---

## 📝 **Notes Personnelles**

*Espace pour tes propres notes et questions :* 