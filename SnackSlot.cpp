#include "SnackSlot.h"
#include "Snack.h"
#include <iostream>
#include <algorithm>

SnackSlot::SnackSlot() = default;

SnackSlot::SnackSlot(const u_int16_t &volume)
{
    this->id_ = 0;
    this->current_snack_ = 0;
    this->volume_ = volume;
    this->snacks_ = new Snack[volume];
    std::cout << "Добавлен слот № " << this->id_ << ", вместительностью " << volume << " закусок.\n";
}

SnackSlot::~SnackSlot()
{
    if (this->snacks_) {
        delete[] this->snacks_;
    }
    this->snacks_ = nullptr;
}

const u_int16_t SnackSlot::getId()
{
    return this->id_;
}

void SnackSlot::setId(const size_t &id)
{
    this->id_ = id;
}

const u_int16_t SnackSlot::getCurrentSnack()
{
    return this->current_snack_ ? this->current_snack_ - 1 : this->current_snack_;
}

void SnackSlot::setCurrentSnack(const u_int16_t &snack)
{
    if (snack < this->volume_) {
        this->current_snack_ = snack;
    }
}

const u_int16_t SnackSlot::getVolume()
{
    return this->volume_;
}

void SnackSlot::setVolume(const u_int16_t &volume)
{
    this->current_snack_ = 0;
    this->volume_ = volume;
    if (this->snacks_) {
        delete[] this->snacks_;
    }
    this->snacks_ = new Snack[volume];
}

Snack *SnackSlot::getSnacks()
{
    return this->snacks_;
}

void SnackSlot::setSnacks(const Snack *snacks)
{
//    std::copy(std::begin(&snacks), std::end(&snacks), std:begin(this->snacks_));
    for (int i = 0; i < this->volume_; ++i) {
        this->snacks_[i] = snacks[i];
    }
}

void SnackSlot::addSnack(const Snack *snack)
{
    if (this->current_snack_ < this->volume_) {
        this->snacks_[this->current_snack_] = *snack;
        std::cout << "Добавлена закуска " << *snack << " в слот № " << this->id_ << ".\n";
        ++(this->current_snack_);
    }
    else {
        std::cout << "ОШИБКА! Слот переполнен.\n";
    }
}

const u_int16_t SnackSlot::getSnacksCount()
{
    return this->current_snack_;
}

Snack *SnackSlot::dispenseSnack()
{
    Snack *result {nullptr};
    if (this->current_snack_) {
        result = &this->snacks_[this->getCurrentSnack()];
        std::cout << "Выдана закуска " << *result << " из слота № " << this->id_ << ".\n";
        --(this->current_snack_);
        if (!this->current_snack_) {
            std::cout << "ВНИМАНИЕ! Слот " << this->id_ << " пуст.\n";
        }
    }
    return result;
}

SnackSlot &SnackSlot::operator=(const SnackSlot &slot)
{
    if (this == &slot) {
        return *this;
    }
    if (this->snacks_) {
        delete[] this->snacks_;
    }
    this->id_ = slot.id_;
    this->current_snack_ = slot.current_snack_;
    this->volume_ = slot.volume_;
    this->snacks_ = new Snack[slot.volume_];
//    std::copy(std::begin(slot.snacks_), std::end(slot.snacks_), std::begin(this->snacks_));
    for (int i = 0; i < slot.current_snack_; ++i) {
        this->snacks_[i] = slot.snacks_[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &output, const SnackSlot &slot)
{
    output << "слот № " << slot.id_;
    output << ", вместительность: " << slot.volume_;
    output << ", занято: " << slot.current_snack_;
    output << ", свободно: " << slot.volume_ - slot.current_snack_;
    output << " (";
    for (int i = 0; i < slot.current_snack_; ++i) {
        if (i) output << ", ";
        output << slot.snacks_[i];
    }
    output << ")";

    return output;
}
