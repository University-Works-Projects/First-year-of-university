/*
VM HACK code:
push local n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @LCL
    A=M+D       // Now we're in RAM[local n]

    D=M         // D = local n

    @SP
    A=M
    M=D         // STACK| local n

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
    @LCL
    A=M+D
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
*/