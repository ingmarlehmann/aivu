# frank

A parser for Franca models - !!!Work in progress!!!
===================================================

This project aims to develop a new alternative parser + code generator toolchain that has:
- Humanly readable error messages from the parsing stage
- Readable parser code
- Fast parsing/code generation, tailored for build systems

This project is in a very early stage, to give an overview of what has been done and what needs doing:

## Parsing/lexing (frank-parser)  
### Fidl parsing (+AST construction)  
  DONE: attributes  
  DONE: comments  
  DONE: constants (all basic types)  
  DONE: enumerations  
  DONE: implicit array declarations  
  DONE: imports  
  DONE: interfaces  
  DONE: methods  
  DONE: package declarations  
  DONE: structs  
  DONE: variable declarations  
  DONE: version information  
  TODO: explicit arrays  
  TODO: expressions  
  TODO: initializer lists  
  TODO: polymophism  

### Fdepl parsing  
  TODO: everything  
 
## Semantic analyser  
  TODO: everything  

## Code generator  
  TODO: everything  

This project is a reboot of my earlier python parser, where I was not happy with the error reporting from PLY.
