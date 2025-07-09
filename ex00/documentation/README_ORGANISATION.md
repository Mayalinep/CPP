# 📁 Organisation du Projet - Exercice Zombies

## 🎯 Structure des Dossiers

```
ex00/
├── cours/                          # 📚 Tous tes cours
│   ├── cours_erreurs_courantes_classes.md
│   └── [autres cours à venir]
│
├── mes_exercices/                  # 🏋️ Tes exercices à faire
│   ├── exercice_01_classe_simple.cpp
│   ├── exercice_02_public_private.cpp
│   └── [exercices suivants]
│
├── exercices_solutions/            # ✅ Solutions et corrections
│   ├── README.md
│   ├── exercice_01_classe_simple_corrige.cpp
│   └── [solutions suivantes]
│
├── sujet_01.md                    # 📋 Sujet original de l'exercice
├── main.cpp                       # 🎯 Exercice principal zombie
├── Zombie.class.hpp               # 🧟 Fichiers de l'exercice zombie
├── Zombie.cpp
├── newZombie.cpp
├── randomChump.cpp
└── README_ORGANISATION.md         # 📁 Ce fichier
```

## 🚀 Comment Travailler

### 1. **Pour les cours** 📚
- Va dans le dossier `cours/`
- Lis les fichiers `.md` pour apprendre
- Reviens-y quand tu as besoin de réviser

### 2. **Pour les exercices** 🏋️
- Va dans le dossier `mes_exercices/`
- Ouvre le fichier `.cpp` de l'exercice
- Écris ton code directement dedans
- Compile et teste : `g++ -o test fichier.cpp && ./test`

### 3. **Pour les corrections** ✅
- Va dans le dossier `exercices_solutions/`
- Compare avec la solution après avoir essayé
- Lis les commentaires d'explication

### 4. **Pour l'exercice zombie** 🧟
- Reste dans le dossier `ex00/`
- Utilise les fichiers `Zombie.cpp`, `main.cpp`, etc.
- Applique ce que tu as appris dans les exercices

## 🎯 Workflow Recommandé

1. **Lis** un cours dans `cours/`
2. **Fais** l'exercice correspondant dans `mes_exercices/`
3. **Compile et teste** ton code
4. **Compare** avec la solution dans `exercices_solutions/`
5. **Corrige** si nécessaire
6. **Passe** à l'exercice suivant

## 💡 Conseils d'Organisation

### Pour compiler rapidement :
```bash
# Depuis mes_exercices/
g++ -o test exercice_01_classe_simple.cpp && ./test
```

### Pour nettoyer :
```bash
# Supprimer les fichiers de compilation
rm -f test *.o
```

### Pour naviguer :
```bash
# Aller dans tes exercices
cd mes_exercices/

# Aller dans les cours
cd ../cours/

# Aller dans les solutions
cd ../exercices_solutions/
```

## 🎯 Prochaines Étapes

1. **Fais** l'exercice 2 dans `mes_exercices/exercice_02_public_private.cpp`
2. **Teste** ton code
3. **Dis-moi** quand tu as terminé
4. **Compare** avec la solution que je créerai

---

*Cette organisation te permettra de rester organisée et de progresser efficacement !* 