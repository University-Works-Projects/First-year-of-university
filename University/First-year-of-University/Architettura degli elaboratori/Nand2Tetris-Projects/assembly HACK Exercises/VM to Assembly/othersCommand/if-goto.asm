/*
VM HACK code:
if-goto labelName

ASSEMBLY HACK code:
It's a conditional jump
*/

// Commented code

    @SP
    A=M
    D=M            // D = last (boolean) value in stack
    
    @SP
    M=M-1           // Ci va questo decremento????

    @labelName
    D;JGT

    // Ci va l'incremento di SP????
    
    // Others instructions

/* // Code for project 6
    @SP
    A=M
    D=M
    @SP
    M=M-1
    @labelName
    D;JGT
*/