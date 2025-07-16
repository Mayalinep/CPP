# Cours Complet : Manipulations de std::string en C++

## Table des matières
1. [Introduction](#introduction)
2. [Méthodes de recherche](#recherche)
3. [Méthodes d'insertion](#insertion)
4. [Méthodes de suppression](#suppression)
5. [Méthodes de remplacement](#remplacement)
6. [Méthodes d'extraction](#extraction)
7. [Méthodes de modification](#modification)
8. [Comparaison et tri](#comparaison)
9. [Exemples pratiques](#exemples)
10. [Pièges courants](#pieges)

---

## 1. Introduction {#introduction}

`std::string` est une classe très riche en C++ qui offre de nombreuses méthodes pour manipuler le texte. Voici les plus importantes à connaître.

### Headers nécessaires
```cpp
#include <string>    // Pour std::string
#include <iostream>  // Pour les exemples
```

### Terminologie importante
- **Position** : index du caractère (commence à 0)
- **Longueur** : nombre de caractères
- **std::string::npos** : valeur spéciale qui signifie "non trouvé"

---

## 2. Méthodes de recherche {#recherche}

### 2.1 `find()` - Recherche vers l'avant
```cpp
std::string text = "Hello world Hello";
std::size_t pos = text.find("Hello");        // Retourne 0
std::size_t pos2 = text.find("Hello", 1);    // Retourne 12 (commence à partir de l'index 1)
std::size_t pos3 = text.find("xyz");         // Retourne std::string::npos
```

### 2.2 `rfind()` - Recherche vers l'arrière
```cpp
std::string text = "Hello world Hello";
std::size_t pos = text.rfind("Hello");       // Retourne 12 (dernière occurrence)
```

### 2.3 `find_first_of()` - Premier caractère d'un ensemble
```cpp
std::string text = "Hello world";
std::size_t pos = text.find_first_of("aeiou");  // Retourne 1 (le 'e')
```

### 2.4 `find_last_of()` - Dernier caractère d'un ensemble
```cpp
std::string text = "Hello world";
std::size_t pos = text.find_last_of("aeiou");   // Retourne 7 (le 'o' de "world")
```

### 2.5 Vérifier si une recherche a réussi
```cpp
std::string text = "Hello world";
std::size_t pos = text.find("xyz");
if (pos != std::string::npos) {
    std::cout << "Trouvé à la position " << pos << std::endl;
} else {
    std::cout << "Non trouvé" << std::endl;
}
```

---

## 3. Méthodes d'insertion {#insertion}

### 3.1 `insert()` - Insérer à une position
```cpp
std::string text = "Hello world";
text.insert(6, "beautiful ");     // "Hello beautiful world"
text.insert(0, "Hey! ");          // "Hey! Hello beautiful world"
```

### 3.2 `insert()` avec itérateurs (C++98)
```cpp
std::string text = "Hello world";
text.insert(text.begin() + 6, '!');  // "Hello !world"
```

### 3.3 `push_back()` - Ajouter un caractère à la fin
```cpp
std::string text = "Hello";
text.push_back('!');               // "Hello!"
```

---

## 4. Méthodes de suppression {#suppression}

### 4.1 `erase()` - Supprimer par position et longueur
```cpp
std::string text = "Hello beautiful world";
text.erase(6, 10);                 // "Hello world" (supprime "beautiful ")
text.erase(5);                     // "Hello" (supprime tout après l'index 5)
```

### 4.2 `erase()` avec itérateurs
```cpp
std::string text = "Hello world";
text.erase(text.begin() + 5);      // "Helloworld" (supprime l'espace)
```

### 4.3 `clear()` - Vider complètement
```cpp
std::string text = "Hello world";
text.clear();                      // text devient ""
```

---

## 5. Méthodes de remplacement {#remplacement}

### 5.1 `replace()` - Remplacer par position
```cpp
std::string text = "Hello world";
text.replace(6, 5, "universe");    // "Hello universe" (remplace "world")
```

### 5.2 `replace()` avec recherche manuelle
```cpp
std::string text = "Hello world Hello";
std::size_t pos = 0;
while ((pos = text.find("Hello", pos)) != std::string::npos) {
    text.replace(pos, 5, "Hi");     // Remplace "Hello" par "Hi"
    pos += 2;                       // Avance de la taille de "Hi"
}
// Résultat : "Hi world Hi"
```

---

## 6. Méthodes d'extraction {#extraction}

### 6.1 `substr()` - Extraire une sous-chaîne
```cpp
std::string text = "Hello world";
std::string part1 = text.substr(0, 5);    // "Hello"
std::string part2 = text.substr(6);       // "world"
std::string part3 = text.substr(6, 2);    // "wo"
```

### 6.2 Utilisation avec `find()`
```cpp
std::string text = "nom=valeur";
std::size_t pos = text.find('=');
if (pos != std::string::npos) {
    std::string nom = text.substr(0, pos);        // "nom"
    std::string valeur = text.substr(pos + 1);    // "valeur"
}
```

---

## 7. Méthodes de modification {#modification}

### 7.1 `append()` - Ajouter à la fin
```cpp
std::string text = "Hello";
text.append(" world");             // "Hello world"
text.append(3, '!');               // "Hello world!!!"
```

### 7.2 `+=` operator - Concaténation
```cpp
std::string text = "Hello";
text += " world";                  // "Hello world"
text += '!';                       // "Hello world!"
```

### 7.3 `assign()` - Remplacer tout le contenu
```cpp
std::string text = "Hello";
text.assign("Bonjour");            // "Bonjour"
text.assign(5, 'X');               // "XXXXX"
```

---

## 8. Comparaison et tri {#comparaison}

### 8.1 `compare()` - Comparaison lexicographique
```cpp
std::string str1 = "apple";
std::string str2 = "banana";
int result = str1.compare(str2);   // < 0 (str1 < str2)
```

### 8.2 Opérateurs de comparaison
```cpp
std::string str1 = "apple";
std::string str2 = "banana";
bool equal = (str1 == str2);       // false
bool less = (str1 < str2);         // true
```

---

## 9. Exemples pratiques {#exemples}

### 9.1 Remplacer toutes les occurrences (méthode 1)
```cpp
std::string remplacer_tout(std::string text, const std::string& ancien, const std::string& nouveau) {
    std::size_t pos = 0;
    while ((pos = text.find(ancien, pos)) != std::string::npos) {
        text.replace(pos, ancien.length(), nouveau);
        pos += nouveau.length();
    }
    return text;
}
```

### 9.2 Remplacer toutes les occurrences (méthode 2)
```cpp
std::string remplacer_tout_v2(std::string text, const std::string& ancien, const std::string& nouveau) {
    std::size_t pos = 0;
    while ((pos = text.find(ancien, pos)) != std::string::npos) {
        text.erase(pos, ancien.length());
        text.insert(pos, nouveau);
        pos += nouveau.length();
    }
    return text;
}
```

### 9.3 Supprimer les espaces en début et fin
```cpp
std::string trim(const std::string& text) {
    std::size_t debut = text.find_first_not_of(" \t\n\r");
    if (debut == std::string::npos) return "";
    
    std::size_t fin = text.find_last_not_of(" \t\n\r");
    return text.substr(debut, fin - debut + 1);
}
```

### 9.4 Séparer une chaîne
```cpp
std::vector<std::string> split(const std::string& text, char delimiteur) {
    std::vector<std::string> resultat;
    std::size_t debut = 0;
    std::size_t fin = text.find(delimiteur);
    
    while (fin != std::string::npos) {
        resultat.push_back(text.substr(debut, fin - debut));
        debut = fin + 1;
        fin = text.find(delimiteur, debut);
    }
    resultat.push_back(text.substr(debut));
    
    return resultat;
}
```

---

## 10. Pièges courants {#pieges}

### 10.1 ❌ Oublier de vérifier std::string::npos
```cpp
// ❌ DANGEREUX
std::string text = "Hello world";
std::size_t pos = text.find("xyz");
text.erase(pos, 3);  // CRASH si "xyz" n'existe pas !

// ✅ CORRECT
std::size_t pos = text.find("xyz");
if (pos != std::string::npos) {
    text.erase(pos, 3);
}
```

### 10.2 ❌ Boucle infinie dans les remplacements
```cpp
// ❌ BOUCLE INFINIE si nouveau contient ancien
std::string text = "hello";
std::size_t pos = 0;
while ((pos = text.find("l", pos)) != std::string::npos) {
    text.replace(pos, 1, "ll");  // "l" devient "ll" !
    pos += 1;  // ❌ Pas assez ! On retombe sur le "l" qu'on vient de créer
}

// ✅ CORRECT
while ((pos = text.find("l", pos)) != std::string::npos) {
    text.replace(pos, 1, "ll");
    pos += 2;  // ✅ Avance de la taille du remplacement
}
```

### 10.3 ❌ Confusion entre position et longueur
```cpp
std::string text = "Hello world";
// ❌ ERREUR : substr prend (position, longueur) pas (début, fin)
std::string wrong = text.substr(6, 11);  // Pas ce qu'on veut !

// ✅ CORRECT
std::string right = text.substr(6, 5);   // "world"
// ou
std::string right2 = text.substr(6);     // "world" (jusqu'à la fin)
```

### 10.4 ❌ Modification pendant l'itération
```cpp
// ❌ PROBLÉMATIQUE
std::string text = "aaa";
for (std::size_t i = 0; i < text.length(); ++i) {
    if (text[i] == 'a') {
        text.insert(i, "b");  // Change la taille !
    }
}

// ✅ MIEUX : utiliser les méthodes appropriées
std::size_t pos = 0;
while ((pos = text.find("a", pos)) != std::string::npos) {
    text.replace(pos, 1, "b");
    pos += 1;
}
```

---

## 11. Résumé des méthodes importantes

| Méthode | Utilisation | Exemple |
|---------|-------------|---------|
| `find()` | Chercher une sous-chaîne | `pos = text.find("hello")` |
| `substr()` | Extraire une partie | `part = text.substr(0, 5)` |
| `replace()` | Remplacer une partie | `text.replace(0, 5, "hi")` |
| `insert()` | Insérer du texte | `text.insert(5, "new ")` |
| `erase()` | Supprimer une partie | `text.erase(5, 3)` |
| `append()` | Ajouter à la fin | `text.append(" end")` |
| `length()` | Obtenir la taille | `size_t len = text.length()` |
| `empty()` | Vérifier si vide | `if (text.empty())` |
| `clear()` | Vider le string | `text.clear()` |

---

*Ce cours couvre les manipulations essentielles de std::string. Pratique avec des exemples concrets pour bien maîtriser ces outils puissants !* 