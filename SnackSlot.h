#pragma once
#include "Snack.h"

class SnackSlot
{
private:
    size_t id_ {0};
    u_int16_t current_snack_ {0};
    u_int16_t volume_ {0};
    Snack *snacks_ {nullptr};
public:
    SnackSlot();
    SnackSlot(const u_int16_t &volume);
    ~SnackSlot();

    const u_int16_t getId();
    void setId(const size_t &id);

    const u_int16_t getCurrentSnack();
    void setCurrentSnack(const u_int16_t &snack);

    const u_int16_t getVolume();
    void setVolume(const u_int16_t &volume);

    Snack* getSnacks();
    void setSnacks(const Snack *snacks);

    void addSnack(const Snack *snack);

    const u_int16_t getSnacksCount();

    Snack* dispenseSnack();

    SnackSlot &operator=(const SnackSlot &slot);
    friend std::ostream &operator<<(std::ostream &output, const SnackSlot &slot);
};