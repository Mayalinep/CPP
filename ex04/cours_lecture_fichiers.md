# Cours Complet : Lecture de Fichiers en C++

## Table des matières
1. [Introduction aux flux de fichiers](#introduction)
2. [Ouverture et vérification d'un fichier](#ouverture)
3. [Méthodes de lecture](#methodes)
4. [Gestion des erreurs](#erreurs)
5. [Bonnes pratiques](#bonnes-pratiques)
6. [Exemples pratiques](#exemples)

---

## 1. Introduction aux flux de fichiers {#introduction}

En C++, la lecture de fichiers se fait principalement via les flux (`streams`). Les classes principales sont :

- `std::ifstream` : pour lire des fichiers (input file stream)
- `std::ofstream` : pour écrire dans des fichiers (output file stream)
- `std::fstream` : pour lire ET écrire (file stream)

### Headers nécessaires
```cpp
#include <iostream>  // Pour std::cout, std::cerr
#include <fstream>   // Pour std::ifstream, std::ofstream
#include <string>    // Pour std::string
```

---

## 2. Ouverture et vérification d'un fichier {#ouverture}

### Méthode 1 : Constructeur
```cpp
std::ifstream file("nom_fichier.txt");
```

### Méthode 2 : Méthode open()
```cpp
std::ifstream file;
file.open("nom_fichier.txt");
```

### Vérification d'ouverture
```cpp
// Méthode 1 : is_open()
if (!file.is_open()) {
    std::cerr << "Erreur : impossible d'ouvrir le fichier" << std::endl;
    return 1;
}

// Méthode 2 : opérateur !
if (!file) {
    std::cerr << "Erreur : impossible d'ouvrir le fichier" << std::endl;
    return 1;
}
```

---

## 3. Méthodes de lecture {#methodes}

### 3.1 Lecture ligne par ligne avec `std::getline()`

**Avantages :**
- Efficace en mémoire pour les gros fichiers
- Permet de traiter chaque ligne individuellement
- Contrôle fin sur le processus

**Inconvénients :**
- Plus de code à écrire
- Peut être plus lent pour de petits fichiers

```cpp
std::string line;
std::string content;

while (std::getline(file, line)) {
    content += line + "\n";  // Reconstituer le contenu complet
}
```

### 3.2 Lecture complète avec `std::istreambuf_iterator`

**Avantages :**
- Une seule ligne de code
- Très efficace pour lire tout le fichier
- Préserve tous les caractères (y compris les fins de ligne)

**Inconvénients :**
- Charge tout en mémoire d'un coup
- Peut être problématique pour de très gros fichiers

```cpp
std::string content((std::istreambuf_iterator<char>(file)), 
                    std::istreambuf_iterator<char>());
```

**Explication détaillée :**
- `std::istreambuf_iterator<char>(file)` : itérateur qui pointe sur le début du fichier
- `std::istreambuf_iterator<char>()` : itérateur "fin" (par défaut)
- Les parenthèses autour du premier paramètre évitent le "most vexing parse"

### 3.3 Lecture avec `std::ostringstream`

```cpp
std::ostringstream buffer;
buffer << file.rdbuf();
std::string content = buffer.str();
```

### 3.4 Lecture caractère par caractère

```cpp
char c;
std::string content;
while (file.get(c)) {
    content += c;
}
```

---

## 4. Gestion des erreurs {#erreurs}

### États d'un flux
```cpp
// Vérifier différents états
if (file.eof())    // Fin de fichier atteinte
if (file.fail())   // Erreur de lecture
if (file.bad())    // Erreur grave
if (file.good())   // Tout va bien
```

### Exemple complet avec gestion d'erreur
```cpp
std::ifstream file("fichier.txt");
if (!file.is_open()) {
    std::cerr << "Erreur : impossible d'ouvrir le fichier" << std::endl;
    return 1;
}

std::string content((std::istreambuf_iterator<char>(file)), 
                    std::istreambuf_iterator<char>());

if (file.bad()) {
    std::cerr << "Erreur de lecture du fichier" << std::endl;
    return 1;
}
```

---

## 5. Bonnes pratiques {#bonnes-pratiques}

### 5.1 Fermeture des fichiers
```cpp
file.close();  // Explicite (optionnel si destructeur appelé)
```

### 5.2 RAII (Resource Acquisition Is Initialization)
```cpp
{
    std::ifstream file("fichier.txt");
    // Utilisation du fichier
    // Le fichier se ferme automatiquement à la fin du scope
}
```

### 5.3 Gestion des chemins
```cpp
#include <filesystem>  // C++17
namespace fs = std::filesystem;

if (fs::exists("fichier.txt")) {
    // Le fichier existe
}
```

---

## 6. Exemples pratiques {#exemples}

### Exemple 1 : Lecture ligne par ligne
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("fichier.txt");
    if (!file.is_open()) {
        std::cerr << "Erreur d'ouverture" << std::endl;
        return 1;
    }
    
    std::string line;
    std::string content;
    
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    
    std::cout << "Contenu lu :\n" << content << std::endl;
    return 0;
}
```

### Exemple 2 : Lecture complète
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("fichier.txt");
    if (!file.is_open()) {
        std::cerr << "Erreur d'ouverture" << std::endl;
        return 1;
    }
    
    std::string content((std::istreambuf_iterator<char>(file)), 
                        std::istreambuf_iterator<char>());
    
    std::cout << "Contenu lu :\n" << content << std::endl;
    return 0;
}
```

### Exemple 3 : Fonction réutilisable
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <optional>

std::optional<std::string> lire_fichier(const std::string& nom_fichier) {
    std::ifstream file(nom_fichier);
    if (!file.is_open()) {
        return std::nullopt;
    }
    
    std::string content((std::istreambuf_iterator<char>(file)), 
                        std::istreambuf_iterator<char>());
    
    return content;
}

int main() {
    auto contenu = lire_fichier("fichier.txt");
    if (contenu.has_value()) {
        std::cout << "Contenu : " << contenu.value() << std::endl;
    } else {
        std::cerr << "Impossible de lire le fichier" << std::endl;
    }
    return 0;
}
```

---

## 7. Application à votre projet

Dans votre code `ex04/main.cpp`, vous devez :

1. **Lire le fichier** avec une des méthodes ci-dessus
2. **Remplacer** toutes les occurrences de `str1` par `str2`
3. **Écrire** le résultat dans le fichier de sortie

### Indices pour vous aider :

**Pour la lecture :**
- Choisissez entre `std::getline()` (ligne par ligne) ou `std::istreambuf_iterator` (tout d'un coup)
- Pensez à la taille de vos fichiers de test

**Pour le remplacement :**
- La méthode `std::string::find()` permet de chercher une sous-chaîne
- La méthode `std::string::replace()` permet de remplacer une partie
- Attention aux cas où `str1` et `str2` ont des tailles différentes !
- Il faut chercher TOUTES les occurrences, pas juste la première

**Pour l'écriture :**
- Un simple `out_file << contenu_modifie` suffit

### Questions à se poser :
- Que se passe-t-il si `str1` n'existe pas dans le fichier ?
- Que se passe-t-il si `str1` est une partie de `str2` ?
- Comment éviter les remplacements en boucle infinie ?

---

## 8. Points clés à retenir

1. **Toujours vérifier** si le fichier s'ouvre correctement
2. **Choisir la méthode** selon le contexte (taille du fichier, traitement nécessaire)
3. **Gérer les erreurs** appropriément
4. **Utiliser RAII** pour la gestion automatique des ressources
5. **Tester avec différents types de fichiers** (vides, très grands, avec caractères spéciaux)

---

*Ce cours couvre les aspects essentiels de la lecture de fichiers en C++. N'hésite pas à expérimenter avec ces différentes méthodes pour bien comprendre leurs avantages et inconvénients !* 