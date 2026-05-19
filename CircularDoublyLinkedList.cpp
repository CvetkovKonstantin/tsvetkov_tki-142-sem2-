#include "CircularDoublyLinkedList.h"
#include <stdexcept>

namespace containers {

    // Конструктор по умолчанию
    template<typename T>
    CircularDoublyLinkedList<T>::CircularDoublyLinkedList() : head(nullptr), size(0) {}

    // Конструктор со списком инициализации
    template<typename T>
    CircularDoublyLinkedList<T>::CircularDoublyLinkedList(const std::initializer_list<T>& init)
        : head(nullptr), size(0) {
        for (const auto& value : init) {
            push_back(value);
        }
    }

    // Конструктор копирования
    template<typename T>
    CircularDoublyLinkedList<T>::CircularDoublyLinkedList(const CircularDoublyLinkedList<T>& other)
        : head(nullptr), size(0) {
        copyFrom(other);
    }

    // Конструктор перемещения
    template<typename T>
    CircularDoublyLinkedList<T>::CircularDoublyLinkedList(CircularDoublyLinkedList<T>&& other) noexcept
        : head(other.head), size(other.size) {
        other.head = nullptr;
        other.size = 0;
    }

    // Деструктор
    template<typename T>
    CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
        clear();
    }

    // Оператор присваивания копированием
    template<typename T>
    CircularDoublyLinkedList<T>& CircularDoublyLinkedList<T>::operator=(const CircularDoublyLinkedList<T>& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    // Оператор присваивания перемещением
    template<typename T>
    CircularDoublyLinkedList<T>& CircularDoublyLinkedList<T>::operator=(CircularDoublyLinkedList<T>&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            size = other.size;
            other.head = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Оператор вывода в поток
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const CircularDoublyLinkedList<T>& list) {
        os << list.ToString();
        return os;
    }

    // Оператор ввода из потока
    template<typename T>
    std::istream& operator>>(std::istream& is, CircularDoublyLinkedList<T>& list) {
        list.clear();
        T value;
        while (is >> value) {
            list.push_back(value);
            if (is.peek() == '\n' || is.peek() == EOF) break;
        }
        return is;
    }

    // Вспомогательный метод копирования
    template<typename T>
    void CircularDoublyLinkedList<T>::copyFrom(const CircularDoublyLinkedList<T>& other) {
        if (other.isEmpty()) return;

        Node<T>* current = other.head;
        do {
            push_back(current->data);
            current = current->next;
        } while (current != other.head);
    }

    // Добавление в конец
    template<typename T>
    void CircularDoublyLinkedList<T>::push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node<T>* tail = head->prev;

            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        ++size;
    }

    // Добавление в начало
    template<typename T>
    void CircularDoublyLinkedList<T>::push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node<T>* tail = head->prev;

            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    // Вставка по индексу
    template<typename T>
    void CircularDoublyLinkedList<T>::insert(const size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            push_front(value);
            return;
        }
        if (index == size) {
            push_back(value);
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* prevNode = current->prev;

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;

        ++size;
    }

    // Удаление с конца
    template<typename T>
    void CircularDoublyLinkedList<T>::pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* tail = head->prev;
            Node<T>* newTail = tail->prev;

            newTail->next = head;
            head->prev = newTail;

            delete tail;
        }
        --size;
    }

    // Удаление с начала
    template<typename T>
    void CircularDoublyLinkedList<T>::pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* newHead = head->next;
            Node<T>* tail = head->prev;

            tail->next = newHead;
            newHead->prev = tail;

            delete head;
            head = newHead;
        }
        --size;
    }

    // Удаление по индексу
    template<typename T>
    void CircularDoublyLinkedList<T>::erase(const size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == size - 1) {
            pop_back();
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;

        --size;
    }

    // Удаление по значению
    template<typename T>
    bool CircularDoublyLinkedList<T>::remove(const T& value) {
        int index = find(value);
        if (index != -1) {
            erase(static_cast<size_t>(index));
            return true;
        }
        return false;
    }

    // Поиск элемента
    template<typename T>
    int CircularDoublyLinkedList<T>::find(const T& value) const {
        if (isEmpty()) return -1;

        Node<T>* current = head;
        size_t index = 0;
        do {
            if (current->data == value) {
                return static_cast<int>(index);
            }
            current = current->next;
            ++index;
        } while (current != head);

        return -1;
    }

    // Изменение элемента
    template<typename T>
    void CircularDoublyLinkedList<T>::modify(const size_t index, const T& value) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    // Оператор индексирования (неконстантный)
    template<typename T>
    T& CircularDoublyLinkedList<T>::operator[](const size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Оператор индексирования (константный)
    template<typename T>
    const T& CircularDoublyLinkedList<T>::operator[](const size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Получение размера
    template<typename T>
    size_t CircularDoublyLinkedList<T>::getSize() const {
        return size;
    }

    // Проверка на пустоту
    template<typename T>
    bool CircularDoublyLinkedList<T>::isEmpty() const {
        return size == 0;
    }

    // Очистка списка
    template<typename T>
    void CircularDoublyLinkedList<T>::clear() {
        if (isEmpty()) return;

        Node<T>* current = head;
        do {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);

        head = nullptr;
        size = 0;
    }

    // Сериализация в строку
    template<typename T>
    std::string CircularDoublyLinkedList<T>::ToString() const {
        if (isEmpty()) {
            return "[]";
        }

        std::stringstream ss;
        ss << "[";

        Node<T>* current = head;
        do {
            ss << current->data;
            if (current->next != head) {
                ss << " <-> ";
            }
            current = current->next;
        } while (current != head);

        ss << "]";
        return ss.str();
    }

    // Получение головы списка
    template<typename T>
    Node<T>* CircularDoublyLinkedList<T>::getHead() const {
        return head;
    }

    // Явная инстанциация для типа int
    template class CircularDoublyLinkedList<int>;
    template std::ostream& operator<<(std::ostream&, const CircularDoublyLinkedList<int>&);
    template std::istream& operator>>(std::istream&, CircularDoublyLinkedList<int>&);

}
