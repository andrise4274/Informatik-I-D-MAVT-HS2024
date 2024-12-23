1. Mistake: The mistake is: the usage of ``delete``
  
   Nature: **memory leak**
  
   Error location (if applicable): The mistake happens when we call ``delete ptr`` instead of ``delete[] ptr``

---

2. Mistake: The mistake is: the order of ``delete n;
        recursive_delete_linked_list(n->next);``
  
   Nature: **error (undefined behaviour)**
  
   Error location: The mistake happens when we delete the parent node before the child node. This leads to undefined behaviour, since we lost the location of the child node in memory
---
3. Mistake: The mistake is: The destructor is missing ``delete c->subshell``
  
   Nature: **memory leak**
  
   Error location: The mistake happens when with the destructor only the Cell object is deleted and not the memory on which subcell points to.
---
4. Mistake: The mistake is to try to delete sth. which is not stored in the heap
  
   Nature: **error (undefined behaviour)**
  
   Error location: The mistake happens when we try to delete the pointer w, which is in the static stack memory and not in the heap (was not dynamically allocated with ``new``).

---
5. Mistake: The mistake is the delete call of ``delete[] &v[0];``
  
   Nature: **error (undefined behaviour)**
  
   Error location: The mistake happens when we try to delete the first element of the vector. This first element is then deleted a second time when the destructor is called, which leads to undefined behaviour.