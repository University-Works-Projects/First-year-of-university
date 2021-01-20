/*
Assuming this --> STACK| x  y

VM HACK code:
or: if x OR y is true puts true in stack, else false

ASSEMBLY HACK code:
If RAM[x] OR RAM[y] is true --> RAM[x] = 1, else RAM[x] = 0

(We just need change the operation of and instruction)
*/

// Commented code

    // Move to RAM[x]
    @SP
    A=M         // Go to RAM[x]
    D=M         // D = x
    
    // Move to RAM[y]
    @SP
    AM=M-1      // Now SP point to RAM[y] and we move to RAM[y]
    
    // D = x OR y and SP--
    D=D|M       // x OR y
    M=D         // RAM[x] = x OR y

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
    D=D|M
    M=D
    @SP
    M=M+1
*/