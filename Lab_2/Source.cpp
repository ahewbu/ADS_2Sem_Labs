#include "Hash_table.h"


int main() {
    HashTable<int, int> table(10);
    for (size_t i = 0; i < 10; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib_key(0, 10 - 1);
        std::uniform_int_distribution<int> distrib_value(0, 100);
        int key = distrib_key(gen);
        int value = distrib_value(gen);
        table.insert(key, value);
    }

    table.print();

    int a = Pearson_hash("family");
    bool res = hash_compare("family", a);

    if (res)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}