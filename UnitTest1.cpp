#include <cassert>
#include <sstream>
#include <iostream>
#include "../task5/CircularDoublyLinkedList.h"

using namespace containers;

/**
 * @brief Функция для тестирования конструкторов
 */
void testConstructors() {
    std::cout << "--- Тест конструкторов ---\n";

    // Конструктор по умолчанию
    CircularDoublyLinkedList<int> list1;
    assert(list1.isEmpty() && "Конструктор по умолчанию: список должен быть пустым");
    assert(list1.getSize() == 0 && "Конструктор по умолчанию: размер должен быть 0");
    std::cout << "✓ Конструктор по умолчанию работает корректно\n";

    // Конструктор со списком инициализации
    CircularDoublyLinkedList<int> list2 = { 1, 2, 3, 4, 5 };
    assert(list2.getSize() == 5 && "Список должен содержать 5 элементов");
    assert(list2[0] == 1 && "Первый элемент должен быть 1");
    assert(list2[4] == 5 && "Последний элемент должен быть 5");
    std::cout << "✓ Конструктор со списком инициализации работает корректно\n";

    // Конструктор копирования
    CircularDoublyLinkedList<int> list3(list2);
    assert(list3.getSize() == list2.getSize() && "Размеры списков должны совпадать");
    assert(list3[2] == list2[2] && "Элементы должны совпадать");
    std::cout << "✓ Конструктор копирования работает корректно\n";

    // Конструктор перемещения
    CircularDoublyLinkedList<int> list4(std::move(list3));
    assert(list4.getSize() == 5 && "Перемещённый список должен иметь размер 5");
    assert(list3.isEmpty() && "Исходный список должен быть пустым после перемещения");
    std::cout << "✓ Конструктор перемещения работает корректно\n";
}

/**
 * @brief Функция для тестирования операторов присваивания
 */
void testAssignmentOperators() {
    std::cout << "--- Тест операторов присваивания ---\n";

    CircularDoublyLinkedList<int> list1 = { 10, 20, 30 };
    CircularDoublyLinkedList<int> list2;

    // Оператор присваивания копированием
    list2 = list1;
    assert(list2.getSize() == 3 && "Размер должен быть 3");
    assert(list2[1] == 20 && "Элемент должен быть 20");
    std::cout << "✓ Оператор присваивания копированием работает корректно\n";

    // Самоприсваивание
    list1 = list1;
    assert(list1.getSize() == 3 && "Размер не должен измениться");
    std::cout << "✓ Самоприсваивание работает корректно\n";

    // Оператор присваивания перемещением
    CircularDoublyLinkedList<int> list3;
    list3 = std::move(list2);
    assert(list3.getSize() == 3 && "Перемещённый список должен иметь размер 3");
    assert(list2.isEmpty() && "Исходный список должен быть пустым");
    std::cout << "✓ Оператор присваивания перемещением работает корректно\n";
}

/**
 * @brief Функция для тестирования вставки элементов
 */
void testInsertion() {
    std::cout << "--- Тест вставки элементов ---\n";

    CircularDoublyLinkedList<int> list;

    // push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.getSize() == 3 && "Размер должен быть 3");
    assert(list[2] == 3 && "Последний элемент должен быть 3");
    std::cout << "✓ push_back работает корректно\n";

    // push_front
    list.push_front(0);
    assert(list[0] == 0 && "Первый элемент должен быть 0");
    assert(list.getSize() == 4 && "Размер должен быть 4");
    std::cout << "✓ push_front работает корректно\n";

    // insert
    list.insert(2, 99);
    assert(list[2] == 99 && "Вставленный элемент должен быть 99");
    assert(list.getSize() == 5 && "Размер должен быть 5");
    std::cout << "✓ insert работает корректно\n";

    // insert в начало
    list.insert(0, 100);
    assert(list[0] == 100 && "Первый элемент должен быть 100");
    std::cout << "✓ insert в начало работает корректно\n";

    // insert в конец
    list.insert(list.getSize(), 200);
    assert(list[list.getSize() - 1] == 200 && "Последний элемент должен быть 200");
    std::cout << "✓ insert в конец работает корректно\n";
}

/**
 * @brief Функция для тестирования удаления элементов
 */
void testDeletion() {
    std::cout << "--- Тест удаления элементов ---\n";

    CircularDoublyLinkedList<int> list = { 1, 2, 3, 4, 5 };

    // pop_back
    list.pop_back();
    assert(list.getSize() == 4 && "Размер должен быть 4");
    assert(list[list.getSize() - 1] == 4 && "Последний элемент должен быть 4");
    std::cout << "✓ pop_back работает корректно\n";

    // pop_front
    list.pop_front();
    assert(list.getSize() == 3 && "Размер должен быть 3");
    assert(list[0] == 2 && "Первый элемент должен быть 2");
    std::cout << "✓ pop_front работает корректно\n";

    // erase
    list.erase(1);
    assert(list.getSize() == 2 && "Размер должен быть 2");
    assert(list[1] == 4 && "Элемент с индексом 1 должен быть 4");
    std::cout << "✓ erase работает корректно\n";

    // remove
    bool removed = list.remove(4);
    assert(removed && "Элемент должен быть найден и удалён");
    assert(list.getSize() == 1 && "Размер должен быть 1");
    std::cout << "✓ remove работает корректно\n";

    // Удаление до пустого списка
    list.pop_back();
    assert(list.isEmpty() && "Список должен быть пустым");
    std::cout << "✓ Удаление до пустого списка работает корректно\n";
}

/**
 * @brief Функция для тестирования поиска и модификации
 */
void testSearchAndModify() {
    std::cout << "--- Тест поиска и модификации ---\n";

    CircularDoublyLinkedList<int> list = { 10, 20, 30, 20, 50 };

    // find
    int index = list.find(20);
    assert(index == 1 && "Первое вхождение 20 должно быть на индексе 1");
    index = list.find(100);
    assert(index == -1 && "Элемент 100 не должен быть найден");
    std::cout << "✓ find работает корректно\n";

    // modify
    list.modify(2, 99);
    assert(list[2] == 99 && "Элемент должен быть изменён на 99");
    std::cout << "✓ modify работает корректно\n";

    // operator[]
    list[0] = 55;
    assert(list[0] == 55 && "Элемент должен быть изменён на 55");
    std::cout << "✓ operator[] (неконстантный) работает корректно\n";

    const CircularDoublyLinkedList<int>& constList = list;
    assert(constList[0] == 55 && "Константный доступ должен возвращать значение");
    std::cout << "✓ operator[] (константный) работает корректно\n";
}

/**
 * @brief Функция для тестирования операторов сдвига
 */
void testStreamOperators() {
    std::cout << "--- Тест операторов сдвига ---\n";

    CircularDoublyLinkedList<int> list1 = { 1, 2, 3, 4, 5 };

    // Оператор вывода
    std::ostringstream oss;
    oss << list1;
    std::string expected = "[1 <-> 2 <-> 3 <-> 4 <-> 5]";
    assert(oss.str() == expected && "Вывод должен соответствовать ожидаемому формату");
    std::cout << "✓ operator<< работает корректно\n";

    // Оператор ввода
    CircularDoublyLinkedList<int> list2;
    std::istringstream iss("10 20 30");
    iss >> list2;
    assert(list2.getSize() == 3 && "Размер должен быть 3");
    assert(list2[0] == 10 && "
