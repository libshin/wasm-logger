Wasm, short for WebAssembly, is a new technology that allows web developers to run high level languages on a webpage with near-native performance. Wasm is slowly gaining in popularity due to its adaptablity with different languages. Developers that are used to their favourite programming languages can compile their codes wouldn't have to master JavaScript in order to build a web application. 

However, being able to compile other languages is not all roses. Take for instance C, which suffers from a large variety of known exploits. Compiling this language means deploying known exploits of said language on the web, which could cause a major security flaw on any application.

We will explain how Wasm works, how it handles memory, and what makes it efficient in computing other languages on a browser.
Throughout the presentation, we will perform an XSS attack on a node server, running a wasm application, in order to remote execute code on the server.

Additionally, we will see what becomes of WASM knowing what these exploits can do.

Our research was mainly based on the conference made in blackhat (https://i.blackhat.com/us-18/Thu-August-9/us-18-Lukasiewicz-WebAssembly-A-New-World-of-Native_Exploits-On-The-Web-wp.pdf)
