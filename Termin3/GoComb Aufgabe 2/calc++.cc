#include <iostream>
#include "calc++-driver.hh"


int
main (int argc, char *argv[])
{
  int res = 0;
  calcxx_driver driver;
  if (argc > 1 && (argv[1] == std::string("-t") || argv[1] == std::string("-T"))){
	driver.setTestMode(true);	
  }
  std::cout << "Test Mode is " << ((driver.getTestMode()) ? "on" : "off") << std::endl;

    if (!driver.parse ("language"))
      std::cout << driver.result << std::endl;
    else
      res = 1;
  return res;
}
