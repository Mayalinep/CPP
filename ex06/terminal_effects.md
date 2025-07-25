# Effets ANSI dans le terminal (C++)

Les codes d'échappement ANSI permettent d'ajouter des effets visuels au texte affiché dans le terminal.

## Exemple d'effet clignotant

```cpp
std::cout << "\033[5mTexte clignotant !\033[0m" << std::endl;
```
- `\033[5m` : active l'effet clignotant (blink)
- `\033[0m` : réinitialise les effets

## Autres effets utiles
| Effet         | Code début | Exemple d'utilisation                |
|---------------|------------|--------------------------------------|
| Gras          | \033[1m    | `\033[1mTexte gras\033[0m`           |
| Souligné      | \033[4m    | `\033[4mTexte souligné\033[0m`       |
| Clignotant    | \033[5m    | `\033[5mTexte clignotant\033[0m`     |
| Inversé       | \033[7m    | `\033[7mTexte inversé\033[0m`         |
| Couleur rouge | \033[31m   | `\033[31mTexte rouge\033[0m`         |

## Remarques
- Tous les terminaux ne supportent pas l'effet clignotant.
- Pour combiner plusieurs effets, tu peux les chaîner :
  ```cpp
  std::cout << "\033[1;31mTexte gras et rouge\033[0m" << std::endl;
  ```
- Toujours terminer par `\033[0m` pour réinitialiser les effets.

---

N'hésite pas à tester ces codes dans ton terminal pour voir les effets ! 

## Faire clignoter un texte plusieurs fois (contrôle manuel)

Si tu veux contrôler le nombre de clignotements (par exemple, faire clignoter 5 fois), il faut alterner l'affichage et l'effacement du texte avec des pauses :

```cpp
#include <iostream>
#include <unistd.h> // pour sleep/usleep

int main() {
    for (int i = 0; i < 5; ++i) { // 5 clignotements
        std::cout << "\033[5mTexte clignotant !\033[0m\r" << std::flush; // Affiche
        usleep(300000); // 0.3 seconde
        std::cout << "                   \r" << std::flush; // Efface
        usleep(300000); // 0.3 seconde
    }
    std::cout << std::endl; // Pour finir proprement
    return 0;
}
```

- On utilise `usleep` pour temporiser entre chaque affichage/effacement.
- `\r` ramène le curseur au début de la ligne pour écraser le texte.
- Cette méthode fonctionne même si le terminal ne supporte pas l'effet clignotant ANSI.

--- 

## Palette de couleurs harmonieuse pour les niveaux de log

Pour rendre l'affichage des différents niveaux plus lisible et agréable, voici une palette harmonieuse :

| Niveau   | Couleur         | Code ANSI      | Exemple d’utilisation                |
|----------|-----------------|---------------|--------------------------------------|
| DEBUG    | Bleu pastel     | 38;5;117      | `\033[38;5;117mDEBUG\033[0m`         |
| INFO     | Vert menthe     | 38;5;121      | `\033[38;5;121mINFO\033[0m`          |
| WARNING  | Jaune doux      | 38;5;229      | `\033[38;5;229mWARNING\033[0m`       |
| ERROR    | Rose poudré     | 38;5;218      | `\033[38;5;218mERROR\033[0m`         |

**Exemple d’utilisation en C++ :**
```cpp
std::cout << "\033[38;5;117mDEBUG\033[0m" << std::endl;
std::cout << "\033[38;5;121mINFO\033[0m" << std::endl;
std::cout << "\033[38;5;229mWARNING\033[0m" << std::endl;
std::cout << "\033[38;5;218mERROR\033[0m" << std::endl;
```

- Tu peux utiliser ces codes dans ta classe `Harl` pour colorer chaque niveau de message.
- Les couleurs sont choisies pour être douces et harmonieuses, tout en restant distinctes.

--- 