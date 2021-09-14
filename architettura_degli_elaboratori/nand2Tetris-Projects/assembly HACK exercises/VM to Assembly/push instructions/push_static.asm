/*
VM HACK code:
push static n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @16
    A=D+A       // Now we're in RAM[static n] --> A=n+16

    D=M         // D = static n

    @SP
    A=M
    M=D         // STACK| static n

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
    @16
    A=D+A
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
*/