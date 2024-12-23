#include "smart.h"
#include "tracker.h"

Smart::Smart() : count(nullptr), ptr(nullptr){}


Smart::Smart(tracked* t) : count(nullptr), ptr(t) {
  if (t != nullptr) {
    int count = 1;
    this->count = new int(count);
  }
}


Smart::Smart(const Smart& src)  : count(src.count), ptr(src.ptr){
  // if the source is a Smart Nullptr, leave the assigned pointer as a nullptr
  if (ptr == nullptr) return;
  // to the count of source and increase it by 1
  *(count) += 1;
}


Smart::~Smart() {
  // ensure smart pointer is existent - can be deconstructed
  if (count != nullptr) {
    // if only one pointer is existing - destruct it
    if (*count == 1) {
      delete count;
      delete ptr;
    } else {
      // decrement count
      *count -= 1;
    }
  }
}


Smart& Smart::operator=(const Smart& src) {
  if (ptr != src.ptr) {
    Smart copy(src);
    // swap elements
    int* temp_count = count;
    count = copy.count;
    copy.count = temp_count;
    
    tracked* temp_ptr = ptr;
    ptr = copy.ptr;
    copy.ptr = temp_ptr;
  // copy gets out of scope and destructor is called
  }
  return *this;
}

tracked& Smart::operator*() {
  return *ptr;
}

const tracked& Smart::operator*() const {
  return *ptr;
}

tracked* Smart::operator->() {
  return ptr;
}

const tracked* Smart::operator->() const {
  return ptr;
}

bool Smart::operator==(const Smart& cmp) const {
  return (ptr == cmp.ptr);
}

bool Smart::operator!=(const Smart& cmp) const {
  return !(*this == cmp);
}

int Smart::get_count() const{
  if (this -> count == nullptr)
    return 0;
  else
    return *(this->count);
}

void your_own_tests() {
  // EXTRA TESTS ?
}
