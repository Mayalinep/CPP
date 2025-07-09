# 📚 Cours C++ - Scope et Durée de Vie des Objets

## 🎯 Objectif
Comprendre **quand** et **comment** les objets sont créés et détruits en C++.

---

## 🔍 Qu'est-ce que le Scope ?

### Définition
Le **scope** (portée) est la **zone du code** où une variable ou un objet existe et peut être utilisé.

### Exemple visuel
```cpp
int main() {
    // Début du scope du main
    
    {
        // Début d'un nouveau scope
        int nombre = 42;
        std::cout << nombre << std::endl;  // ✅ OK, nombre existe ici
    }
    // Fin du scope - nombre est détruit ici !
    
    // std::cout << nombre << std::endl;  // ❌ ERREUR, nombre n'existe plus
    
    return 0;
}
// Fin du scope du main
```

---

## ⏰ Durée de Vie des Objets Stack

### Règle fondamentale
Un objet créé sur le **stack** vit **uniquement** dans son scope.

### Exemple avec randomChump
```cpp
void randomChump(std::string name) {
    // Début du scope de la fonction
    
    Zombie zombie(name);  // ✅ Zombie créé ici
    zombie.announce();    // ✅ Zombie utilisé ici
    
    // Fin du scope de la fonction
    // 🔥 DESTRUCTEUR APPELÉ ICI AUTOMATIQUEMENT
}

int main() {
    std::cout << "Avant randomChump" << std::endl;
    randomChump("Bob");  // Bob est créé ET détruit dans cette ligne
    std::cout << "Après randomChump" << std::endl;
    
    return 0;
}
```

### Sortie attendue
```
Avant randomChump
Bob: BraiiiiiiinnnzzzZ...
Bob détruit!
Après randomChump
```

**Point clé :** Le destructeur s'exécute **immédiatement** après l'appel à randomChump, pas à la fin du main !

---

## 🏗️ Durée de Vie des Objets Heap

### Règle fondamentale
Un objet créé sur le **heap** vit **jusqu'à ce qu'on le détruise manuellement**.

### Exemple avec newZombie
```cpp
Zombie* newZombie(std::string name) {
    // Début du scope de la fonction
    
    Zombie* zombie = new Zombie(name);  // ✅ Zombie créé sur le heap
    
    return zombie;  // ✅ On retourne l'adresse
    
    // Fin du scope de la fonction
    // 🔥 MAIS le zombie n'est PAS détruit !
}

int main() {
    std::cout << "Avant newZombie" << std::endl;
    Zombie* zombie = newZombie("Alice");  // Alice créée
    std::cout << "Après newZombie" << std::endl;
    
    zombie->announce();  // ✅ Alice existe encore
    
    delete zombie;  // 🔥 DESTRUCTEUR APPELÉ ICI
    std::cout << "Après delete" << std::endl;
    
    return 0;
}
```

### Sortie attendue
```
Avant newZombie
Après newZombie
Alice: BraiiiiiiinnnzzzZ...
Alice détruit!
Après delete
```

---

## 🧠 Comparaison Visuelle

### Stack (randomChump)
```
Fonction randomChump {
    Zombie zombie("Bob");  ← Création
    zombie.announce();
}  ← Destruction AUTOMATIQUE ici
```

### Heap (newZombie)
```
Fonction newZombie {
    Zombie* zombie = new Zombie("Alice");  ← Création
    return zombie;
}  ← Zombie survit à la fonction

// Plus tard dans le code...
delete zombie;  ← Destruction MANUELLE ici
```

---

## 🎯 Pourquoi C'est Important ?

### 1. **Prédictibilité**
- **Stack** : Destruction automatique et prévisible
- **Heap** : Destruction manuelle, risque d'oubli

### 2. **Performance**
- **Stack** : Plus rapide, pas de fragmentation
- **Heap** : Plus lent, mais plus flexible

### 3. **Sécurité**
- **Stack** : Pas de fuites mémoire possibles
- **Heap** : Risque de fuites si on oublie `delete`

---

## 🔧 Exercice Pratique

### Prédis la sortie
```cpp
void test() {
    std::cout << "1. Début test" << std::endl;
    
    {
        Zombie zombie1("Stack1");
        std::cout << "2. Zombie1 créé" << std::endl;
    }
    std::cout << "3. Après scope zombie1" << std::endl;
    
    Zombie* zombie2 = new Zombie("Heap1");
    std::cout << "4. Zombie2 créé" << std::endl;
    
    delete zombie2;
    std::cout << "5. Après delete zombie2" << std::endl;
}
```

### Réponse
```
1. Début test
2. Zombie1 créé
Stack1 détruit!
3. Après scope zombie1
4. Zombie2 créé
Heap1 détruit!
5. Après delete zombie2
```

---

## 🎯 Points Clés à Retenir

1. **Stack** : Destruction automatique à la fin du scope
2. **Heap** : Destruction manuelle avec `delete`
3. Le **scope** détermine la durée de vie des objets stack
4. Les objets heap **survivent** à leur scope de création
5. **Toujours** appeler `delete` pour les objets créés avec `new`

---

*Maintenant tu comprends pourquoi le destructeur de randomChump s'affiche immédiatement !* 