#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <string>


using namespace std;


template<typename K, typename V>
class HashTable {
    struct Pair
    {
        K key;
        V value;
        bool not_empty;
        Pair():	 key(0), value(0), not_empty(false) {}
        Pair(const K& key, const V& value) : key(key), value(value), not_empty(true) {}
    };
    std::vector<std::list<Pair>> _data;
    size_t _collisions;
    size_t hash_function(const K& key) {
        return key % _data.size();
    }
public:
    HashTable(size_t size): _data(size) {}
    HashTable(size_t size, size_t num_elements): _data(size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<K> distrib_key(0, size - 1);
        std::uniform_int_distribution<V> distrib_value(0, 100);

        for (size_t i = 0; i < num_elements; ++i) {
            K key = distrib_key(gen);
            V value = distrib_value(gen);
            insert(key, value);
        }
    }
    HashTable(const HashTable& other): _data(other._data) {}
    ~HashTable() {}
    HashTable& operator=(const HashTable& other) {
        if (this != &other) {
            _data.clear();
            _data.resize(other._data.size());
            for (size_t i = 0; i < other._data.size(); ++i) {
                for (const auto& pair : other._data[i]) {
                    _data[i].push_back(pair);
                }
            }
        }
        return *this;
    }
    //функция печати хэш-таблицы
    void print() {
        for (size_t i = 0; i < _data.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : _data[i]) {
                std::cout << pair.key << " -> " << pair.value << "; ";
            }
            std::cout << std::endl;
        }
    }

    //вставка элемента пары ключ-значение в соответствующий бакет по индексу, вычисленному хэш-функцией
    void insert(K key, V value) {
        size_t index = hash_function(key);
        if (_data[index].size()) _collisions++;
        for (auto& pair : _data[index]) {
            if (pair.key == key) {
                return;
            }
        }
        _data[index].push_back(Pair(key, value));
    }

    //вставка элемент или изменение значения по указанному ключу
    void insert_or_assign(K key, V value) {
        size_t index = hash_function(key);
        for (auto& pair : _data[index]) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        _data[index].push_back(Pair(key, value));
    }

    //проверка наличия заданного значения в таблице
    bool contains(V value) {
        for (const auto& bucket : _data) {
            for (const auto& pair : bucket) {
                if (pair.value == value) {
                    return true;
                }
            }
        }
        return false;
    }

    //поиск значения по ключу
    V* search(K key) {
        size_t index = hash_function(key);
        for (auto& pair : _data[index]) {
            if (pair.key == key) {
                return &pair.value;
            }
        }
        return nullptr;
    }
    //удаление элемента из таблицы по заданному ключу
    bool erase(K key) {
        size_t index = hash_function(key);
        for (auto& pair : _data[index]) {
            if (pair->key == key) {
                _data[index].erase(pair);
                return true;
            }
        }
        return false;
    }

    //возвращает количество элементов по заданному ключу
    int count(K key) {
        size_t index = hash_function(key);
        return _data[index].size();
    }

    //возвращает количество коллизий в хэш-таблице
    size_t get_collisions() const {
        return _collisions;
    }
};

//реализация алгоритма хэширования Пирсона для строк
unsigned char Pearson_hash(string str) {
    static const unsigned char T[256] = {
            98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219,
            61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115,
            90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10,
            237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121,
            123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55,
            59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222,
            197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186,
            39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99,
            154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254,
            133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139,
            189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44,
            183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12,
            221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166,
            3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117,
            238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110,
            43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
    };
    unsigned char hash = 0;
    for (char c : str) {
        hash = T[hash ^ static_cast<unsigned char>(c)];
    }
    return hash;
}
//функция для сравнения хэшей
bool hash_compare(string str, int hash) {
    int str_hash = Pearson_hash(str);
    if (str_hash == hash) {
        return true;
    }
    return false;
}
