/*
VM HACK code:
push that n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @THAT
    A=M+D       // Now we're in RAM[that n]

    D=M         // D = that n

    @SP
    A=M
    M=D         // STACK| that n

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
    @THAT
    A=M+D
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
*/