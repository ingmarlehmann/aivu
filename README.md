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
  DONE: package declarations  
  DONE: imports  
  DONE: comments  
  DONE: interfaces  
  DONE: enumerations  
  DONE: version information  
  DONE: structs  
  DONE: methods  
  DONE: implicit array declarations  
  DONE: variable declarations  
  DONE: constants (all basic types)  
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
