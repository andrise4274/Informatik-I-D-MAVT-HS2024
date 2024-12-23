#pragma once

#include <string>
#include <cassert>

// class tracked: wrapper around its value type which track the number
//   of elements of class tracked currently in existence.
//   Used to check for memory leaks.
class tracked {
public:
  using value = int;
  // POST: apply matching constructor/assignment operator/destructor
  //       to underlying value.
  tracked();
  tracked(const tracked&);
  tracked& operator=(const tracked&);
  ~tracked();
  // POST: return (const) reference to underlying value.
  value& operator*();
  const value& operator*() const;
private:
  void check(const std::string&) const;
  void checkc(const std::string&) const;
  value v;
};

// POST: return number of elements of class tracked currently in existence.
int count_tracked();