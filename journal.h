#pragma once
#include <iostream>
#include <string>
#include "rubric.h"

namespace publication {

/**
 * @brief Класс, представляющий журнал
 */
class Journal {
private:
    std::string name;     ///< Название журнала
    Rubric rubricator;    ///< Рубрикатор журнала (основная рубрика)

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Journal();

    /**
     * @brief Конструктор с параметрами
     * @param name Название журнала
     * @param rubricator Рубрикатор
     */
    Journal(const std::string& name, const Rubric& rubricator);

    /**
     * @brief Конструктор копирования
     * @param other Другой объект Journal
     */
    Journal(const Journal& other);

    /**
     * @brief Конструктор перемещения
     * @param other Другой объект Journal
     */
    Journal(Journal&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~Journal() = default;

    /**
     * @brief Получить название журнала
     * @return Название
     */
    std::string getName() const;

    /**
     * @brief Получить рубрикатор журнала
     * @return Рубрикатор
     */
    Rubric getRubricator() const;

    /**
     * @brief Оператор присваивания (копирование)
     * @param other Другой объект Journal
     * @return Ссылка на текущий объект
     */
    Journal& operator=(const Journal& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other Другой объект Journal
     * @return Ссылка на текущий объект
     */
    Journal& operator=(Journal&& other) noexcept;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другой объект Journal
     * @return true, если объекты равны
     */
    bool operator==(const Journal& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другой объект Journal
     * @return true, если объекты не равны
     */
    bool operator!=(const Journal& other) const;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param journal Объект Journal
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Journal& journal);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param journal Объект Journal
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Journal& journal);
};

} 
