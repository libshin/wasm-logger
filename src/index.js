const code = require("./code.js");

const sleep = ms => new Promise(res => setTimeout(() => res(), ms));

sleep(150).then(() => {
  code._sup();
});
