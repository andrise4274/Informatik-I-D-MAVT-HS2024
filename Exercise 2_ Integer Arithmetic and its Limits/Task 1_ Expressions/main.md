
### Expression 1: --> **valid, lvalue**
- the number 5 is assigned both to a and b. a and b are lvalues with a location in memory. 

- [x] valid
---

### Expression 2: --> **invalid**


- since the number 1 is an rvalue with no dedicated space in memory, it cannot stand on the right of the assignment operator.

- [ ] -> invalid
---

### Expression 3: --> **valid, rvalue**

- The sum of both lvalues returns an rvalue

- [x] valid
---

### Expression 4: --> **invalid**

- the rvalue c + d, from the sum operator has no place in memory and cannot be assigned to the invalid lvalue a + b

- [ ] -> invalid
---

### Expression 5: **invalid**

- syntax error, no operator between 2 and b - correct would be: a = 2*b;

- [ ] -> invalid
---