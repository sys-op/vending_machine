#pragma once
#include <string>

class Snack {
public:
    Snack();
    Snack(const std::string &name);
    Snack(const std::string &name, const u_int16_t &calories, const double &price);
    ~Snack();

    const std::string getName();
    void setName(const std::string &name);

    const u_int16_t getCalories();
    void setCalories(const u_int16_t &calories);

    const double getPrice();
    void setPrice(const double &price);

    friend std::ostream &operator<<(std::ostream &output, const Snack &snack);

private:
    std::string name_ {};
    u_int16_t calories_ {0};
    double price_ {0};
};