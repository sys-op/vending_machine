#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"
#include <iostream>
#include <string>

using namespace std::string_literals;

const u_int16_t slotCount {10};

int main(){
  Snack *bounty = new Snack("Bounty");
  Snack *snickers = new Snack("Snickers");
  SnackSlot *slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot->addSnack(bounty); //Добавляем батончик в слот
  slot->addSnack(snickers); 
  VendingMachine* machine = new VendingMachine(slotCount /*Количество слотов для снеков*/);
  machine->addSlot(slot); // Помещаем слот обратно в аппарат
 
  std::cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков

  std::cout << "\n";

  Snack *bounty2 = new Snack("Bounty"s, 200, 100.0);
  Snack *snickers2 = new Snack("Snickers"s, 300, 150.0);
  Snack *twix2 = new Snack("Twix"s, 250, 125.0);
  SnackSlot *slot2 = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot2->setId(1);
  slot2->addSnack(bounty2); //Добавляем батончик в слот
  slot2->addSnack(snickers2); 
  slot2->addSnack(twix2);

  Snack *bounty3 = new Snack("Bounty"s, 200, 100.0);
  Snack *snickers3 = new Snack("Snickers"s, 300, 150.0);
  Snack *twix3 = new Snack("Twix"s, 250, 125.0);
  Snack *nuts3 = new Snack("Nuts"s, 400, 175.0);
  SnackSlot *slot3 = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot3->setId(2);
  slot3->addSnack(bounty3); //Добавляем батончик в слот
  slot3->addSnack(snickers3); 
  slot3->addSnack(twix3); 
  slot3->addSnack(nuts3); 

  machine->addSlot(slot2); // Помещаем слот обратно в аппарат
  machine->addSlot(slot3); // Помещаем слот обратно в аппарат

  std::cout << "Всего закусок в вендинговой машине: " << machine->getSnacksCount() << "\n";
  std::cout << *machine << "\n";

  /* Тест */
  
  SnackSlot *cur_slot = &machine->getSlots()[machine->getCurrentSlot()];
  Snack *cur_snack = &cur_slot->getSnacks()[cur_slot->getCurrentSnack()];
  cur_snack->setPrice(100.0);
  
  machine->acceptMoney(50.0);
  Snack *wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }
  machine->acceptMoney(50.1);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  machine->acceptMoney(1000);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  machine->acceptMoney(1000);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  machine->acceptMoney(1000);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  machine->acceptMoney(1000);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  machine->acceptMoney(1000);
  wanted_snack = machine->dispenseSnackFromSlot();
  if (wanted_snack) {
    std::cout << "Получена закуска " << *wanted_snack << "\n";
  }
  else {
    std::cout << "Закуска не получена (\n";
  }

  std::cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
  std::cout << "\nВсего закусок в вендинговой машине: " << machine->getSnacksCount() << "\n";
  std::cout << *machine << "\n";

  /* Конец теста */

  delete machine;
  delete slot;
  delete snickers;
  delete bounty;

  return 0;
}