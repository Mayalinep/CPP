# Effet "machine à écrire" en C++98

## Principe
L'effet machine à écrire consiste à afficher un texte caractère par caractère, avec un délai entre chaque, pour simuler la frappe d'une machine à écrire.

## Exemple de fonction en C++98
```cpp
#include <iostream>
#include <unistd.h> // pour usleep

void typewriter_effect(const std::string& text, useconds_t delay) {
    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i] << std::flush;
        usleep(delay); // délai en microsecondes
    }
    std::cout << std::endl;
}
```
- `delay` est le temps d'attente entre chaque caractère (ex: 100000 pour 100ms).
- Utilise `std::flush` pour forcer l'affichage immédiat.

## À éviter en C++98
- **Boucle range-based for** (`for(char c : text)`) : seulement à partir de C++11 !
- **auto** et autres nouveautés C++11.

## Bonnes pratiques
- Toujours finir par un retour à la ligne (`std::endl`).
- Utiliser `size_t` pour l'indexation.
- Adapter le délai selon l'effet désiré.

## Différence avec C++11+
- En C++11, tu peux écrire :
  ```cpp
  for(char c : text) { ... }
  ```
- En C++98, il faut utiliser l'index :
  ```cpp
  for(size_t i = 0; i < text.length(); ++i) { ... }
  ```

## Pour aller plus loin
- Tu peux ajouter un son (bip) à chaque caractère pour un effet encore plus réaliste.
- Tu peux varier le délai pour simuler une frappe humaine.

---
N'hésite pas à relire ce fichier si tu veux refaire cet effet dans un autre projet ! 