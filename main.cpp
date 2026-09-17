
#include <cstddef>
#include <cstdlib>
#include <iostream>
struct item {
  int value;
  int amount;
};

class Storage {
private:
  int count = 0;
  int size = 2;
  struct item *array;

public:
  Storage() {
    array = (struct item *)malloc((size * sizeof(struct item)));
    if (array == NULL) {
      std::cout << "Could not Allocate memory for array!!" << "\n";
      return;
    }
  };

  // add item will add a new item to the array
  // it will aslo check if there a dup if there is it adds to the values amount
  // it will also check if it is at max capcity

  void add_item(int value, int amount) {
    struct item new_item;
    // check if the array is full
    if (count == size) {
      struct item *temp =
          (struct item *)realloc(array, 2 * sizeof(struct item));
      if (temp == NULL) {
        std::cout << "Cound not Reallocate Array !!" << "\n";
        free(array);
        return;
      }
      array = temp;
      size *= 2;
    }
    // check if theres a dup
    for (int i = 0; i < count; i++) {
      if (value == array[i].value) {
        array[i].amount += amount;
        count++;
        return;
      }
    }
    new_item.value = value;
    new_item.amount = amount;
    array[count] = new_item;
    count++;
  }

  void print_members() {
    std::cout << "--Item List--" << "\n";
    for (int i = 0; i < count; i++) {
      std::cout << "Value: " << array[i].value << "\n";
      std::cout << "Amount: " << array[i].amount << "\n";
      std::cout << "\n";
    }
  }
  void print_system_info() {
    std::cout << "--System Info--" << "\n";
    std::cout << "Size: " << size << "\n";
    std::cout << "Item count: " << count << "\n";
    std::cout << "\n";
  }
};

int main() {
  Storage myst;
  myst.print_system_info();
  myst.add_item(2, 3);
  myst.print_system_info();
  myst.add_item(66, 3);
  myst.print_members();
  myst.print_system_info();
  return 0;
}
