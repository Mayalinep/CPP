# Projet ex04 : Sed_is_for_losers

## 🎯 Objectif du projet

Ce projet consiste à écrire un programme C++ qui remplace **toutes les occurrences** d'une chaîne de caractères par une autre dans un fichier texte, puis écrit le résultat dans un nouveau fichier `<filename>.replace`.

Le programme doit :
- Gérer tous les cas d'erreur classiques (fichier inexistant, permissions, fichier vide, etc.)
- Utiliser les flux C++ (`ifstream`, `ofstream`)
- Utiliser les fonctions de `std::string` (pas de lecture caractère par caractère)
- Être robuste, lisible et professionnel

---

## 🚀 Utilisation

Compilation :
```sh
make
```

Exécution :
```sh
./Not_a_Looser <filename> <s1> <s2>
```
- `<filename>` : nom du fichier à traiter
- `<s1>` : chaîne à remplacer
- `<s2>` : chaîne de remplacement

---

## 🗂️ Organisation des fichiers

- `main.cpp` : point d'entrée du programme
- `Replace.cpp` / `replace.hpp` : classe qui gère toute la logique de remplacement
- `Makefile` : compilation propre, objets dans `obj/`, messages colorés
- `README.md` : ce fichier d'explication

---

## 🧩 Détail des fonctions principales

### `Replace` (classe)
**Rôle** : Encapsule toute la logique du remplacement, la gestion d'erreur, et l'affichage des messages.

#### Attributs principaux
- `_filename` : nom du fichier d'entrée
- `_str1` : chaîne à remplacer
- `_str2` : chaîne de remplacement
- `_output_filename` : nom du fichier de sortie
- `_nb_replacements` : nombre total de remplacements effectués

#### Constructeur
```cpp
Replace(const std::string& filename, const std::string& str1, const std::string& str2, const std::string& output_filename);
```
- Initialise tous les attributs
- Affiche un message d'initialisation coloré

#### `replace_content()`
**Cœur du programme**. Elle :
1. Ouvre le fichier d'entrée en lecture
2. Vérifie l'ouverture, la non-vacuité, la validité des chaînes
3. Parcourt le fichier ligne par ligne, effectue les remplacements avec `find`, `insert`, `erase`
4. Compte le nombre de remplacements
5. Si au moins un remplacement, écrit le résultat dans le fichier de sortie
6. Affiche un compte rendu professionnel
7. Sinon, affiche un message et ne crée pas de fichier `.replace`

**Gestion d'erreur** :
- Fichier inexistant ou non accessible
- Fichier vide (testé avec `.peek()`)
- Chaîne à remplacer vide
- Chaîne de remplacement vide
- Chaîne à remplacer identique à la chaîne de remplacement
- Fichier de sortie non créable

#### `getNbReplacements() const`
Retourne le nombre de remplacements effectués (utile pour des tests ou des extensions).

#### `take_content(const std::string& filename)`
Fonction utilitaire pour lire tout le contenu d'un fichier (utilisée pour des tests ou des extensions, pas indispensable dans la version finale).

#### Destructeur
Ne fait rien ici (pas d'allocation dynamique), mais présent pour la forme.

---

## 📝 Syntaxe et choix C++
- Utilisation de `std::ifstream` et `std::ofstream` pour la gestion de fichiers (C++ moderne)
- Utilisation de `std::string::find`, `insert`, `erase` pour manipuler les chaînes
- Pas de containers avancés (vector, map, etc.) pour rester conforme au sujet
- Gestion des couleurs dans les messages pour un affichage agréable
- Les attributs privés commencent par `_` pour la clarté
- Les méthodes qui ne modifient pas l'objet sont marquées `const`

---

## 🛠️ Makefile
- Compile tous les fichiers `.cpp` en objets dans `obj/`
- Crée le binaire `Not_a_Looser`
- Règle `clean` : supprime les objets et le dossier `obj/`
- Règle `fclean` : supprime aussi le binaire et tous les fichiers `.replace`
- Règle `re` : recompile tout
- Messages colorés et personnalisés pour le fun et la lisibilité

---

## 🧪 Conseils de tests et cas limites

Teste ton programme avec :
- Un fichier inexistant
- Un fichier sans permission de lecture
- Un fichier vide
- Une chaîne à remplacer vide
- Une chaîne de remplacement vide
- Une chaîne à remplacer identique à la chaîne de remplacement
- Un fichier où la chaîne n'existe pas
- Un fichier où la chaîne existe plusieurs fois sur la même ligne
- Un fichier très gros (pour voir la robustesse)

**Exemples de commandes** :
```sh
./Not_a_Looser hello.txt hello bonjour
./Not_a_Looser notfound.txt hello bonjour
./Not_a_Looser empty.txt hello bonjour
./Not_a_Looser hello.txt "" bonjour
./Not_a_Looser hello.txt hello ""
./Not_a_Looser hello.txt hello hello
```

---

## 🚀 Pour aller plus loin
- Gérer le remplacement insensible à la casse (bonus)
- Afficher le nombre de remplacements par ligne
- Gérer les très gros fichiers en écrivant ligne par ligne (pro)
- Ajouter des tests automatiques
- Factoriser l'affichage des messages dans des fonctions privées
- Ajouter une option pour remplacer seulement la première occurrence par ligne

---

## 👩‍💻 Conseils de mentor
- Prends le temps de bien tester chaque cas d'erreur
- Lis toujours les messages d'erreur pour comprendre ce qui ne va pas
- Commente ton code pour t'y retrouver
- N'hésite pas à demander de l'aide ou à relire ce README si tu bloques
- L'autonomie vient avec la pratique et la curiosité !

---

Bonne progression, et n'oublie pas : **tu es sur la bonne voie pour devenir une super codeuse !** 