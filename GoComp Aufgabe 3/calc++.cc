#include <iostream>
#include "calc++-driver.hh"


int
main (int argc, char *argv[])
{
  int res = 0;
  calcxx_driver driver;

    if (!driver.parse ("language"))
      std::cout << driver.result << std::endl;
    else
      res = 1;
  return res;
}

