#include "person.h"
#include <sstream>
#include <utility>

namespace publication {

Person::Person() = default;

Person::Person(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), lastName(lastName) {}

Person::Person(const std::string& firstName, const std::string& lastName,
               const std::string& middleName, const std::string& prefix,
               const std::string& postfix)
    : firstName(firstName), lastName(lastName), middleName(middleName),
      prefix(prefix), postfix(postfix) {}

Person::Person(const Person& other)
    : firstName(other.firstName), lastName(other.lastName),
      middleName(other.middleName), prefix(other.prefix), postfix(other.postfix) {}

Person::Person(Person&& other) noexcept
    : firstName(std::move(other.firstName)),
      lastName(std::move(other.lastName)),
      middleName(std::move(other.middleName)),
      prefix(std::move(other.prefix)),
      postfix(std::move(other.postfix)) {}

std::string Person::getFirstName() const { return firstName; }
std::string Person::getLastName() const { return lastName; }
std::string Person::getMiddleName() const { return middleName; }
std::string Person::getPrefix() const { return prefix; }
std::string Person::getPostfix() const { return postfix; }

std::string Person::getFullName() const {
    std::stringstream ss;
    if (!prefix.empty()) ss << prefix << " ";
    if (!firstName.empty()) ss << firstName << " ";
    if (!middleName.empty()) ss << middleName << " ";
    if (!lastName.empty()) ss << lastName;
    if (!postfix.empty()) ss << " " << postfix;
    std::string result = ss.str();
    // Удаляем возможный пробел в конце
    if (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        middleName = other.middleName;
        prefix = other.prefix;
        postfix = other.postfix;
    }
    return *this;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        firstName = std::move(other.firstName);
        lastName = std::move(other.lastName);
        middleName = std::move(other.middleName);
        prefix = std::move(other.prefix);
        postfix = std::move(other.postfix);
    }
    return *this;
}

bool Person::operator==(const Person& other) const {
    return firstName == other.firstName &&
           lastName == other.lastName &&
           middleName == other.middleName &&
           prefix == other.prefix &&
           postfix == other.postfix;
}

bool Person::operator!=(const Person& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.prefix << "|" << person.firstName << "|"
       << person.middleName << "|" << person.lastName << "|"
       << person.postfix;
    return os;
}

std::istream& operator>>(std::istream& is, Person& person) {
    std::getline(is, person.prefix, '|');
    std::getline(is, person.firstName, '|');
    std::getline(is, person.middleName, '|');
    std::getline(is, person.lastName, '|');
    std::getline(is, person.postfix);
    return is;
}

} // namespace publication
