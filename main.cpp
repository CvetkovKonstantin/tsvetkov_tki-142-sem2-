/**
 * @file main.cpp
 * @brief Демонстрация работы библиотеки публикаций
 */

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <clocale>
#include "person.h"
#include "rubric.h"
#include "journal.h"
#include "publication.h"
#include "journal_article.h"

using namespace publication;

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 */
int main() {
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "=== Демонстрация работы с публикациями ===\n\n";

        // 1. Создание авторов (класс Person)
        std::cout << "1. Создание авторов:\n";
        Person author1("Иван", "Иванов", "Иванович", "д-р", "");
        Person author2("Петр", "Петров", "", "", "мл.");
        Person author3("Мария", "Сидорова", "Алексеевна", "проф.", "");

        std::cout << "Автор 1: " << author1 << " -> " << author1.getFullName() << "\n";
        std::cout << "Автор 2: " << author2 << " -> " << author2.getFullName() << "\n";
        std::cout << "Автор 3: " << author3 << " -> " << author3.getFullName() << "\n\n";

        // 2. Работа с рубриками
        std::cout << "2. Доступные рубрики:\n";
        for (const auto& r : Rubric::getAllRubrics()) {
            std::cout << " - " << r << "\n";
        }
        Rubric rubricMath("Математика");
        Rubric rubricPhys("Физика");
        std::cout << "Выбраны рубрики: " << rubricMath << ", " << rubricPhys << "\n\n";

        // 3. Создание журнала
        std::cout << "3. Создание журнала:\n";
        Journal journal("Вестник науки", rubricMath);
        std::cout << "Журнал: " << journal << "\n\n";

        // 4. Создание статьи в журнале
        std::cout << "4. Создание статьи:\n";
        std::vector<Person> authors = { author1, author2 };
        JournalArticle article(authors, "Применение нейронных сетей в прогнозировании",
                               2023, journal, rubricPhys);
        std::cout << article.ToString() << "\n\n";

        // 5. Полиморфизм: коллекция публикаций
        std::cout << "5. Коллекция публикаций (полиморфизм):\n";
        std::vector<std::unique_ptr<Publication>> publications;
        publications.push_back(std::make_unique<JournalArticle>(article));

        std::vector<Person> authors2 = { author3 };
        JournalArticle article2(authors2, "Квантовые вычисления: современное состояние",
                                2024, journal, rubricMath);
        publications.push_back(std::make_unique<JournalArticle>(article2));

        for (size_t i = 0; i < publications.size(); ++i) {
            std::cout << "Публикация " << i + 1 << ":\n"
                      << publications[i]->ToString() << "\n\n";
        }

        // 6. Сериализация и десериализация
        std::cout << "6. Проверка сериализации/десериализации:\n";
        std::stringstream ss;
        ss << article;
        std::cout << "Сериализованное представление:\n" << ss.str() << "\n";

        JournalArticle newArticle;
        ss >> newArticle;
        std::cout << "Восстановленная статья:\n" << newArticle.ToString() << "\n\n";

        // 7. Статический метод readFromStream
        std::cout << "7. Демонстрация статического метода readFromStream:\n";
        std::cout << "Введите данные статьи в формате:\n";
        std::cout << "<количество авторов>\n";
        std::cout << "<префикс>|<имя>|<отчество>|<фамилия>|<постфикс> (для каждого автора)\n";
        std::cout << "<название>\n<год>\n<журнал>|<рубрикатор>\n<рубрика>\n\n";
        std::cout << "Для автоматического теста ввод пропущен.\n";

        std::cout << "Программа завершена успешно.\n";

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
