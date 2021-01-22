/*
Assuming this --> STACK| x  y

VM HACK code:
sub: x - y

ASSEMBLY HACK code:
If RAM[x] = RAM[x] - RAM[y]

(We just need change the operation of add instruction)
*/

// Commented code

    // Move to RAM[y]
    @SP
    A=M         // Go to RAM[y]
    D=M         // D = y
    
    // Move to RAM[x]
    @SP
    AM=M-1      // Now SP point to RAM[x] and we move to it
    
    // D = y - x
    D=D-M       // x -= y
    M=D         // RAM[x] = y - x

    // SP++
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
    D=D-M
    M=D
    @SP
    M=M+1
*/