#include "journal_article.h"
#include <sstream>
#include <utility>

namespace publication {

JournalArticle::JournalArticle() = default;

JournalArticle::JournalArticle(const std::vector<Person>& authors,
                               const std::string& title, int year,
                               const Journal& journal, const Rubric& rubric)
    : journal(journal), rubric(rubric) {
    this->authors = authors;
    this->title = title;
    this->year = year;
}

JournalArticle::JournalArticle(const JournalArticle& other)
    : Publication(other), journal(other.journal), rubric(other.rubric) {}

JournalArticle::JournalArticle(JournalArticle&& other) noexcept
    : Publication(std::move(other)),
      journal(std::move(other.journal)),
      rubric(std::move(other.rubric)) {}

Journal JournalArticle::getJournal() const { return journal; }
Rubric JournalArticle::getRubric() const { return rubric; }

void JournalArticle::setJournal(const Journal& journal) {
    this->journal = journal;
}

void JournalArticle::setRubric(const Rubric& rubric) {
    this->rubric = rubric;
}

JournalArticle& JournalArticle::operator=(const JournalArticle& other) {
    if (this != &other) {
        Publication::operator=(other);
        journal = other.journal;
        rubric = other.rubric;
    }
    return *this;
}

JournalArticle& JournalArticle::operator=(JournalArticle&& other) noexcept {
    if (this != &other) {
        Publication::operator=(std::move(other));
        journal = std::move(other.journal);
        rubric = std::move(other.rubric);
    }
    return *this;
}

bool JournalArticle::operator==(const JournalArticle& other) const {
    return authors == other.authors &&
           title == other.title &&
           year == other.year &&
           journal == other.journal &&
           rubric == other.rubric;
}

bool JournalArticle::operator!=(const JournalArticle& other) const {
    return !(*this == other);
}

std::string JournalArticle::ToString() const {
    std::stringstream ss;
    ss << "JournalArticle[";
    ss << "authors={";
    for (size_t i = 0; i < authors.size(); ++i) {
        if (i > 0) ss << ", ";
        ss << authors[i].getFullName();
    }
    ss << "}, title=\"" << title << "\", year=" << year
       << ", journal=" << journal << ", rubric=" << rubric << "]";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const JournalArticle& article) {
    os << article.authors.size() << "\n";
    for (const auto& author : article.authors) {
        os << author << "\n";
    }
    os << article.title << "\n"
       << article.year << "\n"
       << article.journal << "\n"
       << article.rubric << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, JournalArticle& article) {
    size_t authorCount;
    is >> authorCount;
    is.ignore(); 

    article.authors.clear();
    for (size_t i = 0; i < authorCount; ++i) {
        Person p;
        is >> p;
        is.ignore();
        article.authors.push_back(p);
    }

    std::getline(is, article.title);
    is >> article.year;
    is.ignore(); 
    is >> article.journal;
    is.ignore(); 
    is >> article.rubric;
    is.ignore(); 
    return is;
}

} 
