#include <iostream>
#include "memorycache.h"

int main() {
    setlocale(LC_ALL, "");
    MemoryCache* cache = MemoryCache::getInstance();


   
    cache->put("�����", "�����");
    cache->put("��������", "����");

    std::cout << "���������� ��������� ����� ���������� ��� ��� �������� � ������: " << cache->size() << "\n";

    std::cout << "����� -> " << cache->get("�����") << "\n";
    std::cout << "�������� -> " << cache->get("��������") << "\n";
    std::cout << "���������� -> " << cache->get("����������") << "\n\n";


    std::cout << "���� �� ���� '�����'?: " << (cache->contains("�����") ? "true" : "false") << "\n";
    std::cout << "���� �� ���� '����������'?: " << (cache->contains("����������") ? "true" : "false") << "\n\n";

   
    cache->remove("��������");
    std::cout << "���������� ��������� ����� �������� ����� '��������': " << cache->size() << "\n";
    std::cout << "���� �� ���� '��������'?: " << (cache->contains("��������") ? "true" : "false") << "\n\n";

    cache->setMaxSize(2);
    std::cout << "������������ ������ ���� - 2\n";
    std::cout << "���������� ���������: " << cache->size() << "\n";
    std::cout << "���� �� ���� '�����'?: " << (cache->contains("�����") ? "true" : "false") << "\n\n";

    
    cache->clear();
    std::cout << "���-�� ��������� ����� �������: " << cache->size() << "\n\n";


    cache->put("��������", "�����");
    std::cout << "���������� ��������� ����� ���������� ������: " << cache->size() << "\n";
    std::cout << "�������� -> " << cache->get("��������") << "\n";

    return 0;
}