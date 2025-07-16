# 🚗 EXERCICE D'ENTRAÎNEMENT - Références vs Pointeurs

## 🎯 **OBJECTIF**
Bien comprendre la différence entre **références** et **pointeurs** avec un exercice similaire à l'ex03.

---

## 📝 **SUJET - Système de Véhicules**

### **Classe Vehicle**
Implémente une classe `Vehicle` qui a :
- Un attribut privé `model` (string)
- Une fonction `getModel()` qui retourne une référence constante vers `model`
- Une fonction `setModel()` qui change le modèle

### **Classe DriverA** (Conducteur qui a TOUJOURS un véhicule)
- Prend un `Vehicle` dans son constructeur
- A toujours un véhicule (ne peut jamais être sans)
- Fonction `drive()` qui affiche : `<name> drives a <vehicle model>`

### **Classe DriverB** (Conducteur qui peut être sans véhicule)
- Ne prend PAS de véhicule dans son constructeur
- Peut commencer sans véhicule
- Fonction `setVehicle()` pour assigner un véhicule
- Fonction `drive()` qui affiche : `<name> drives a <vehicle model>` OU `<name> has no vehicle`

---

## 🤔 **QUESTIONS À SE POSER**

1. **DriverA** : Référence ou pointeur ? Pourquoi ?
2. **DriverB** : Référence ou pointeur ? Pourquoi ?
3. Que se passe-t-il si on change le modèle du véhicule après l'avoir assigné ?

---

## 🧪 **TEST ATTENDU**

```cpp
int main(){
    {
        Vehicle car = Vehicle("Ferrari");
        DriverA alice("Alice", car);
        alice.drive();
        car.setModel("Lamborghini");
        alice.drive();
    }
    {
        Vehicle car = Vehicle("Ferrari");
        DriverB bob("Bob");
        bob.drive();  // Bob has no vehicle
        bob.setVehicle(car);
        bob.drive();
        car.setModel("Lamborghini");
        bob.drive();
    }
    return 0;
}
```

## 📤 **RÉSULTAT ATTENDU**
```
Alice drives a Ferrari
Alice drives a Lamborghini
Bob has no vehicle
Bob drives a Ferrari
Bob drives a Lamborghini
```

---

## 📁 **FICHIERS À CRÉER**
- `Makefile`
- `main.cpp`
- `Vehicle.hpp`, `Vehicle.cpp`
- `DriverA.hpp`, `DriverA.cpp`
- `DriverB.hpp`, `DriverB.cpp`

---

## 🎯 **CONCEPTS CLÉS À RETENIR**
1. **Référence** = Toujours valide, ne peut pas changer
2. **Pointeur** = Peut être NULL, peut changer
3. **Initialisation** des références dans le constructeur
4. **Vérification** des pointeurs avant utilisation 