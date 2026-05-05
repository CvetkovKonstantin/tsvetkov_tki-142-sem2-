#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "person.h"

namespace publication {

/**
 * @brief Абстрактный базовый класс "Публикация"
 */
class Publication {
protected:
    std::vector<Person> authors; ///< Список авторов
    std::string title;           ///< Название публикации
    int year;                    ///< Год издания

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Publication();

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Publication() = default;

    /**
     * @brief Сериализация объекта в строку
     * @return Строковое представление публикации
     */
    virtual std::string ToString() const = 0;

    /**
     * @brief Статический метод чтения публикации из потока
     * @param is Входной поток
     * @return Умный указатель на созданную публикацию
     */
    static std::unique_ptr<Publication> readFromStream(std::istream& is);

    /**
     * @brief Получить список авторов
     * @return Вектор авторов
     */
    std::vector<Person> getAuthors() const;

    /**
     * @brief Получить название публикации
     * @return Название
     */
    std::string getTitle() const;

    /**
     * @brief Получить год издания
     * @return Год
     */
    int getYear() const;

    /**
     * @brief Установить список авторов
     * @param authors Новый список авторов
     */
    void setAuthors(const std::vector<Person>& authors);

    /**
     * @brief Установить название публикации
     * @param title Новое название
     */
    void setTitle(const std::string& title);

    /**
     * @brief Установить год издания
     * @param year Новый год
     */
    void setYear(const int year);

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param pub Публикация
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Publication& pub);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param pub Публикация
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, Publication& pub);
};

} 
