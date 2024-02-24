#include "VendingMachine.h"
#include "SnackSlot.h"
#include <iostream>

VendingMachine::VendingMachine() = default;

VendingMachine::VendingMachine(const u_int16_t &count)
{
    this->id_ = 0;
    this->current_slot_ = 0;
    this->slotCount_ = count;
    this->slots_ = new SnackSlot[count];
    std::cout << "Добавлена вендинговая машина № " << this->id_ << ", вместительностью " << count << " слотов.\n";
}

VendingMachine::~VendingMachine()
{
    if (this->slots_) {
        delete[] this->slots_;
    }
    this->slots_ = nullptr;
}

const u_int16_t VendingMachine::getCurrentSlot()
{
    return this->current_slot_ ? this->current_slot_ - 1 : this->current_slot_;
}

void VendingMachine::setCurrentSlot(const u_int16_t &current)
{
    if (current < this->slotCount_) {
        this->current_slot_ = current;
    }
    else {
        std::cout << "ОШИБКА! Невозможно назначить слот № " << current << " текущим слотом. Количество слотов: " << this->slotCount_ << ".\n";
    }
}

const u_int16_t VendingMachine::getSlotCount()
{
    return this->slotCount_;
}

void VendingMachine::setSlotCount(const u_int16_t &count)
{
    if (count) {
        this->current_slot_ = 0;
        this->slotCount_ = count;
        if (this->slots_) {
            delete[] this->slots_;
        }
        this->slots_ = new SnackSlot[count];
    }
    else {
        std::cout << "ОШИБКА! Невозможно установить количество слотов: " << count << ". Текущий слот: " << this->current_slot_ << ".\n";
    }
}

const double VendingMachine::getMoney()
{
    return this->money_;
}

void VendingMachine::setMoney(const double &money)
{
    this->money_;
}

void VendingMachine::addSlot(const SnackSlot *slot)
{
    if (this->current_slot_ < this->slotCount_) {
        this->slots_[this->current_slot_] = *slot;
        std::cout << "Добавлен слот " << *slot << " в вендинговую машину № " << this->id_ << ".\n";
        ++(this->current_slot_);
    }
    else {
        std::cout << "ОШИБКА! В вендинговой машине нет места для слотов.\n";
    }
}

const u_int16_t VendingMachine::getEmptySlotsCount()
{
    std::cout << "Количество свободных слотов в вендинговой машине № " << this->id_ << ": " << (this->slotCount_ - this->current_slot_) << ".\n";
    return (this->slotCount_ - this->current_slot_);
}

SnackSlot *VendingMachine::getSlots()
{
    return this->slots_;
}

void VendingMachine::setSlots(const SnackSlot *slots)
{
    std::copy(&slots, &slots+sizeof(&slots), this->slots_);
//    std::copy(&slots, &(*slots+*slots->getCurrentSnack()), this->slots_);
//    this->slots_ = &slots;
}

void VendingMachine::acceptMoney(const double &money)
{
    this->money_ += money;
    std::cout << "Внесены деньги: " << money << "\n";
}

const double VendingMachine::giveChange()
{
    double change = this->money_;
    this->money_ = 0.0;
    std::cout << "Выдана сдача: " << change << "\n";
    return change;
}

Snack *VendingMachine::dispenseSnackFromSlot()
{
    Snack *result {nullptr};
    SnackSlot *current_slot {nullptr};
    Snack *current_snack {nullptr};
    double price {0.0};
    if (this->current_slot_) {
        current_slot = &this->slots_[this->getCurrentSlot()];
        current_snack = &current_slot->getSnacks()[current_slot->getCurrentSnack()];
        if (current_snack) {
            price = current_snack->getPrice();
            if (this->money_ >= price) {
                this->money_ -= price;
                result = current_slot->dispenseSnack();
                if (this->money_ > 0) {
                    this->giveChange();
                }
                if (!current_slot->getSnacksCount() && (this->getEmptySlotsCount() < this->getSlotCount())) {
                    --(this->current_slot_);
                }
            }
            else {
                std::cout << "ОШИБКА! Для выдачи закуски " << *current_snack << " внесите деньги в размере: " << (price - this->money_) << "\n";
            }
        }
        else {
            std::cout << "ВНИМАНИЕ! Текущая закуска отсутствует.\n";
        }
    }
    else {
        std::cout << "ВНИМАНИЕ! Текущий слот пуст.\n";
    }
    return result;
}

const u_int32_t VendingMachine::getSnacksCount()
{
    u_int32_t result {0};
    for (int i = 0; i < this->current_slot_; ++i) {
        result += this->slots_[i].getSnacksCount();
    }
    return result;
}

std::ostream &operator<<(std::ostream &output, const VendingMachine &slot)
{
    output << "№ " << slot.id_ << ", вместительность " << slot.slotCount_;
    output << " (";
    for (int i = 0; i < slot.current_slot_; ++i) {
        if (i) output << ", ";
        output << slot.slots_[i];
    }
    output << ")";

    return output;
}
