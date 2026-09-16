
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

  void add_item(int value, int amount) {
    struct item new_item;

    if (count == size) {
      struct item *temp;
      temp = (struct item *)realloc(temp, 2 * sizeof(struct item));
      if (temp == NULL) {
        std::cout << "Cound not Reallocate Array !!" << "\n";
        return;
      }
      array = temp;
      size *= 2;
      free(temp);
    }

    for (int i = 0; i < count; i++) {
      if (value == array[i].value) {
        array->amount += amount;
        return;
      }
    }
    new_item.value = value;
    new_item.amount = amount;
    array[count] = new_item;
    count++;
  }
  void print_members() {
    for (int i = 0; i < count; i++) {
      std::cout << "Value: " << array->value << "\n";
      std::cout << "Amount: " << array->amount << "\n";
      std::cout << "Storage left: " << size - count << "\n";
      std::cout << "\n";
    }
  }
};

int main() {
  Storage myst;
  myst.add_item(2, 3);
  myst.add_item(2, 3);
  myst.add_item(6, 3);
  myst.print_members();
  return 0;
}
