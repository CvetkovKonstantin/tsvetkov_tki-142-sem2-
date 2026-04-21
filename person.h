#pragma once
#include <iostream>
#include <string>

namespace publication {

/**
 * @brief Класс, представляющий персону (автора)
 */
class Person {
private:
    std::string firstName;   ///< Имя
    std::string lastName;    ///< Фамилия
    std::string middleName;  ///< Отчество (необязательное)
    std::string prefix;      ///< Префикс (необязательное)
    std::string postfix;     ///< Постфикс (необязательное)

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Person();

    /**
     * @brief Конструктор с обязательными полями
     * @param firstName Имя
     * @param lastName Фамилия
     */
    Person(const std::string& firstName, const std::string& lastName);

    /**
     * @brief Полный конструктор
     * @param firstName Имя
     * @param lastName Фамилия
     * @param middleName Отчество
     * @param prefix Префикс
     * @param postfix Постфикс
     */
    Person(const std::string& firstName, const std::string& lastName,
           const std::string& middleName, const std::string& prefix,
           const std::string& postfix);

    /**
     * @brief Конструктор копирования
     * @param other Другой объект Person
     */
    Person(const Person& other);

    /**
     * @brief Конструктор перемещения
     * @param other Другой объект Person
     */
    Person(Person&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~Person() = default;

    /**
     * @brief Получить имя
     * @return Имя
     */
    std::string getFirstName() const;

    /**
     * @brief Получить фамилию
     * @return Фамилия
     */
    std::string getLastName() const;

    /**
     * @brief Получить отчество
     * @return Отчество
     */
    std::string getMiddleName() const;

    /**
     * @brief Получить префикс
     * @return Префикс
     */
    std::string getPrefix() const;

    /**
     * @brief Получить постфикс
     * @return Постфикс
     */
    std::string getPostfix() const;

    /**
     * @brief Получение полного имени в формате "Префикс Имя Отчество Фамилия Постфикс"
     * @return Полное имя
     */
    std::string getFullName() const;

    /**
     * @brief Оператор присваивания (копирование)
     * @param other Другой объект Person
     * @return Ссылка на текущий объект
     */
    Person& operator=(const Person& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other Другой объект Person
     * @return Ссылка на текущий объект
     */
    Person& operator=(Person&& other) noexcept;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другой объект Person
     * @return true, если объекты равны
     */
    bool operator==(const Person& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другой объект Person
     * @return true, если объекты не равны
     */
    bool operator!=(const Person& other) const;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param person Объект Person
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param person Объект Person
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Person& person);
};

} 
