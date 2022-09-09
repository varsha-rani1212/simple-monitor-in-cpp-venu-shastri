#include <assert.h>
#include <iostream>
using namespace std;

void printToConsole(string statement)         //impure function 
{
  cout << statement;
}

void dummyFunction(){}

bool checkTemperature(float temperature, void *print)
{
  if(temperature >= 0 && temperature <= 45)
    return true;
 
   print("Temperature out of range!\n");
   return false;
}

bool checkSoc(float soc,void *printToConsole)
{
    if(soc >= 20 && soc <= 80) 
      return true;

    printToConsole("State of Charge out of range!\n");
    return false;
}

bool checkChargeRate(float chargeRate,void *printToConsole)
{
   if(chargeRate <= 0.8) 
    return true;
  
  printToConsole("State of Charge out of range!\n"); 
  return false;
}

bool batteryIsOk(float temperature, float soc, float chargeRate,void *dummyFunction) {
  
   bool isTempOk = checkTemperature(temperature, &PrintToConsole);
   bool isSocOk = checkSoc(soc, &PrintToConsole);
   bool isChargeRateOk = checkChargeRate(chargeRate, &PrintToConsole);
  
   return isTempOk && isSocOk && isChargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7, &dummyFunction) == true);
  assert(batteryIsOk(50, 85, 0, &dummyFunction) == false);
}
