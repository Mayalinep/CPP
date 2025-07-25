# Différence entre Exercice 5 et 6

## 🎯 Exercice 5 : Harl 2.0
**Objectif :** Afficher UN seul message selon le niveau donné
- `complain("DEBUG")` → affiche seulement le message DEBUG
- `complain("INFO")` → affiche seulement le message INFO

## 🎯 Exercice 6 : Harl Filter
**Objectif :** Afficher le message ET TOUS LES NIVEAUX SUPÉRIEURS
- `harlFilter "WARNING"` → affiche WARNING + ERROR
- `harlFilter "DEBUG"` → affiche DEBUG + INFO + WARNING + ERROR

## 🔥 Concept Clé : Fall-Through Switch

### Dans l'exercice 5 (avec breaks)
```cpp
switch(index){
    case 0 :
        (this->*complain[0])();
        break;  // ✅ S'arrête ici
    case 1 : 
        (this->*complain[1])();
        break;  // ✅ S'arrête ici
    // ...
}
```

### Dans l'exercice 6 (SANS breaks)
```cpp
switch(index){
    case 0 :
        std::cout << "[ DEBUG ]" << std::endl;
        (this->*complain[0])();
        // ❌ PAS de break → continue au case suivant
    case 1 : 
        std::cout << "[ INFO ]" << std::endl;
        (this->*complain[1])();
        // ❌ PAS de break → continue au case suivant
    case 2 : 
        std::cout << "[ WARNING ]" << std::endl;
        (this->*complain[2])();
        // ❌ PAS de break → continue au case suivant
    case 3 :
        std::cout << "[ ERROR ]" << std::endl;
        (this->*complain[3])();
        break;  // ✅ Enfin un break pour arrêter
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
}
```

## 📊 Exemple de Comportement

### Commande : `./harlFilter "WARNING"`
```
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

### Commande : `./harlFilter "DEBUG"`
```
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!
[ INFO ]
I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

## 🔧 Changements Nécessaires

1. **Nouveau main.cpp** : Doit accepter un paramètre en ligne de commande
2. **Modifier complain()** : Utiliser fall-through au lieu de breaks
3. **Ajouter les labels** : `[ DEBUG ]`, `[ INFO ]`, etc.
4. **Gestion cas invalide** : Message spécial pour les niveaux inconnus
5. **Makefile** : Changer le nom de l'exécutable en `harlFilter`

## 🚀 Stratégie de Résolution

1. **Copier les fichiers** de l'exercice 5 vers l'exercice 6
2. **Modifier main.cpp** pour accepter `argv[1]`
3. **Enlever les breaks** dans le switch (sauf le dernier)
4. **Ajouter les labels** `[ LEVEL ]`
5. **Tester** avec différents niveaux

## 💡 Points Importants

- **Fall-through** : Comportement où le switch continue aux cases suivants
- **Labels** : Afficher le nom du niveau entre crochets
- **Ordre des niveaux** : DEBUG < INFO < WARNING < ERROR
- **Gestion d'erreur** : Message spécial pour les niveaux invalides

---

**Note :** C'est un excellent exemple pratique du fall-through en switch case ! 