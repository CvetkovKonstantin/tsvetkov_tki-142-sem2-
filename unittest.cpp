/**
 * @file unittest.cpp
 * @brief Модульные тесты для классов библиотеки публикаций
 */

#include "../solver/person.h"
#include "../solver/rubric.h"
#include "../solver/journal.h"
#include "../solver/publication.h"
#include "../solver/journal_article.h"
#include "CppUnitTest.h"
#include <sstream>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace publication;

namespace Tests
{
    /**
     * @brief Тесты для класса Person
     */
    TEST_CLASS(PersonTests)
    {
    public:
        /// Проверка конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Person p;
            Assert::IsTrue(p.getFirstName().empty());
            Assert::IsTrue(p.getLastName().empty());
        }

        /// Проверка конструктора с обязательными полями
        TEST_METHOD(TestParameterizedConstructor)
        {
            Person p("Иван", "Иванов");
            Assert::AreEqual(std::string("Иван"), p.getFirstName());
            Assert::AreEqual(std::string("Иванов"), p.getLastName());
        }

        /// Проверка полного конструктора
        TEST_METHOD(TestFullConstructor)
        {
            Person p("Иван", "Иванов", "Иванович", "д-р", "мл.");
            Assert::AreEqual(std::string("Иван"), p.getFirstName());
            Assert::AreEqual(std::string("Иванов"), p.getLastName());
            Assert::AreEqual(std::string("Иванович"), p.getMiddleName());
            Assert::AreEqual(std::string("д-р"), p.getPrefix());
            Assert::AreEqual(std::string("мл."), p.getPostfix());
        }

        /// Проверка конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Person original("Иван", "Иванов", "Иванович", "д-р", "мл.");
            Person copy(original);
            Assert::IsTrue(original == copy);
        }

        /// Проверка конструктора перемещения
        TEST_METHOD(TestMoveConstructor)
        {
            Person original("Иван", "Иванов", "Иванович", "д-р", "мл.");
            Person moved(std::move(original));
            Assert::AreEqual(std::string("Иван"), moved.getFirstName());
            Assert::AreEqual(std::string("Иванов"), moved.getLastName());
            Assert::AreEqual(std::string("Иванович"), moved.getMiddleName());
        }

        /// Проверка оператора присваивания (копирование)
        TEST_METHOD(TestAssignmentOperator)
        {
            Person original("Иван", "Иванов");
            Person assigned;
            assigned = original;
            Assert::IsTrue(original == assigned);
        }

        /// Проверка оператора присваивания (перемещение)
        TEST_METHOD(TestMoveAssignmentOperator)
        {
            Person original("Иван", "Иванов", "Иванович", "д-р", "мл.");
            Person assigned;
            assigned = std::move(original);
            Assert::AreEqual(std::string("Иван"), assigned.getFirstName());
            Assert::AreEqual(std::string("Иванов"), assigned.getLastName());
        }

        /// Проверка самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            Person p("Иван", "Иванов");
            p = p;
            Assert::AreEqual(std::string("Иван"), p.getFirstName());
        }

        /// Проверка оператора сравнения ==
        TEST_METHOD(TestEqualityOperator)
        {
            Person p1("Иван", "Иванов");
            Person p2("Иван", "Иванов");
            Person p3("Петр", "Петров");
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        /// Проверка оператора сравнения !=
        TEST_METHOD(TestInequalityOperator)
        {
            Person p1("Иван", "Иванов");
            Person p2("Петр", "Петров");
            Assert::IsTrue(p1 != p2);
        }

        /// Проверка метода getFullName (с префиксом и постфиксом)
        TEST_METHOD(TestGetFullName)
        {
            Person p("Иван", "Иванов", "Иванович", "д-р", "мл.");
            std::string expected = "д-р Иван Иванович Иванов мл.";
            Assert::AreEqual(expected, p.getFullName());
        }

        /// Проверка getFullName без необязательных полей
        TEST_METHOD(TestGetFullNameMinimal)
        {
            Person p("Иван", "Иванов");
            std::string expected = "Иван Иванов";
            Assert::AreEqual(expected, p.getFullName());
        }

        /// Проверка оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Person p("Иван", "Иванов", "Иванович", "д-р", "мл.");
            std::stringstream ss;
            ss << p;
            std::string expected = "д-р|Иван|Иванович|Иванов|мл.";
            Assert::AreEqual(expected, ss.str());
        }

        /// Проверка оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            std::string input = "д-р|Иван|Иванович|Иванов|мл.";
            std::stringstream ss(input);
            Person p;
            ss >> p;
            Assert::AreEqual(std::string("д-р"), p.getPrefix());
            Assert::AreEqual(std::string("Иван"), p.getFirstName());
            Assert::AreEqual(std::string("Иванович"), p.getMiddleName());
            Assert::AreEqual(std::string("Иванов"), p.getLastName());
            Assert::AreEqual(std::string("мл."), p.getPostfix());
        }
    };

    /**
     * @brief Тесты для класса Rubric
     */
    TEST_CLASS(RubricTests)
    {
    public:
        /// Проверка конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Rubric r;
            Assert::IsTrue(r.getName().empty());
        }

        /// Проверка конструктора с допустимой рубрикой
        TEST_METHOD(TestValidRubricConstructor)
        {
            Rubric r("Математика");
            Assert::AreEqual(std::string("Математика"), r.getName());
        }

        /// Проверка конструктора с недопустимой рубрикой (ожидается исключение)
        TEST_METHOD(TestInvalidRubricConstructorThrows)
        {
            auto func = []() { Rubric r("Астрономия"); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        /// Проверка конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Rubric original("Физика");
            Rubric copy(original);
            Assert::IsTrue(original == copy);
        }

        /// Проверка конструктора перемещения
        TEST_METHOD(TestMoveConstructor)
        {
            Rubric original("Химия");
            Rubric moved(std::move(original));
            Assert::AreEqual(std::string("Химия"), moved.getName());
        }

        /// Проверка статического метода getAllRubrics
        TEST_METHOD(TestGetAllRubrics)
        {
            const auto& list = Rubric::getAllRubrics();
            Assert::IsTrue(list.size() > 0);
            Assert::IsTrue(std::find(list.begin(), list.end(), "Математика") != list.end());
        }

        /// Проверка статического метода isValidRubric
        TEST_METHOD(TestIsValidRubric)
        {
            Assert::IsTrue(Rubric::isValidRubric("Биология"));
            Assert::IsFalse(Rubric::isValidRubric("Астрология"));
        }

        /// Проверка оператора присваивания
        TEST_METHOD(TestAssignmentOperator)
        {
            Rubric r1("Информатика");
            Rubric r2;
            r2 = r1;
            Assert::IsTrue(r1 == r2);
        }

        /// Проверка оператора сравнения ==
        TEST_METHOD(TestEqualityOperator)
        {
            Rubric r1("История");
            Rubric r2("История");
            Rubric r3("Экономика");
            Assert::IsTrue(r1 == r2);
            Assert::IsFalse(r1 == r3);
        }

        /// Проверка оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Rubric r("Физика");
            std::stringstream ss;
            ss << r;
            Assert::AreEqual(std::string("Физика"), ss.str());
        }

        /// Проверка оператора ввода >> (допустимая рубрика)
        TEST_METHOD(TestInputStreamOperatorValid)
        {
            std::string input = "Математика";
            std::stringstream ss(input);
            Rubric r;
            ss >> r;
            Assert::AreEqual(std::string("Математика"), r.getName());
        }

        /// Проверка оператора ввода >> (недопустимая рубрика, исключение)
        TEST_METHOD(TestInputStreamOperatorInvalidThrows)
        {
            std::string input = "География";
            std::stringstream ss(input);
            Rubric r;
            auto func = [&]() { ss >> r; };
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };

    /**
     * @brief Тесты для класса Journal
     */
    TEST_CLASS(JournalTests)
    {
    public:
        /// Проверка конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Journal j;
            Assert::IsTrue(j.getName().empty());
        }

        /// Проверка конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Rubric r("Биология");
            Journal j("Природа", r);
            Assert::AreEqual(std::string("Природа"), j.getName());
            Assert::IsTrue(r == j.getRubricator());
        }

        /// Проверка конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Journal original("Наука", Rubric("Химия"));
            Journal copy(original);
            Assert::IsTrue(original == copy);
        }

        /// Проверка конструктора перемещения
        TEST_METHOD(TestMoveConstructor)
        {
            Journal original("Вестник", Rubric("Физика"));
            Journal moved(std::move(original));
            Assert::AreEqual(std::string("Вестник"), moved.getName());
            Assert::AreEqual(std::string("Физика"), moved.getRubricator().getName());
        }

        /// Проверка оператора присваивания
        TEST_METHOD(TestAssignmentOperator)
        {
            Journal j1("Журнал", Rubric("Математика"));
            Journal j2;
            j2 = j1;
            Assert::IsTrue(j1 == j2);
        }

        /// Проверка оператора сравнения ==
        TEST_METHOD(TestEqualityOperator)
        {
            Journal j1("А", Rubric("Информатика"));
            Journal j2("А", Rubric("Информатика"));
            Journal j3("Б", Rubric("Информатика"));
            Assert::IsTrue(j1 == j2);
            Assert::IsFalse(j1 == j3);
        }

        /// Проверка оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Journal j("Квант", Rubric("Физика"));
            std::stringstream ss;
            ss << j;
            Assert::AreEqual(std::string("Квант|Физика"), ss.str());
        }

        /// Проверка оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            std::string input = "Природа|Биология";
            std::stringstream ss(input);
            Journal j;
            ss >> j;
            Assert::AreEqual(std::string("Природа"), j.getName());
            Assert::AreEqual(std::string("Биология"), j.getRubricator().getName());
        }
    };

    /**
     * @brief Тесты для классов Publication и JournalArticle
     */
    TEST_CLASS(PublicationTests)
    {
    public:
        /// Проверка конструктора JournalArticle по умолчанию
        TEST_METHOD(TestJournalArticleDefaultConstructor)
        {
            JournalArticle article;
            Assert::IsTrue(article.getTitle().empty());
            Assert::AreEqual(0, article.getYear());
        }

        /// Проверка конструктора JournalArticle с параметрами
        TEST_METHOD(TestJournalArticleParameterizedConstructor)
        {
            std::vector<Person> authors = { Person("Иван", "Иванов") };
            Journal journal("Наука", Rubric("Физика"));
            Rubric rubric("Математика");
            JournalArticle article(authors, "Тестовая статья", 2023, journal, rubric);

            Assert::AreEqual(size_t(1), article.getAuthors().size());
            Assert::AreEqual(std::string("Тестовая статья"), article.getTitle());
            Assert::AreEqual(2023, article.getYear());
            Assert::IsTrue(journal == article.getJournal());
            Assert::IsTrue(rubric == article.getRubric());
        }

        /// Проверка конструктора копирования JournalArticle
        TEST_METHOD(TestJournalArticleCopyConstructor)
        {
            JournalArticle original(
                { Person("А", "Б") }, "Статья", 2024,
                Journal("Журнал", Rubric("Химия")), Rubric("Биология"));
            JournalArticle copy(original);
            Assert::IsTrue(original == copy);
        }

        /// Проверка конструктора перемещения JournalArticle
        TEST_METHOD(TestJournalArticleMoveConstructor)
        {
            JournalArticle original(
                { Person("А", "Б") }, "Статья", 2024,
                Journal("Журнал", Rubric("Химия")), Rubric("Биология"));
            JournalArticle moved(std::move(original));
            Assert::AreEqual(std::string("Статья"), moved.getTitle());
        }

        /// Проверка оператора присваивания JournalArticle
        TEST_METHOD(TestJournalArticleAssignment)
        {
            JournalArticle a1({ Person("А", "Б") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            JournalArticle a2;
            a2 = a1;
            Assert::IsTrue(a1 == a2);
        }

        /// Проверка оператора сравнения == JournalArticle
        TEST_METHOD(TestJournalArticleEquality)
        {
            JournalArticle a1({ Person("А", "Б") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            JournalArticle a2({ Person("А", "Б") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            JournalArticle a3({ Person("В", "Г") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            Assert::IsTrue(a1 == a2);
            Assert::IsFalse(a1 == a3);
        }

        /// Проверка метода ToString JournalArticle
        TEST_METHOD(TestJournalArticleToString)
        {
            std::vector<Person> authors = { Person("Иван", "Иванов") };
            JournalArticle article(authors, "Заголовок", 2023,
                Journal("Журнал", Rubric("Информатика")), Rubric("Математика"));
            std::string str = article.ToString();
            Assert::IsTrue(str.find("JournalArticle") != std::string::npos);
            Assert::IsTrue(str.find("Иван Иванов") != std::string::npos);
            Assert::IsTrue(str.find("Заголовок") != std::string::npos);
            Assert::IsTrue(str.find("2023") != std::string::npos);
        }

        /// Проверка оператора вывода << для JournalArticle
        TEST_METHOD(TestJournalArticleOutputStream)
        {
            JournalArticle article(
                { Person("Иван", "Иванов") }, "Статья", 2022,
                Journal("Ж", Rubric("Физика")), Rubric("Химия"));
            std::stringstream ss;
            ss << article;
            std::string out = ss.str();
            Assert::IsTrue(out.find("Иван|") != std::string::npos || out.find("Иван") != std::string::npos);
            Assert::IsTrue(out.find("Статья") != std::string::npos);
            Assert::IsTrue(out.find("2022") != std::string::npos);
        }

        /// Проверка оператора ввода >> для JournalArticle
        TEST_METHOD(TestJournalArticleInputStream)
        {
            std::string input =
                "1\n"
                "|Иван||Иванов|\n"
                "Тестовая статья\n"
                "2023\n"
                "Наука|Биология\n"
                "Химия\n";
            std::stringstream ss(input);
            JournalArticle article;
            ss >> article;

            Assert::AreEqual(size_t(1), article.getAuthors().size());
            Assert::AreEqual(std::string("Тестовая статья"), article.getTitle());
            Assert::AreEqual(2023, article.getYear());
            Assert::AreEqual(std::string("Наука"), article.getJournal().getName());
            Assert::AreEqual(std::string("Биология"), article.getJournal().getRubricator().getName());
            Assert::AreEqual(std::string("Химия"), article.getRubric().getName());
        }

        /// Проверка статического метода Publication::readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input =
                "2\n"
                "д-р|Иван|Иванович|Иванов|\n"
                "|Петр||Петров|мл.\n"
                "Полиморфизм в C++\n"
                "2024\n"
                "Программист|Информатика\n"
                "Математика\n";
            std::stringstream ss(input);
            auto pub = Publication::readFromStream(ss);
            Assert::IsNotNull(pub.get());
            std::string str = pub->ToString();
            Assert::IsTrue(str.find("Полиморфизм в C++") != std::string::npos);
        }

        /// Проверка полиморфизма через базовый класс
        TEST_METHOD(TestPolymorphism)
        {
            std::unique_ptr<Publication> pub = std::make_unique<JournalArticle>(
                std::vector<Person>{Person("А", "Б")},
                "Статья", 2025,
                Journal("Ж", Rubric("Физика")),
                Rubric("Математика")
            );
            std::string str = pub->ToString();
            Assert::IsTrue(str.find("JournalArticle") != std::string::npos);
        }

        /// Проверка сеттеров и геттеров
        TEST_METHOD(TestSettersAndGetters)
        {
            JournalArticle article;
            std::vector<Person> authors = { Person("Сеттер", "Тестов") };
            article.setAuthors(authors);
            article.setTitle("Новый заголовок");
            article.setYear(2030);
            article.setJournal(Journal("Новый журнал", Rubric("Экономика")));
            article.setRubric(Rubric("История"));

            Assert::AreEqual(size_t(1), article.getAuthors().size());
            Assert::AreEqual(std::string("Новый заголовок"), article.getTitle());
            Assert::AreEqual(2030, article.getYear());
            Assert::AreEqual(std::string("Новый журнал"), article.getJournal().getName());
            Assert::AreEqual(std::string("История"), article.getRubric().getName());
        }

        /// Проверка сравнения JournalArticle с разными авторами
        TEST_METHOD(TestComparisonDifferentAuthors)
        {
            JournalArticle a1({ Person("А", "Б") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            JournalArticle a2({ Person("А", "Б"), Person("В", "Г") }, "Т", 2020,
                Journal("Ж", Rubric("Физика")), Rubric("Математика"));
            Assert::IsFalse(a1 == a2);
        }

        /// Проверка десериализации после сериализации (round-trip)
        TEST_METHOD(TestSerializationRoundTrip)
        {
            JournalArticle original(
                { Person("Иван", "Иванов", "Иванович", "д-р", "") },
                "Тест сериализации", 2025,
                Journal("Наука и жизнь", Rubric("Биология")),
                Rubric("Химия")
            );
            std::stringstream ss;
            ss << original;

            JournalArticle restored;
            ss >> restored;

            Assert::IsTrue(original == restored);
        }

        /// Проверка ToString при пустом списке авторов
        TEST_METHOD(TestToStringEmptyAuthors)
        {
            JournalArticle article({}, "Без авторов", 2024,
                Journal("Ж", Rubric("Математика")), Rubric("Физика"));
            std::string str = article.ToString();
            Assert::IsTrue(str.find("authors={}") != std::string::npos);
        }
    };
}
