
#include <iostream>
struct item {
  int value;
  int amount;
};

class Storage {
private:
  struct item *array = new struct item;
  int count = 0;
  int size = 0;

public:
  Storage() {};

  void add_item(int value, int amount) {
    struct item new_item;

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
      std::cout << "\n";
    }
  }
};

int main() {
  Storage myst;
  myst.add_item(2, 3);
  myst.add_item(2, 3);
  myst.print_members();
  return 0;
}
