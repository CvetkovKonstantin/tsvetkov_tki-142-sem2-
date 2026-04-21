#include "publication.h"
#include "journal_article.h"

namespace publication {

Publication::Publication() : year(0) {}

std::vector<Person> Publication::getAuthors() const { return authors; }
std::string Publication::getTitle() const { return title; }
int Publication::getYear() const { return year; }

void Publication::setAuthors(const std::vector<Person>& authors) {
    this->authors = authors;
}

void Publication::setTitle(const std::string& title) {
    this->title = title;
}

void Publication::setYear(int year) {
    this->year = year;
}

std::unique_ptr<Publication> Publication::readFromStream(std::istream& is) {
    auto article = std::make_unique<JournalArticle>();
    is >> *article;
    return article;
}

std::ostream& operator<<(std::ostream& os, const Publication& pub) {
    os << pub.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Publication& pub) {
    return is;
}

} 
