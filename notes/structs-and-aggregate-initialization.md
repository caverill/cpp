# Structs and Aggregate Initialization

Some objects have multiple related properties. For example, a position in 3D space is represented by three coordinates: `x`, `y`, and `z`.

Instead of storing these coordinates as separate variables, we can group them into a single object, making them easier to manage and pass around.

---

## Vectors

A vector is a mathematical object that represents a quantity with magnitude and direction.

In programming, vectors are commonly represented using structures containing multiple numerical components.

For example, a 3D vector contains three components: `x`, `y`, and `z`.

---

## Structs vs. Classes (Technical)

In C++, `struct` and `class` are nearly identical.

The main differences are their default access levels:

- **Struct:** Members and base classes are `public` by default.
- **Class:** Members and base classes are `private` by default.

Both support constructors, methods, inheritance, and access modifiers.

---

## Structs vs. Classes (Semantic)

Although structs and classes are technically similar, C++ programmers typically use them for different purposes.

- **Structs:** Simple types that primarily group related data.
- **Classes:** More complex types that encapsulate data and behaviour.

These are conventions rather than enforced rules.

---

## Aggregate Initialization

Aggregate initialization allows us to initialize the members of an aggregate type directly using braces `{}`, without explicitly defining a constructor.

For example:

```cpp
struct Vector3 {
    float x;
    float y;
    float z;
};
```

We can initialize a `Vector3` object directly:

```cpp
int main() {
    Vector3 Position{1.9f, 2.6f, 0.3f};
}
```

Here, `Position` is a `Vector3` instance with `x`, `y`, and `z` initialized to `1.9`, `2.6`, and `0.3`, respectively.

Values are assigned to members in their declaration order.

Aggregate initialization is not available for all types. Only types that meet the requirements of an aggregate can be initialized this way.

Since structs are conventionally used for simple data types, aggregate initialization is more commonly associated with structs.

More complex types, such as classes with private data members, cannot use aggregate initialization. Instead, we typically define a constructor to initialize their members.

Following C++ conventions, we would generally declare these more complex types using `class` rather than `struct`.

---

### Important Notes

- Aggregate initialization uses braces `{}`.
- Values are assigned in the order members are declared.
- You do not need to define a constructor.
- Not every `struct` or `class` qualifies as an aggregate.
- Arrays can also use aggregate initialization.

---

## Summary

- **Structs** provide a simple way to group related data into a single object.
- **Structs vs. Classes:** Struct members are `public` by default, while class members are `private`. The same distinction applies to default inheritance access.
- **Structs** are conventionally used for simple data types without complex behaviour, while classes are used for more complex objects.
- **Aggregate initialization** allows us to initialize members directly using `{}`, without explicitly defining a constructor.
- **Vectors**, such as `Vector3`, demonstrate how structs can group related values like `x`, `y`, and `z` into a single object.