# Encapsulation and Access Specifiers

## Class Invariants

A **class invariant** is a rule that objects of a class should maintain throughout their use.

For example, a `Monster` class might guarantee that its health is never negative.

```cpp
class Monster {
public:
    int Health { 150 };

    void TakeDamage(int Damage) {
        if (Damage <= 0) {
            return;
        }

        if (Damage >= Health) {
            Health = 0;
        } else {
            Health -= Damage;
        }
    }
};
```

`TakeDamage()` keeps health from dropping below zero and ignores nonpositive damage.

However, because `Health` is public, other code can bypass the function and break the invariant:

```cpp
Monster goblin;
goblin.Health = -100;
```

---

## Encapsulation

**Encapsulation** involves:

- Bundling data and the functions that work with it into a class.
- Restricting direct access to internal details so other code interacts through a controlled interface.

This helps a class protect its invariants.

## Access Specifiers

**Access specifiers** control which code can access class members:

- **`public`** members can be accessed by code outside the class.
- **`private`** members can be accessed by the class’s own member functions, but not directly by outside code.

Making `Health` private lets us control how it changes:

```cpp
class Monster {
private:
    int Health { 150 };

public:
    int GetHealth() const {
        return Health;
    }

    void TakeDamage(int Damage) {
        if (Damage <= 0) {
            return;
        }

        if (Damage >= Health) {
            Health = 0;
        } else {
            Health -= Damage;
        }
    }
};
```

Other code can read health through `GetHealth()` and apply damage through `TakeDamage()`, but cannot assign to `Health` directly.

The `const` after `GetHealth()` means the function cannot modify the object’s ordinary member variables.

---

## Getters and Setters

Public member functions can provide controlled access to private member variables.

- A **getter** reads a value.
- A **setter** updates a value and can validate it to protect class invariants.

```cpp
#include <iostream>
using namespace std;

class Monster {
public:
  int GetHealth(){ 
    return Health; 
   }

  void SetHealth(int IncomingHealth){
    if (IncomingHealth < 0) {
      Health = 0;
    } else {
      Health = IncomingHealth;
    }
  }

  void TakeDamage(int Damage){/*...*/};

private:
  int Health{150};
};

int main(){
  Monster Goblin;
  cout << "Health: " << Goblin.GetHealth() << endl;
  Goblin.SetHealth(-50);
  cout << "Health: " << Goblin.GetHealth() << endl;
}
```

`Health` is private, so outside code cannot access it directly.

- `GetHealth()` returns the current health.
- `SetHealth()` updates health, replacing negative values with `0`. This protects the invariant that health is never negative.

---

## Summary

- **Class invariants** are rules that objects should maintain, such as a monster’s health never being negative.
- **Encapsulation** bundles data and functions within a class and controls how outside code accesses them.
- **Access specifiers** control access to class members: `public` members are accessible from outside the class, while `private` members cannot be accessed directly.
- **Private data and public functions** help protect invariants by preventing outside code from bypassing validation.
- **Getters** provide read access to private data
- **Setters** provide controlled updates to private data.
  