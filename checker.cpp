#include <assert.h>
#include <iostream>
using namespace std;

void printToConsole(string statement)         //impure function 
{
  cout << statement;
}

bool checkBattery(float temperature)
{
  if(temperature >= 0 && temperature <= 45)
    return true;
 
   return false;
}

bool checkSoc(float soc)
{
    if(soc >= 20 && soc <= 80) 
      return true;

    return false;
}

bool checkChargeRate(float chargeRate)
{
   if(chargeRate <= 0.8) 
    return true;
   
  return false;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
   checkBattery(temperature);
   checkSoc(soc);
   checkChargeRate(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
