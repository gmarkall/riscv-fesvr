#include "term.h"
#include <termios.h>
#include <unistd.h>
#include <poll.h>
#include <signal.h>
#include <stdlib.h>

bool foreground = true;

extern "C" void ttou_handler(int signal)
{
  foreground = false;
}

class canonical_termios_t
{
 public:
  canonical_termios_t()
   : restore_tios(false)
  {
    signal(SIGTTOU, ttou_handler);

    //if (tcgetattr(0, &old_tios) == 0)
    //{
    //  struct termios new_tios = old_tios;
    //  new_tios.c_lflag &= ~(ICANON | ECHO);
    //  if (tcsetattr(0, TCSANOW, &new_tios) == 0)
    //    restore_tios = true;
    //}
  }

  ~canonical_termios_t()
  {
    if (restore_tios)
      tcsetattr(0, TCSANOW, &old_tios);
  }
 private:
  struct termios old_tios;
  bool restore_tios;
};

static canonical_termios_t tios; // exit() will clean up for us


int canonical_terminal_t::read()
{
//  if (foreground)
//  {
//    struct pollfd pfd;
//    pfd.fd = 0;
//    pfd.events = POLLIN;
//    int ret = poll(&pfd, 1, 0);
//    if (ret <= 0 || !(pfd.revents & POLLIN))
//      return -1;
//
//    unsigned char ch;
//    ret = ::read(0, &ch, 1);
//    return ret <= 0 ? -1 : ch;
//  }
//  else
    return -1;
}

void canonical_terminal_t::write(char ch)
{
  //if (foreground)
  //  if (::write(1, &ch, 1) != 1)
  //    abort();
}
