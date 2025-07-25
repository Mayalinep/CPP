# Cours : Switch Case en C++

## 📚 Concept Fondamental

Le `switch case` est une structure de contrôle qui permet d'exécuter différentes actions selon la valeur d'une expression. C'est une alternative élégante aux longues chaînes de `if/else if/else`.

## 🔢 Syntaxe de Base

```cpp
switch (expression) {
    case valeur1:
        // Code à exécuter si expression == valeur1
        break;
    case valeur2:
        // Code à exécuter si expression == valeur2
        break;
    default:
        // Code à exécuter si aucune correspondance
        break;
}
```

## 🎯 Types Compatibles

Le `switch` fonctionne avec :
- `int`, `char`, `short`, `long`
- `enum` et `enum class`
- **PAS** avec `string`, `float`, `double`

## 🔄 Convertir String → Nombre pour Switch

### 1. Technique du Tableau de Recherche

```cpp
#include <iostream>
#include <string>

class StringToNumber {
public:
    static int convertir(const std::string& mot) {
        std::string mots[] = {"rouge", "vert", "bleu", "jaune"};
        
        for (int i = 0; i < 4; i++) {
            if (mots[i] == mot) {
                return i;
            }
        }
        return -1; // Mot non trouvé
    }
    
    static void traiterCouleur(const std::string& couleur) {
        int index = convertir(couleur);
        
        switch (index) {
            case 0: // "rouge"
                std::cout << "Couleur chaude" << std::endl;
                break;
            case 1: // "vert"
                std::cout << "Couleur de la nature" << std::endl;
                break;
            case 2: // "bleu"
                std::cout << "Couleur froide" << std::endl;
                break;
            case 3: // "jaune"
                std::cout << "Couleur du soleil" << std::endl;
                break;
            default:
                std::cout << "Couleur inconnue" << std::endl;
                break;
        }
    }
};
```

### 2. Technique avec Map (C++11)

```cpp
#include <iostream>
#include <string>
#include <map>

class StringToNumberMap {
private:
    static std::map<std::string, int> creerMap() {
        std::map<std::string, int> mapping;
        mapping["rouge"] = 0;
        mapping["vert"] = 1;
        mapping["bleu"] = 2;
        mapping["jaune"] = 3;
        return mapping;
    }

public:
    static void traiterCouleur(const std::string& couleur) {
        static std::map<std::string, int> mapping = creerMap();
        
        auto it = mapping.find(couleur);
        int index = (it != mapping.end()) ? it->second : -1;
        
        switch (index) {
            case 0:
                std::cout << "Couleur chaude" << std::endl;
                break;
            case 1:
                std::cout << "Couleur de la nature" << std::endl;
                break;
            case 2:
                std::cout << "Couleur froide" << std::endl;
                break;
            case 3:
                std::cout << "Couleur du soleil" << std::endl;
                break;
            default:
                std::cout << "Couleur inconnue" << std::endl;
                break;
        }
    }
};
```

### 3. Technique avec Enum et Fonction de Conversion

```cpp
#include <iostream>
#include <string>

enum CouleurEnum {
    ROUGE = 0,
    VERT = 1,
    BLEU = 2,
    JAUNE = 3,
    COULEUR_INCONNUE = -1
};

class StringToEnum {
public:
    static CouleurEnum stringToCouleur(const std::string& couleur) {
        if (couleur == "rouge") return ROUGE;
        if (couleur == "vert") return VERT;
        if (couleur == "bleu") return BLEU;
        if (couleur == "jaune") return JAUNE;
        return COULEUR_INCONNUE;
    }
    
    static void traiterCouleur(const std::string& couleur) {
        CouleurEnum enumCouleur = stringToCouleur(couleur);
        
        switch (enumCouleur) {
            case ROUGE:
                std::cout << "Couleur chaude" << std::endl;
                break;
            case VERT:
                std::cout << "Couleur de la nature" << std::endl;
                break;
            case BLEU:
                std::cout << "Couleur froide" << std::endl;
                break;
            case JAUNE:
                std::cout << "Couleur du soleil" << std::endl;
                break;
            case COULEUR_INCONNUE:
            default:
                std::cout << "Couleur inconnue" << std::endl;
                break;
        }
    }
};
```

### 4. Technique avec Hash Simple

```cpp
#include <iostream>
#include <string>

class StringToHash {
public:
    static int hashString(const std::string& str) {
        // Hash simple pour démonstration
        int hash = 0;
        for (char c : str) {
            hash += c;
        }
        return hash % 100; // Limiter à 0-99
    }
    
    static void traiterCommande(const std::string& cmd) {
        int hash = hashString(cmd);
        
        switch (hash) {
            case 19: // Hash de "start" par exemple
                if (cmd == "start") {
                    std::cout << "Démarrage..." << std::endl;
                } else {
                    std::cout << "Collision de hash!" << std::endl;
                }
                break;
            case 32: // Hash de "stop" par exemple
                if (cmd == "stop") {
                    std::cout << "Arrêt..." << std::endl;
                } else {
                    std::cout << "Collision de hash!" << std::endl;
                }
                break;
            default:
                std::cout << "Commande inconnue" << std::endl;
                break;
        }
    }
};
```

### 5. Technique Optimisée avec Tableau Parallèle

```cpp
#include <iostream>
#include <string>

class OptimizedStringSwitch {
private:
    static const int NB_COULEURS = 4;
    static const std::string COULEURS[NB_COULEURS];
    
public:
    static int trouverIndex(const std::string& couleur) {
        for (int i = 0; i < NB_COULEURS; i++) {
            if (COULEURS[i] == couleur) {
                return i;
            }
        }
        return -1;
    }
    
    static void traiterCouleur(const std::string& couleur) {
        int index = trouverIndex(couleur);
        
        switch (index) {
            case 0: // COULEURS[0] = "rouge"
                std::cout << "Couleur chaude" << std::endl;
                break;
            case 1: // COULEURS[1] = "vert"
                std::cout << "Couleur de la nature" << std::endl;
                break;
            case 2: // COULEURS[2] = "bleu"
                std::cout << "Couleur froide" << std::endl;
                break;
            case 3: // COULEURS[3] = "jaune"
                std::cout << "Couleur du soleil" << std::endl;
                break;
            default:
                std::cout << "Couleur inconnue" << std::endl;
                break;
        }
    }
};

// Définition du tableau statique
const std::string OptimizedStringSwitch::COULEURS[NB_COULEURS] = {
    "rouge", "vert", "bleu", "jaune"
};
```

## 📊 Comparaison des Techniques

| Technique | Avantages | Inconvénients |
|-----------|-----------|---------------|
| **Tableau de recherche** | Simple, direct | Recherche linéaire O(n) |
| **Map** | Recherche rapide O(log n) | Plus de mémoire |
| **Enum + fonction** | Type-safe, lisible | Plus de code |
| **Hash** | Très rapide O(1) | Risque de collisions |
| **Tableau parallèle** | Équilibré | Maintenance des 2 tableaux |

## 📊 Exemples par Contexte

### 1. Utilisation Basique avec Entiers

```cpp
#include <iostream>

void afficherJour(int jour) {
    switch (jour) {
        case 1:
            std::cout << "Lundi" << std::endl;
            break;
        case 2:
            std::cout << "Mardi" << std::endl;
            break;
        case 3:
            std::cout << "Mercredi" << std::endl;
            break;
        case 4:
            std::cout << "Jeudi" << std::endl;
            break;
        case 5:
            std::cout << "Vendredi" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Week-end!" << std::endl;
            break;
        default:
            std::cout << "Jour invalide" << std::endl;
            break;
    }
}
```

### 2. Avec des Enums

```cpp
enum Couleur {
    ROUGE,
    VERT,
    BLEU,
    JAUNE
};

void traiterCouleur(Couleur c) {
    switch (c) {
        case ROUGE:
            std::cout << "Couleur chaude" << std::endl;
            break;
        case VERT:
            std::cout << "Couleur de la nature" << std::endl;
            break;
        case BLEU:
            std::cout << "Couleur froide" << std::endl;
            break;
        case JAUNE:
            std::cout << "Couleur du soleil" << std::endl;
            break;
    }
}
```

### 3. Avec des Enum Class (C++11)

```cpp
enum class Vehicule {
    VOITURE,
    MOTO,
    VELO,
    AVION
};

void decrireVehicule(Vehicule v) {
    switch (v) {
        case Vehicule::VOITURE:
            std::cout << "4 roues, carburant" << std::endl;
            break;
        case Vehicule::MOTO:
            std::cout << "2 roues, rapide" << std::endl;
            break;
        case Vehicule::VELO:
            std::cout << "2 roues, écologique" << std::endl;
            break;
        case Vehicule::AVION:
            std::cout << "Vole dans le ciel" << std::endl;
            break;
    }
}
```

### 4. Dans une Classe

```cpp
class Calculatrice {
private:
    double a, b;

public:
    Calculatrice(double x, double y) : a(x), b(y) {}
    
    double calculer(char operation) {
        switch (operation) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b != 0) return a / b;
                else {
                    std::cout << "Division par zéro!" << std::endl;
                    return 0;
                }
            default:
                std::cout << "Opération invalide" << std::endl;
                return 0;
        }
    }
};
```

### 5. Avec des Tableaux pour Optimiser

```cpp
class MenuHandler {
private:
    void option1() { std::cout << "Option 1 sélectionnée" << std::endl; }
    void option2() { std::cout << "Option 2 sélectionnée" << std::endl; }
    void option3() { std::cout << "Option 3 sélectionnée" << std::endl; }

public:
    void traiterMenu(int choix) {
        switch (choix) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            default:
                std::cout << "Choix invalide" << std::endl;
                break;
        }
    }
};
```

### 6. Switch Imbriqués

```cpp
void traiterInput(char categorie, int valeur) {
    switch (categorie) {
        case 'A':
            switch (valeur) {
                case 1:
                    std::cout << "Catégorie A, option 1" << std::endl;
                    break;
                case 2:
                    std::cout << "Catégorie A, option 2" << std::endl;
                    break;
                default:
                    std::cout << "Catégorie A, option inconnue" << std::endl;
                    break;
            }
            break;
        case 'B':
            switch (valeur) {
                case 1:
                    std::cout << "Catégorie B, option 1" << std::endl;
                    break;
                case 2:
                    std::cout << "Catégorie B, option 2" << std::endl;
                    break;
                default:
                    std::cout << "Catégorie B, option inconnue" << std::endl;
                    break;
            }
            break;
        default:
            std::cout << "Catégorie inconnue" << std::endl;
            break;
    }
}
```

## ⚡ Optimisations et Bonnes Pratiques

### 1. Éviter la Duplication de Code

```cpp
// Mauvais : répétition
switch (type) {
    case 1:
        std::cout << "Type: ";
        std::cout << "Premier" << std::endl;
        break;
    case 2:
        std::cout << "Type: ";
        std::cout << "Deuxième" << std::endl;
        break;
}

// Bon : factorisation
std::cout << "Type: ";
switch (type) {
    case 1:
        std::cout << "Premier" << std::endl;
        break;
    case 2:
        std::cout << "Deuxième" << std::endl;
        break;
}
```

### 2. Utilisation des Fall-Through

```cpp
void traiterNote(char note) {
    switch (note) {
        case 'A':
        case 'B':
            std::cout << "Excellente note!" << std::endl;
            break;
        case 'C':
            std::cout << "Note correcte" << std::endl;
            break;
        case 'D':
        case 'F':
            std::cout << "Peut mieux faire" << std::endl;
            break;
        default:
            std::cout << "Note invalide" << std::endl;
            break;
    }
}
```

## 🚫 Limitations du Switch

### 1. Pas de Strings

```cpp
// ❌ Ne compile pas
void traiterString(std::string mot) {
    switch (mot) {  // ERREUR !
        case "bonjour":
            std::cout << "Salut!" << std::endl;
            break;
    }
}

// ✅ Alternative avec conversion
void traiterString(std::string mot) {
    int index = convertirStringEnIndex(mot);
    switch (index) {
        case 0: // "bonjour"
            std::cout << "Salut!" << std::endl;
            break;
        case 1: // "aurevoir"
            std::cout << "À bientôt!" << std::endl;
            break;
        default:
            std::cout << "Mot inconnu" << std::endl;
            break;
    }
}
```

### 2. Pas de Comparaisons Complexes

```cpp
// ❌ Ne fonctionne pas
switch (age) {
    case age > 18:  // ERREUR !
        std::cout << "Adulte" << std::endl;
        break;
}

// ✅ Utiliser if/else
if (age > 18) {
    std::cout << "Adulte" << std::endl;
} else {
    std::cout << "Mineur" << std::endl;
}
```

## 🔄 Switch vs Alternatives

### Comparaison avec If/Else

```cpp
// Switch - Plus rapide pour de nombreuses valeurs
switch (valeur) {
    case 1: /* ... */ break;
    case 2: /* ... */ break;
    case 3: /* ... */ break;
    // ... 20 autres cases
}

// If/Else - Plus flexible mais plus lent
if (valeur == 1) {
    /* ... */
} else if (valeur == 2) {
    /* ... */
} else if (valeur == 3) {
    /* ... */
}
```

### Comparaison avec Pointeurs de Fonctions

```cpp
// Switch - Simple mais limité
class Handler {
public:
    void traiter(int type) {
        switch (type) {
            case 1: methode1(); break;
            case 2: methode2(); break;
            case 3: methode3(); break;
        }
    }
private:
    void methode1() { /* ... */ }
    void methode2() { /* ... */ }
    void methode3() { /* ... */ }
};

// Pointeurs de fonctions - Plus flexible
class Handler {
public:
    void traiter(int type) {
        void (Handler::*fonctions[])() = {
            &Handler::methode1,
            &Handler::methode2,
            &Handler::methode3
        };
        
        if (type >= 1 && type <= 3) {
            (this->*fonctions[type-1])();
        }
    }
private:
    void methode1() { /* ... */ }
    void methode2() { /* ... */ }
    void methode3() { /* ... */ }
};
```

## 📋 Avantages et Inconvénients

### ✅ Avantages
- **Performance** : Optimisé par le compilateur (jump table)
- **Lisibilité** : Structure claire et organisée
- **Maintenabilité** : Facile d'ajouter de nouveaux cas

### ❌ Inconvénients
- **Types limités** : Seulement entiers, char, enum
- **Valeurs constantes** : Pas de variables dans les cases
- **Pas de ranges** : Impossible de faire `case 1...10:`

## 🎯 Quand Utiliser Switch ?

**Utilise switch quand :**
- Tu as plusieurs valeurs discrètes à tester
- Les valeurs sont des constantes connues à la compilation
- Tu veux une performance optimale
- La structure est claire et organisée

**Évite switch quand :**
- Tu travailles avec des strings
- Tu as besoin de comparaisons complexes
- Tu as peu de cas (2-3 maximum)
- Les valeurs ne sont pas constantes

---

**Note** : Le switch case est un outil puissant mais avec des limitations. Comprendre quand l'utiliser te permettra d'écrire du code plus efficace et lisible ! 