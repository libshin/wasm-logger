const code = require("./code.js");

const sleep = ms => new Promise(res => setTimeout(() => res(), ms));

sleep(150).then(() => {
  // Create a pointer using the 'Glue' method and the String value
  var ptr  = code.allocate(code.intArrayFromString("Hello"), 'i8', code.ALLOC_NORMAL);

  // Call the method passing the pointer
  var retPtr = code._sup(ptr);

  // Retransform back your pointer to string using 'Glue' method
  var resValue = code.Pointer_stringify(retPtr);

  // Free the memory allocated by 'allocate'
  code._free(ptr);
});
