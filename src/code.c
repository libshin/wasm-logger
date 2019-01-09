#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <emscripten.h>

/* Represents a message and an output channel */
typedef struct Comms {
  char msg[64];
  uint16_t msg_len;
  void (*out)(const char *);
  void (*eval)(const char *);
} Comms;


void trigger(Comms *comms) {
  comms->out(comms->msg);
}

void communicate(const char *msg) {
  char str[80];
  strcpy(str, "console.log(`");
  strcat(str, msg);
  strcat(str, "`);");

  emscripten_run_script(str);
}

EMSCRIPTEN_KEEPALIVE
void run(char *msg) {
  Comms comms;
  comms.out = &communicate;
  comms.eval = &emscripten_run_script;
  
  memcpy(comms.msg, msg, strlen(msg));
  trigger(&comms);

  return;
}
