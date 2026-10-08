# Abstraction, Classes, and Objects

## Abstraction

**Abstraction** means representing the relevant features of something while leaving out unnecessary details.

For example, a program might represent a pet using their name, age, and ability to play. It doesn’t need to model every detail about a real pet.

**Object-oriented programming (OOP)** organizes code around objects that combine data and behavior.

---

## Classes and Objects

A **class** defines a custom type, such as `Pet`. It acts as a **blueprint** describing the data and behavior its objects can have.

An **object** is an individual instance of that class.

```cpp
class Pet {
public:
    // Member variables and functions go here
};

int main() {
    Pet Lexi;
}
```

Here, `Pet` is the **class**, and `Lexi` is an **object** of that class.

### Instantiation

Creating an object from a class is called **instantiation**. The object created is an **instance** of that class.

`Pet Lexi;` instantiates the `Pet` class to create an object named `Lexi`.

---

## Class Members

**Class members** are the variables and functions declared within a class. They allow objects to store **state** and perform **actions**.

- **Member variables** store state, such as a pet’s name and age. They are also called **data members** or **fields**, and sometimes **properties**.
- **Member functions** define behavior, such as a pet playing. They are also called **methods**.

In C++, **member variable** and **member function** are the usual terms.

---

## Member Function Declarations and Definitions

A member function can be **declared inside a class** and **defined outside it**.

The declaration specifies the function’s return type, name, and parameters without providing its body yet.

```cpp
class Pet {
public:
    int Energy { 100 };

    void Play(int EnergyUsed);
};
```

The definition provides the function’s body. We use `ClassName::FunctionName` to identify which class the function belongs to.

```cpp
void Pet::Play(int EnergyUsed) {
    Energy -= EnergyUsed;
}
```

Here, `::` is the **scope resolution operator**. `Pet::Play` means “the `Play` member function belonging to `Pet`.”

We can then call the function on an object:

```cpp
int main() {
    Pet Lexi;
    Lexi.Play(20);
}
```

After the call, `Lexi.Energy` is `80`.
