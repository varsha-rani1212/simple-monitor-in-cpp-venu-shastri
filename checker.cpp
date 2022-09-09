#include <assert.h>
#include <iostream>
using namespace std;

void printToConsole(string statement)         //impure function 
{
  cout << statement;
}

bool checkBattery(float temperature)
{
  if(temperature < 0 || temperature > 45) { 
    printToConsole("Temperature out of range!\n");
    return false;
  }
  return true;
}

bool checkSoc(float soc)
{
    if(soc < 20 || soc > 80) {
    printToConsole("State of Charge out of range!\n");
    return false;
  }
  return true;
}

bool checkChargeRate(float chargeRate)
{
   if(chargeRate > 0.8) {
    printToConsole( "Charge Rate out of   range!\n);
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
   if(checkBattery == true && checkSoc == true && checkChargeRate == true)
      return true;
   return false;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
