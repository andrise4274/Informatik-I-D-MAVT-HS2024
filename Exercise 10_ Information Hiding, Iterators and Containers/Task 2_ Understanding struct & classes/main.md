1. `plain|`
  
    1. Type: `cpp|double` / Value: `cpp|1.5`
    2. Type: `cpp|bool` / Value: `cpp|false`
    3. Type: `cpp|double` / Value: `cpp|0.75`
    4. Type: `cpp|int` / Value: `cpp|0`
    5. Type: `cpp|double` / Value: `cpp|-1.5`

---

2. ```c++ 
    // PRE: index of vector as char c in range [0, 127]
    // POST: increments vec[c] by 1
    void add(const char c);

    // PRE: index of vector as char c in range [0, 127]
    // POST: returns integer of vec at position c (vec[c])
    // does not change vec internally
    int get(const char c) const;
    
    ```