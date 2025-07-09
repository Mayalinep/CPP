# 🤔 Questions de Compréhension - Exercice Zombies

## Instructions
Réponds à ces questions dans les espaces prévus. Cela m'aidera à vérifier ta compréhension et à t'accompagner au mieux.

---

## 🎯 Questions sur les Classes

### Question 1 : Attributs privés
**Pourquoi l'attribut `name` est-il privé et pas public ?**

**Ta réponse :**
```
Name est dans la partie prive pour eviter d y acceder comme ca, pour y acceder on utilise des getters et pour les changer des setters, c est plus secure. Si tout le monde pouvait y acceder le programme n est plus proteger correctement et les donnes sont modifier sans le vouloir. les methodes par contre sont plus souvent public. 
```

**✅ Correction :**
**Très bien !** Tu as parfaitement compris le concept d'encapsulation. L'attribut `name` est privé pour :
- **Sécurité** : Empêcher les modifications accidentelles
- **Contrôle** : Forcer l'utilisation de méthodes spécifiques
- **Intégrité** : Garantir que les données restent cohérentes

**Indices si tu bloques :**
- Pense à la sécurité et au contrôle
- Que se passerait-il si tout le monde pouvait modifier directement le nom ?

---

## 🎯 Questions sur la Gestion Mémoire

### Question 2 : Destructeur et randomChump
**Quand penses-tu que le destructeur s'affichera avec randomChump ?**

**Ta réponse :**
```
le destructeur s affichera a la fin du main, donc du programme, pour quitter proprement sans leak. grace a la stack les donnes sont detruite automatiquement 
```

**⚠️ Correction :**
**Presque !** Mais attention au timing. Le destructeur ne s'affiche pas à la fin du main, mais **à la fin de la fonction randomChump** !

**Réponse correcte :**
- randomChump crée un zombie sur le **stack local** de la fonction
- Dès que la fonction se termine (accolade fermante `}`), le zombie est **automatiquement détruit**
- Le destructeur s'affiche **immédiatement** après l'appel à randomChump

**Pourquoi c'est important :** Cela montre que les objets stack ont une durée de vie **limitée à leur scope**.

**Indices si tu bloques :**
- randomChump crée un zombie sur le stack
- Que se passe-t-il à la fin d'une fonction ?

### Question 3 : newZombie et pointeurs
**Si newZombie retournait un Zombie au lieu d'un Zombie*, que se passerait-il ?**

**Ta réponse :**
```
ca recreerai une copie de Zombie donc ca ferai une trop grosse consommation des ressources. et qd on sort de la fonction il risque d avoir des leaks si on prend pas la peine d effacer cette copie.
```

**⚠️ Correction :**
**Partiellement correct !** Tu as raison sur la copie, mais le problème principal est différent.

**Réponse correcte :**
- Si newZombie retournait un `Zombie` (pas `Zombie*`), il y aurait une **copie** de l'objet
- Mais le vrai problème : l'objet original (créé avec `new`) serait **détruit** quand on sort de la fonction
- La copie retournée **pointerait vers rien** (objet détruit)
- Résultat : **comportement indéfini** et **fuite mémoire** de l'objet original

**Le pointeur permet** de retourner l'**adresse** de l'objet heap, qui survit à la fonction.

**Indices si tu bloques :**
- Pense à la durée de vie de l'objet
- Que se passe-t-il quand on sort de la fonction ?

---

## 🎯 Question de Logique

### Question 4 : Pourquoi deux fonctions ?
**Pourquoi l'exercice demande-t-il de créer DEUX fonctions différentes (randomChump et newZombie) ?**

**Ta réponse :**
```
je sais pas a quoi ca sert, j ai pas bien compris l exercice. je crois que tu m a parler de l un sur la heap et l un sur la stack
```

**✅ Correction :**
**Exactement !** Tu as identifié le point clé. L'exercice veut te faire comprendre la différence entre stack et heap.

**Réponse complète :**
- **randomChump** : Crée un zombie sur le **stack** → destruction automatique, usage temporaire
- **newZombie** : Crée un zombie sur le **heap** → destruction manuelle, usage prolongé

**Objectif de l'exercice :** Te faire réfléchir à **quand utiliser** chaque méthode :
- **Stack** : Objets temporaires qui n'ont pas besoin de survivre à la fonction
- **Heap** : Objets qui doivent être utilisés ailleurs dans le programme

**Indices si tu bloques :**
- Quelle est la différence fondamentale entre les deux ?
- Que veulent-ils nous faire comprendre sur la gestion mémoire ?

---

## 🎯 Questions Bonus - Prédictions

### Question 5 : Ordre d'exécution
**Dans quel ordre penses-tu que les messages s'afficheront si on fait ça dans le main ?**

```cpp
int main() {
    std::cout << "=== Test randomChump ===" << std::endl;
    randomChump("Bob");
    std::cout << "=== Fin randomChump ===" << std::endl;
    
    std::cout << "=== Test newZombie ===" << std::endl;
    Zombie* zombie = newZombie("Alice");
    zombie->announce();
    delete zombie;
    std::cout << "=== Fin newZombie ===" << std::endl;
    
    return 0;
}
```

**Ta prédiction :**
```

je sais pas trop j avoue
```

**✅ Correction - Ordre d'exécution :**
```
=== Test randomChump ===
Bob: BraiiiiiiinnnzzzZ...
Bob détruit!
=== Fin randomChump ===
=== Test newZombie ===
Alice: BraiiiiiiinnnzzzZ...
Alice détruit!
=== Fin newZombie ===
```

**Explication :**
1. **randomChump("Bob")** : Crée Bob, il s'annonce, puis est détruit immédiatement
2. **newZombie("Alice")** : Crée Alice sur le heap, elle s'annonce, puis on la détruit avec `delete`

---

## 🎯 Auto-évaluation

### As-tu bien compris ?
Coche les cases pour lesquelles tu te sens à l'aise :

- [x] Je comprends ce qu'est une classe
- [x] Je comprends la différence entre public et private
- [x] Je comprends ce qu'est un constructeur
- [x] Je comprends ce qu'est un destructeur
- [-] Je comprends la différence entre stack et heap
- [x] Je comprends pourquoi on utilise des pointeurs
- [-] Je comprends la logique de l'exercice

### Questions pour moi (ton mentor)
**Y a-t-il des concepts que tu veux que je réexplique ?**

**Ta demande :**
```
la logique de l exercice et ce qu on attend de moi.
```

---

## 🎯 Prêt(e) pour l'étape suivante ?

**Te sens-tu prêt(e) à commencer l'implémentation ?**
- [ ] Oui, j'ai tout compris
- [ ] Non, j'ai encore des questions
- [ ] Je veux d'abord faire des exercices pratiques

**Si tu veux des exercices pratiques, coche ce qui t'intéresse :**
- [x] Exercices sur les classes de base
- [x] Exercices sur les pointeurs
- [x] Exercices sur stack vs heap
- [x] Mini-projet pour pratiquer

---

*Remplis ce fichier et dis-moi quand tu as terminé !* 