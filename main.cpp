#include "Server.h"
//#include "Client.h"
#include "PiGPIO.h"
#include <thread>
#include <string>

void test()
{
  std::cout << "Test" << '\n';
}

int main(int argc, char const *argv[])
{
  //Client client;
  PiGPIO gpioPi("3");
  std::string gpioResult;
  std::string keyboardResult;
  const char *hello = "Program exiting";

  gpioPi.setdir_gpio("in");

  while(1)
  {
    gpioPi.getval_gpio(gpioResult);

    std::cin >> keyboardResult;

    if(keyboardResult == "hej")
    {
      std::cout << "Keyboard trigger" << '\n';
    }
    else if(keyboardResult == "exit")
      break;
    else if(gpioResult == "1")
    {
      std::cout << "GPIO trigger" << '\n';
    }

  /*
  Server server;
  std::thread t1(&Server::Listen, &server);
  t1.join();
  std::thread t2(test);
  t2.join();
  std::cout << hello << '\n';
  */
  }
  return 0;
}
