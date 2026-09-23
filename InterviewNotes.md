# C++ Interview Notes

### 1. Dangling Pointer
- Pointer to invalid/dead object (object that is not in the access limit of the program)
- Memory freed, pointer still exists

### 2. Memory Leak
- Pointer lost, memory still allocated to the program

### 3. Stack
- Automatic lifetime
- Local variables commonly live here

### 4. Heap
- Dynamically allocated
```cpp
int* p = new int(10);
```
- Explicit/managed lifetime
- `new`/allocators dynamically allocate
- Must be managed, preferably via RAII

**RAII** stands for **Resource Acquisition Is Initialization**.

> RAII = ownership tied to object lifetime → destructor automatically cleans up the resource.

### 5. Smart Pointers
- They reduce memory leaks and dangling-pointer risks and make ownership semantics explicit.
- `unique_ptr`, `shared_ptr`, `weak_ptr`
- Smart pointers are primarily about ownership.
- Raw pointers can be used when you don't own the object.

### 6. `unique_ptr`
```cpp
auto p = std::make_unique<int>(10);
```

You cannot copy it:
```cpp
auto p2 = p;  // ❌
```

But you can move ownership:
```cpp
auto p2 = std::move(p);  // ✅
```

### 7. `shared_ptr`
```cpp
auto p1 = std::make_shared<int>(10);
```

- The object is destroyed when the last `shared_ptr` owning it is destroyed.
- You can copy it:
```cpp
auto p2 = p1;
```

### 8. `weak_ptr`
```cpp
auto shared = make_shared<int>(10);
weak_ptr<int> weak = shared;
```

- Used with `shared_ptr` when you want to observe an object without owning it.
- It doesn't increase the reference count.
- It's especially useful for avoiding reference cycles.

### 9. Race Condition

### 10. Atomic
```cpp
atomic<int> counter;
```

### 11. Mutex
```cpp
lock_guard<mutex> lock(m);
```

### 12. Mutex vs Semaphore

### 13. `transform`
```cpp
transform(v.begin(), v.end(), out.begin(), square)
```

- `square` is a function which accepts one `int` value.
- This works in parallel.

### 14. `vector<bool>`
- `vector<bool>` is different.
- It uses a proxy.
- So you cannot:
```cpp
bool& x = v[0];  // ❌
```
- But:
```cpp
cout << v[0];  // ✅
```

### 15. Thread Pool
- Worker threads
- Task queue
- Mutex
- Condition variable
- Shutdown mechanism

### 16. Lvalues / Rvalues
- Lvalues can take only lvalues unless there is `const`.
- `const` can take rvalues.
- Rvalues only take temporary rvalues and can steal the resources of temporary rvalues.

### 17. Double-Checked Locking
- Naive double-checked locking is unsafe → proper memory ordering/publication isn't guaranteed.

Use `call_once` or:

```cpp
static Singleton& getInstance() {
    static Singleton instance;
    return instance;
}
```

### 18. Name Mangling
- Name mangling for overloading in C++

### 19. `push_back` vs `emplace_back`

```cpp
v.push_back(Person("Rupesh", 35));
```

→ First object is created, then it is moved or copied to the vector.

```cpp
v.emplace_back("Rupesh", 35);
```

→ The object is created only once.

### 20. `std::function`
- Holds the function and it is type saved.

### 21. Static Variable
- Static variable is not thread safe.

### 22. Operator Overloading
- Only when it makes sense.

### 23. Friend
- `friend` class can access all the variables and functions of what the other class can access.
- For testing, you can use the `friend` keyword without messing with the original class.
- If there are, let's say, 20 classes and we want to have a mediator of those 20 classes, we can use the `friend` keyword.

### 24. Reference

```cpp
int &r = i;
```

- `r` is an alias of `i`.
- `&r` represents the address.
- `r++` can be done.
- A reference cannot be reseated. It is final; you cannot change it.
- So initializing as `null` also cannot be done.
- Arithmetic operations cannot be applied to variable `r` but `&r` represents the value `i` so can be done like:
```cpp
(&r)++
```

### 25. Factory Design Pattern

The Factory Design Pattern separates object creation from the main application logic.

Instead of having the Amazon class directly create every type of product, a separate `ProductFactory` handles the creation.

This way, when a new product is added, the object-creation logic is handled in the factory rather than modifying the main Amazon class.
