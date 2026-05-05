#include "rubric.h"
#include <algorithm>
#include <stdexcept>
#include <utility>

namespace publication {

// Статический список допустимых рубрик
static const std::vector<std::string> rubricList = {
    "Математика",
    "Физика",
    "Информатика",
    "Химия",
    "Биология",
    "История",
    "Экономика"
};

Rubric::Rubric() = default;

Rubric::Rubric(const std::string& name) : name(name) {
    if (!isValidRubric(name)) {
        throw std::invalid_argument("Недопустимое название рубрики: " + name);
    }
}

Rubric::Rubric(const Rubric& other) : name(other.name) {}

Rubric::Rubric(Rubric&& other) noexcept : name(std::move(other.name)) {}

std::string Rubric::getName() const { return name; }

const std::vector<std::string>& Rubric::getAllRubrics() {
    return rubricList;
}

bool Rubric::isValidRubric(const std::string& name) {
    const auto& list = getAllRubrics();
    return std::find(list.begin(), list.end(), name) != list.end();
}

Rubric& Rubric::operator=(const Rubric& other) {
    if (this != &other) name = other.name;
    return *this;
}

Rubric& Rubric::operator=(Rubric&& other) noexcept {
    if (this != &other) name = std::move(other.name);
    return *this;
}

bool Rubric::operator==(const Rubric& other) const {
    return name == other.name;
}

bool Rubric::operator!=(const Rubric& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rubric& rubric) {
    os << rubric.name;
    return os;
}

std::istream& operator>>(std::istream& is, Rubric& rubric) {
    std::string temp;
    std::getline(is, temp);
    if (Rubric::isValidRubric(temp)) {
        rubric.name = temp;
    } else {
        throw std::invalid_argument("Введена недопустимая рубрика: " + temp);
    }
    return is;
}

} 
