# 📖 EXERCICE D'ENTRAÎNEMENT - Bibliothèque

## 🎯 **TON DÉFI**

Crée un système de bibliothèque avec des livres et des lecteurs, en utilisant les concepts qu'on vient d'apprendre !

---

## 📋 **ÉNONCÉ**

### **Classe Book**
Implémente une classe `Book` qui a :
- Un attribut privé `title` (string)
- Un constructeur qui prend un titre
- Un getter `getTitle()` qui retourne une référence constante au titre
- Un setter `setTitle()` qui change le titre
- Un destructeur

### **Classe ReaderA** (Toujours en train de lire)
- A un `name` (string) et un `book` (référence `Book&`)
- Constructeur : `ReaderA(string name, Book& book)`
- Méthode `read()` qui affiche : `"<name> is reading <book title>"`
- **ReaderA lit TOUJOURS** - il a toujours un livre en main !

### **Classe ReaderB** (Peut ne pas avoir de livre)
- A un `name` (string) et un `book` (pointeur `Book*`)
- Constructeur : `ReaderB(string name)` (sans livre)
- Méthode `setBook(Book& book)` pour donner un livre
- Méthode `read()` qui affiche :
  - S'il a un livre : `"<name> is reading <book title>"`
  - Sinon : `"<name> has no book to read"`
- **ReaderB peut être sans livre** - il peut commencer sans rien !

---

## 🧪 **TEST ATTENDU**

Ton programme doit produire cette sortie :
```
Alice is reading The Great Gatsby
Alice is reading 1984
Bob has no book to read
Bob is reading The Great Gatsby
Bob is reading 1984
```

Avec ce code de test :
```cpp
int main() {
    {
        Book book("The Great Gatsby");
        ReaderA alice("Alice", book);
        alice.read();
        book.setTitle("1984");
        alice.read();
    }
    {
        Book book("The Great Gatsby");
        ReaderB bob("Bob");
        bob.read();
        bob.setBook(book);
        bob.read();
        book.setTitle("1984");
        bob.read();
    }
    return 0;
}
```

---

## 💡 **INDICES**

### **Pour Book :**
- Simple classe avec un string et ses accesseurs
- N'oublie pas le destructeur !

### **Pour ReaderA :**
- Utilise une **référence** `Book&`
- **Liste d'initialisation** obligatoire !
- Format : `ReaderA(params) : name(name), book(book) {}`

### **Pour ReaderB :**
- Utilise un **pointeur** `Book*`
- Initialise à `NULL` dans le constructeur
- Dans `setBook()` : `this->book = &book`
- Dans `read()` : vérifie si `this->book` n'est pas NULL

---

## 📁 **FICHIERS À CRÉER**

Crée ces fichiers dans un dossier `entrainement/` :
- `Book.hpp` et `Book.cpp`
- `ReaderA.hpp` et `ReaderA.cpp`
- `ReaderB.hpp` et `ReaderB.cpp`
- `main.cpp`
- `Makefile`

---

## 🚀 **ÉTAPES SUGGÉRÉES**

1. **Commence par `Book`** (la plus simple)
2. **Puis `ReaderA`** (avec référence)
3. **Enfin `ReaderB`** (avec pointeur)
4. **Teste au fur et à mesure** avec `make` et `./programme`

---

## 💪 **C'EST PARTI !**

N'hésite pas à :
- Poser des questions si tu bloques
- Tester chaque classe séparément
- Relire `COMPRENDRE_EX03.md` si besoin

**Tu vas y arriver !** 🎉

---

## 🔍 **BONUS (optionnel)**

Si tu veux aller plus loin :
- Ajoute une méthode `getPageCount()` à Book
- Ajoute une méthode `hasBook()` à ReaderB qui retourne true/false
- Gère le cas où on donne un livre vide ("") à Book 