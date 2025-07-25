# APPRENDRE À REFAIRE SEULE LE PROJET ex04 : Sed_is_for_losers

## 🗂️ Sommaire
1. [Lire et comprendre le sujet](#1)
2. [Découper le problème](#2)
3. [Structurer le projet](#3)
4. [Écrire le code étape par étape](#4)
5. [Questions à se poser à chaque étape](#5)
6. [Astuces de mentor et débogage](#6)
7. [Tester et valider](#7)
8. [S'auto-corriger et progresser](#8)
9. [Exemples de code détaillés](#9)
10. [Exemple de Makefile commenté](#10)
11. [Exemple de test complet](#11)

---

<a name="1"></a>
## 1. Lire et comprendre le sujet
- **Lis le sujet lentement**. Souligne les mots-clés : "remplacer", "toutes les occurrences", "fichier texte", "C++", "gestion d'erreur".
- **Note les interdits** : pas de lecture caractère par caractère, pas de containers avancés, pas de fonctions C pour les fichiers.
- **Liste les cas d'erreur à gérer** : fichier inexistant, vide, permissions, chaîne vide, etc.

---

<a name="2"></a>
## 2. Découper le problème
- **Sous-problèmes à résoudre** :
  1. Lire un fichier texte en C++
  2. Remplacer une chaîne par une autre dans une string
  3. Écrire le résultat dans un nouveau fichier
  4. Gérer tous les cas d'erreur
- **Astuce** : écris sur papier ou dans un commentaire la liste des étapes à suivre.

---

<a name="3"></a>
## 3. Structurer le projet
- **Fichiers à créer** :
  - `main.cpp` : point d'entrée
  - `Replace.cpp` / `replace.hpp` : la classe qui fait tout le travail
  - `Makefile` : pour compiler facilement
- **Classe Replace** :
  - Attributs : `_filename`, `_str1`, `_str2`, `_output_filename`, `_nb_replacements`
  - Méthodes : constructeur, `replace_content()`, gestion d'erreur, etc.

---

<a name="4"></a>
## 4. Écrire le code étape par étape

### a) Lecture du fichier
- **Syntaxe** :
  ```cpp
  std::ifstream file("monfichier.txt");
  if (!file.is_open()) {
      std::cerr << "Erreur d'ouverture !" << std::endl;
      return;
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
      std::cerr << "Fichier vide !" << std::endl;
      return;
  }
  std::string line;
  while (std::getline(file, line)) {
      // ...
  }
  file.close();
  ```
- **Explication** : `ifstream` ouvre le fichier en lecture. `is_open()` vérifie l'ouverture. `peek()` teste si le fichier est vide. `getline` lit ligne par ligne.

### b) Remplacement dans la string
- **Syntaxe** :
  ```cpp
  std::size_t found = line.find(str1);
  while (found != std::string::npos) {
      line.insert(found, str2);
      line.erase(found + str2.length(), str1.length());
      found = line.find(str1, found + str2.length());
      nb_replacements++;
  }
  ```
- **Explication** : On cherche la position de `str1`, on insère `str2` à la place, on efface `str1`, on continue la recherche après la nouvelle string.

### c) Écriture du fichier de sortie
- **Syntaxe** :
  ```cpp
  if (nb_replacements > 0) {
      std::ofstream out_file("monfichier.txt.replace");
      if (!out_file.is_open()) {
          std::cerr << "Erreur d'écriture !" << std::endl;
          return;
      }
      out_file << contenu_modifie;
      out_file.close();
  } else {
      std::cout << "Aucun remplacement, pas de fichier créé." << std::endl;
  }
  ```
- **Explication** : On n'écrit le fichier que si au moins un remplacement a eu lieu.

### d) Gestion des erreurs
- **Exemples de messages** :
  - Fichier inexistant : "Error: The file could not be opened."
  - Fichier vide : "Error: The file is empty."
  - Chaîne à remplacer vide : "Error: The string to replace is empty."
  - Chaîne de remplacement vide : "Error: The string to replace with is empty."
  - Chaîne à remplacer == chaîne de remplacement : "Error: The string to replace is the same as the string to replace with."

---

<a name="5"></a>
## 5. Questions à se poser à chaque étape
- Ai-je bien vérifié l'ouverture des fichiers ?
- Ai-je testé le cas du fichier vide ?
- Ai-je géré les chaînes vides ou identiques ?
- Est-ce que j'affiche un message clair pour chaque erreur ?
- Est-ce que je teste mon code à chaque étape ?

---

<a name="6"></a>
## 6. Astuces de mentor et débogage
- **Lis toujours le message d'erreur du compilateur** : il indique la ligne et le problème.
- **Utilise des `std::cout` pour afficher la valeur de tes variables** si tu ne comprends pas ce qui se passe.
- **Teste chaque étape séparément** (lecture, remplacement, écriture).
- **Commente ton code** pour t'y retrouver.
- **N'aie pas peur de recommencer une fonction si elle devient trop compliquée.**

---

<a name="7"></a>
## 7. Tester et valider
- Crée des fichiers de test variés :
  - Fichier vide
  - Fichier avec plusieurs occurrences
  - Fichier sans occurrence
  - Fichier avec des droits modifiés (`chmod 000 fichier.txt`)
- Essaie de casser ton programme exprès pour voir s'il réagit bien.

---

<a name="8"></a>
## 8. S'auto-corriger et progresser
- Relis le sujet et vérifie que tu respectes toutes les contraintes.
- Relis ton code comme si tu étais un correcteur : est-ce clair ?
- Demande à un camarade de tester ton programme.
- Note ce que tu as trouvé difficile et cherche à comprendre pourquoi.
- Refais l'exercice dans quelques jours sans regarder la solution.

---

<a name="9"></a>
## 9. Exemples de code détaillés

### a) Lecture d'un fichier et affichage
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Erreur d'ouverture !" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}
```

### b) Remplacement dans une string
```cpp
std::string line = "hello world hello";
std::string str1 = "hello";
std::string str2 = "bonjour";
std::size_t found = line.find(str1);
while (found != std::string::npos) {
    line.insert(found, str2);
    line.erase(found + str2.length(), str1.length());
    found = line.find(str1, found + str2.length());
}
// line vaut maintenant "bonjour world bonjour"
```

### c) Écriture dans un fichier
```cpp
std::ofstream out_file("result.txt");
if (!out_file.is_open()) {
    std::cerr << "Erreur d'écriture !" << std::endl;
    return 1;
}
out_file << "Ceci est un test." << std::endl;
out_file.close();
```

---

<a name="10"></a>
## 10. Exemple de Makefile commenté
```makefile
NAME = Not_a_Looser
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Replace.cpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f *.replace

re: fclean all

.PHONY: all clean fclean re
```

---

<a name="11"></a>
## 11. Exemple de test complet

1. Crée un fichier `test.txt` avec le contenu :
   ```
   hello world
   hello you
   bye
   ```
2. Compile :
   ```sh
   make
   ```
3. Lance le programme :
   ```sh
   ./Not_a_Looser test.txt hello bonjour
   ```
4. Vérifie le fichier `test.txt.replace` :
   ```
   bonjour world
   bonjour you
   bye
   ```
5. Teste les cas d'erreur (fichier vide, fichier inexistant, etc.)

---

**N'oublie pas : chaque étape compte, et plus tu comprends la logique, plus tu seras autonome !** 