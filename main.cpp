#include <iostream>
#include "memorycache.h"

int main() {
    setlocale(LC_ALL, "");
    MemoryCache* cache = MemoryCache::getInstance();


   
    cache->put("банан", "фрукт");
    cache->put("картошка", "овощ");

    std::cout << "Количество элементов после добавления пар для картошки и банана: " << cache->size() << "\n";

    std::cout << "банан -> " << cache->get("банан") << "\n";
    std::cout << "картошка -> " << cache->get("картошка") << "\n";
    std::cout << "вентилятор -> " << cache->get("вентилятор") << "\n\n";


    std::cout << "Есть ли ключ 'банан'?: " << (cache->contains("банан") ? "true" : "false") << "\n";
    std::cout << "Есть ли ключ 'вентилятор'?: " << (cache->contains("вентилятор") ? "true" : "false") << "\n\n";

   
    cache->remove("картошка");
    std::cout << "Количество элементов после удаления ключа 'картошка': " << cache->size() << "\n";
    std::cout << "Есть ли ключ 'картошка'?: " << (cache->contains("картошка") ? "true" : "false") << "\n\n";

    cache->setMaxSize(2);
    std::cout << "Максимальный размер кэша - 2\n";
    std::cout << "Количество элементов: " << cache->size() << "\n";
    std::cout << "Есть ли ключ 'банан'?: " << (cache->contains("банан") ? "true" : "false") << "\n\n";

    
    cache->clear();
    std::cout << "Кол-во элементов после очистки: " << cache->size() << "\n\n";


    cache->put("клубника", "ягода");
    std::cout << "Количество элементов после добавления нового: " << cache->size() << "\n";
    std::cout << "клубника -> " << cache->get("клубника") << "\n";

    return 0;
}