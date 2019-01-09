const code = require("./code.js");

module.exports = (req, res, next) => {
  const methodPtr = code.allocate(code.intArrayFromString(req.method), "i8", code.ALLOC_NORMAL);
  code._run(methodPtr);
  code._free(methodPtr);
  next();
};
