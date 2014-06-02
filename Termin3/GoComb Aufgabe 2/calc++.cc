#include <iostream>
#include "calc++-driver.hh"


int
main (int argc, char *argv[])
{
  int res = 0;
  calcxx_driver driver;
  if (argc > 1 && (argv[1] == "-t" || argv[1] == "-T")){
	driver.setTestMode(true);	
  }

    if (!driver.parse ("language"))
      std::cout << driver.result << std::endl;
    else
      res = 1;
  return res;
}
