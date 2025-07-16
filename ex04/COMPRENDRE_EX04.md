# 📝 COMPRENDRE L'EXERCICE 04 - Replace

## 🎯 **BUT DE L'EXERCICE**

Créer un programme qui **remplace** toutes les occurrences d'une string par une autre dans un fichier.

---

## 📋 **CAHIER DES CHARGES**

### **Paramètres d'entrée :**
```bash
./replace <filename> <s1> <s2>
```

- **filename** : nom du fichier à traiter
- **s1** : string à remplacer
- **s2** : string de remplacement

### **Comportement :**
1. Ouvre le fichier `<filename>`
2. Lit tout le contenu
3. Remplace **toutes** les occurrences de `s1` par `s2`
4. Écrit le résultat dans `<filename>.replace`

---

## 🔧 **EXEMPLE CONCRET**

**Fichier original (`test.txt`) :**
```
Hello world!
This is a test.
Hello everyone!
```

**Commande :**
```bash
./replace test.txt "Hello" "Bonjour"
```

**Fichier résultat (`test.txt.replace`) :**
```
Bonjour world!
This is a test.
Bonjour everyone!
```

---

## 🚫 **INTERDICTIONS**

### **❌ Fonctions C interdites :**
```cpp
fopen(), fclose(), fread(), fwrite()  // Manipulation de fichiers C
```

### **❌ Fonction C++ interdite :**
```cpp
std::string::replace()  // Trop facile !
```

### **✅ Autorisé :**
```cpp
std::ifstream, std::ofstream  // Streams C++
std::string::find()           // Chercher une substring
std::string::substr()         // Extraire une partie
std::string::append()         // Ajouter du texte
// ... et toutes les autres fonctions de std::string
```

---

## 🤔 **QUESTIONS À SE POSER**

1. **Comment lire un fichier en C++ ?**
   - `std::ifstream` pour lire
   - `std::ofstream` pour écrire

2. **Comment remplacer sans `replace()` ?**
   - Chercher avec `find()`
   - Extraire les parties avec `substr()`
   - Reconstituer avec les remplacements

3. **Comment gérer les erreurs ?**
   - Fichier inexistant
   - Mauvais nombre de paramètres
   - Permissions insuffisantes

4. **Comment tester ?**
   - Créer différents fichiers de test
   - Tester différents cas (s1 absent, s1 multiple, etc.)

---

## 🧠 **ALGORITHMIE GÉNÉRALE**

```
1. Vérifier les paramètres (3 paramètres ?)
2. Ouvrir le fichier en lecture
3. Lire tout le contenu dans une string
4. Parcourir la string et remplacer s1 par s2
5. Écrire le résultat dans <filename>.replace
6. Gérer les erreurs à chaque étape
```

---

## 💡 **INDICES POUR COMMENCER**

### **Structure générale :**
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    // 1. Vérifier les paramètres
    if (argc != 4) {
        // Erreur
    }
    
    // 2. Récupérer les paramètres
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    // 3. Ouvrir et lire le fichier
    // 4. Remplacer s1 par s2
    // 5. Écrire dans <filename>.replace
    
    return 0;
}
```

---

## 🎯 **CONCEPTS CLÉS À MAÎTRISER**

1. **Streams C++** (`ifstream`, `ofstream`)
2. **Manipulation de strings** (`find`, `substr`)
3. **Gestion d'erreurs** (fichier inexistant, etc.)
4. **Paramètres en ligne de commande** (`argc`, `argv`)

---

## 📝 **TESTS À CRÉER**

1. **Test normal** : remplacer "Hello" par "Bonjour"
2. **Test multiple** : plusieurs occurrences de s1
3. **Test vide** : s1 n'existe pas dans le fichier
4. **Test erreur** : fichier inexistant
5. **Test edge case** : s1 vide, s2 vide

---

## 🚀 **POUR COMMENCER**

1. **Crée le dossier ex04**
2. **Commence par la structure de base** (vérif paramètres)
3. **Ajoute la lecture de fichier**
4. **Implémente le remplacement**
5. **Ajoute la gestion d'erreurs**
6. **Crée tes tests**

---

## 🤝 **COMMENT JE PEUX T'AIDER**

- Explications sur les streams C++
- Algorithme de remplacement sans `replace()`
- Gestion d'erreurs
- Tests et validation

Tu veux qu'on commence par quelle partie ? 😊 