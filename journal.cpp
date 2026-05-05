#include "journal.h"
#include <utility>

namespace publication {

Journal::Journal() = default;

Journal::Journal(const std::string& name, const Rubric& rubricator)
    : name(name), rubricator(rubricator) {}

Journal::Journal(const Journal& other)
    : name(other.name), rubricator(other.rubricator) {}

Journal::Journal(Journal&& other) noexcept
    : name(std::move(other.name)), rubricator(std::move(other.rubricator)) {}

std::string Journal::getName() const { return name; }
Rubric Journal::getRubricator() const { return rubricator; }

Journal& Journal::operator=(const Journal& other) {
    if (this != &other) {
        name = other.name;
        rubricator = other.rubricator;
    }
    return *this;
}

Journal& Journal::operator=(Journal&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        rubricator = std::move(other.rubricator);
    }
    return *this;
}

bool Journal::operator==(const Journal& other) const {
    return name == other.name && rubricator == other.rubricator;
}

bool Journal::operator!=(const Journal& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Journal& journal) {
    os << journal.name << "|" << journal.rubricator;
    return os;
}

std::istream& operator>>(std::istream& is, Journal& journal) {
    std::getline(is, journal.name, '|');
    is >> journal.rubricator;
    return is;
}

} 
