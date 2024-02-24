#include "Snack.h"
#include <iostream>

Snack::Snack() = default;
Snack::Snack(const std::string &name) {
    this->name_ = name;
    std::cout << "Добавлена закуска " << name << ".\n";
}
Snack::Snack(const std::string &name, const u_int16_t &calories, const double &price) {
    this->name_ = name;
    this->calories_ = calories;
    this->price_ = price;
    std::cout << "Добавлена закуска " << name << ", цена: " << price << ", количество калорий: " << calories << ".\n";
}
Snack::~Snack() = default;

const std::string Snack::getName() {return this->name_;}
void Snack::setName(const std::string &name) {this->name_ = name;}

const u_int16_t Snack::getCalories()
{
    return this->calories_;
}

void Snack::setCalories(const u_int16_t &calories)
{
    this->calories_ = calories;
}

const double Snack::getPrice()
{
    return this->price_;
}

void Snack::setPrice(const double &price)
{
    this->price_ = price;
}

std::ostream &operator<<(std::ostream &output, const Snack &snack) {
    output << "{" << snack.name_ << ", " << snack.calories_ << " Ккал, " << snack.price_ << " руб.}";
    return output;
}