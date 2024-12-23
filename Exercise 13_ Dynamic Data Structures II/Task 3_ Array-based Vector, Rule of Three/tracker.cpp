#include <iostream>
#include <unordered_set>
#include "tracker.h"

using ms = std::unordered_set<const tracked*>;

namespace {

  struct Manager {
    ms tracker;
    static ms& getManager() {
      static Manager m;
      return m.tracker;
    }
  };

}

void tracked::check(const std::string& s) const {
  ms& m(Manager::getManager());
  if (m.find(this) == m.end()) {
    std::cout << "Error: you are accessing unallocated memory (" << s << ")" << std::endl;
    std::terminate();
  }
}

void tracked::checkc(const std::string& s) const {
  ms& m(Manager::getManager());
  if(m.find(this) != m.end()) {
    std::cout << "Error: you are somehow constructing an object within previously allocated memory (" << s << ")" << std::endl;
    std::terminate();
  }
}

tracked::tracked() : v() {
  checkc("default constructor");
  Manager::getManager().insert(this);
}
tracked::tracked(const tracked& t) : v(t.v) {
  checkc("default constructor");
  t.check("copy constructor source");
  Manager::getManager().insert(this);
}
tracked& tracked::operator=(const tracked& t) {
  t.check("assignment operator source");
  check("assignment operator target");
  v = t.v;
  return (*this);
}
tracked::~tracked() {
  check("deleting tracked object");
  Manager::getManager().erase(this);
}

tracked::value& tracked::operator*() {
  check("accessor");
  return v;
}

const tracked::value& tracked::operator*() const {
  check("const accessor");
  return v;
}

int count_tracked() {
  return Manager::getManager().size();
}



