
1. 

```c++
int foo(int i) {
    return ++i;
}
```

a) no

b yes

c) integer i is incremented by 1 and returned (pass by value)


2.
```c++
int foo(const int i) {
    return ++i;
}
```

a) yes the function attempts to modify i, which is constant, as defined in the function head (pass by value). 

b) no, since the function tries to modify a constant value, it produces an error -> undefined behaviour

c) N/A


3.

```c++
int foo(int& i) {
    return ++i;
}
```

a) no

b) yes

c) it increments the variable passed to the function (pass by reference) by 1. After the function vall this variable is changed. 


4. 

```c++
int& foo(int i) {
    return ++i;
}
```

a) No

b) No, it returns a reference to the variable (temporary copy of i) used in the function by a pass by value. This reference is not usable outside the function, so it does not make sense to return this reference. -> undefined behaviour

c) N/A

5. 

```c++
const int& foo(int& i) {
    return ++i;
}
```

a) No

b) No, the orignal value is incremented by 1 (pass by reference), but a reference to a (temporary function) variable is returned, which doesn't make sense, since the function does not have any passed by value variables. -> undefined behaviour

c) N/A
