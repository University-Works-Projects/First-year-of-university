/*
VM HACK code:
push constant n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    // Move to RAM[n]
    @n          // n is defined previously, so it must be a number
    D=A         // D=A --> D=n

    // Move to RAM[m]
    @SP
    A=M
    
    M=D         // RAM[m] = n

    // SP++
    @SP
    M=M+1
    
    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @n
    D=A
    @SP
    AM=M+1
    M=D
    @SP
    M=M+1
*/