#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace publication {

/**
 * @brief Класс, представляющий рубрику
 */
class Rubric {
private:
    std::string name; ///< Название рубрики

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Rubric();

    /**
     * @brief Конструктор с названием
     * @param name Название рубрики
     * @throw std::invalid_argument если рубрика недопустима
     */
    explicit Rubric(const std::string& name);

    /**
     * @brief Конструктор копирования
     * @param other Другой объект Rubric
     */
    Rubric(const Rubric& other);

    /**
     * @brief Конструктор перемещения
     * @param other Другой объект Rubric
     */
    Rubric(Rubric&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~Rubric() = default;

    /**
     * @brief Получить название рубрики
     * @return Название рубрики
     */
    std::string getName() const;

    /**
     * @brief Статический метод, возвращающий список всех возможных рубрик
     * @return Вектор названий рубрик
     */
    static const std::vector<std::string>& getAllRubrics();

    /**
     * @brief Проверка, существует ли рубрика с таким названием
     * @param name Название рубрики
     * @return true, если рубрика допустима
     */
    static bool isValidRubric(const std::string& name);

    /**
     * @brief Оператор присваивания (копирование)
     * @param other Другой объект Rubric
     * @return Ссылка на текущий объект
     */
    Rubric& operator=(const Rubric& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other Другой объект Rubric
     * @return Ссылка на текущий объект
     */
    Rubric& operator=(Rubric&& other) noexcept;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другой объект Rubric
     * @return true, если объекты равны
     */
    bool operator==(const Rubric& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другой объект Rubric
     * @return true, если объекты не равны
     */
    bool operator!=(const Rubric& other) const;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param rubric Объект Rubric
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Rubric& rubric);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param rubric Объект Rubric
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Rubric& rubric);
};

} 
