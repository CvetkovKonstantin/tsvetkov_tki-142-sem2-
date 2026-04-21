#pragma once
#include "publication.h"
#include "journal.h"
#include "rubric.h"

namespace publication {

/**
 * @brief Класс "Статья в журнале", наследник Publication
 */
class JournalArticle : public Publication {
private:
    Journal journal; ///< Журнал, в котором опубликована статья
    Rubric rubric;   ///< Рубрика статьи

public:
    /**
     * @brief Конструктор по умолчанию
     */
    JournalArticle();

    /**
     * @brief Конструктор с параметрами
     * @param authors Список авторов
     * @param title Название статьи
     * @param year Год издания
     * @param journal Журнал
     * @param rubric Рубрика статьи
     */
    JournalArticle(const std::vector<Person>& authors, const std::string& title,
                   int year, const Journal& journal, const Rubric& rubric);

    /**
     * @brief Конструктор копирования
     * @param other Другой объект JournalArticle
     */
    JournalArticle(const JournalArticle& other);

    /**
     * @brief Конструктор перемещения
     * @param other Другой объект JournalArticle
     */
    JournalArticle(JournalArticle&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~JournalArticle() = default;

    /**
     * @brief Получить журнал
     * @return Объект Journal
     */
    Journal getJournal() const;

    /**
     * @brief Получить рубрику статьи
     * @return Объект Rubric
     */
    Rubric getRubric() const;

    /**
     * @brief Установить журнал
     * @param journal Новый журнал
     */
    void setJournal(const Journal& journal);

    /**
     * @brief Установить рубрику статьи
     * @param rubric Новая рубрика
     */
    void setRubric(const Rubric& rubric);

    /**
     * @brief Оператор присваивания (копирование)
     * @param other Другой объект JournalArticle
     * @return Ссылка на текущий объект
     */
    JournalArticle& operator=(const JournalArticle& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other Другой объект JournalArticle
     * @return Ссылка на текущий объект
     */
    JournalArticle& operator=(JournalArticle&& other) noexcept;

    /**
     * @brief Оператор сравнения на равенство
     * @param other Другой объект JournalArticle
     * @return true, если объекты равны
     */
    bool operator==(const JournalArticle& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другой объект JournalArticle
     * @return true, если объекты не равны
     */
    bool operator!=(const JournalArticle& other) const;

    /**
     * @brief Сериализация в строку
     * @return Строковое представление статьи
     */
    std::string ToString() const override;

    /**
     * @brief Оператор вывода в поток
     * @param os Выходной поток
     * @param article Объект JournalArticle
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const JournalArticle& article);

    /**
     * @brief Оператор ввода из потока
     * @param is Входной поток
     * @param article Объект JournalArticle
     * @return Ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, JournalArticle& article);
};

} 
