#pragma once
#include "SnackSlot.h"

class VendingMachine
{
private:
    size_t id_ {0};
    u_int16_t current_slot_ {0};
    u_int16_t slotCount_ {0};
    double money_ {0.0};
    SnackSlot *slots_ {nullptr};
public:
    VendingMachine();
    VendingMachine(const u_int16_t &count);
    ~VendingMachine();

    const u_int16_t getCurrentSlot();
    void setCurrentSlot(const u_int16_t &current);

    const u_int16_t getSlotCount();
    void setSlotCount(const u_int16_t &count);

    const double getMoney();
    void setMoney(const double &money);

    void addSlot(const SnackSlot *slot);
    const u_int16_t getEmptySlotsCount();

    SnackSlot* getSlots();
    void setSlots(const SnackSlot *slots);

    void acceptMoney(const double &money);
    const double giveChange();
    Snack* dispenseSnackFromSlot();
    const u_int32_t getSnacksCount();

    friend std::ostream &operator<<(std::ostream &output, const VendingMachine &slot);
};
