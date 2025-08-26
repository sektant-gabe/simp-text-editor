#include <termios.h>
#include <unistd.h>

void enableRawMode() {
  struct termios raw;

  tcgetattr(
      STDIN_FILENO,
      &raw); // using tcgetattr() to read the current attributes into a struct

  raw.c_lflag &= ~(ECHO); // modifying the struct by hand and

  tcsetattr(STDERR_FILENO, TCSAFLUSH,
            &raw); // passing the modified struct to tcsetattr() to write the
                   // new terminal attributes back out.
}

int main(void) {

  enableRawMode();

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
    ;

  return 0;
}
