/*
Assuming this --> STACK| x  y

VM HACK code:
and: if x AND y is true puts true in stack, else false

ASSEMBLY HACK code:
If RAM[x] AND RAM[y] is true --> RAM[x] = 1, else RAM[x] = 0

(We just need change the operation of or instruction)
*/

// Commented code

    // Move to RAM[y]
    @SP
    A=M         // Go to RAM[y]
    D=M         // D = y
    
    // Move to RAM[x]
    @SP
    AM=M-1      // Now SP point to RAM[x] and we move to it
    
    // D = y AND x
    D=D&M       // D = x AND y
    M=D         // RAM[x] = x AND y

    @SP
    M=M+1

    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @SP
    A=M
    D=M
    @SP
    AM=M-1
    D=D&M
    M=D
    @SP
    M=M+1
*/