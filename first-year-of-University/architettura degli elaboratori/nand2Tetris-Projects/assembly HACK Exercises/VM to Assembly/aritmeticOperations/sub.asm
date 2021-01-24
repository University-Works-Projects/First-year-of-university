/*
Assuming this --> STACK| x  y

VM HACK code:
sub: x - y

ASSEMBLY HACK code:
If RAM[x] = RAM[x] - RAM[y]

(We just need change the operation of add instruction)
*/

// Commented code

    // SP--
    @SP
    M=M-1

    // Move to RAM[y]
    @SP
    A=M         // Go to RAM[y]
    D=M         // D = y
    
    // Move to RAM[x]
    @SP
    AM=M-1      // Now SP point to RAM[x] and we move to it
    
    // RAM[x] = x - y
    M=M-D

    // SP++
    @SP
    M=M+1

    // RAM[y] = 0
    M=0

    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @SP
    AM=M+1
    @SP
    A=M
    D=M
    @SP
    AM=M-1
    M=M-D
    @SP
    AM=M+1
    M=0
*/