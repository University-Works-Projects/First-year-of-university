/*
VM HACK code:
push argument n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @ARG
    A=M+D       // Now we're in RAM[argument n]

    D=M         // D = argument n

    @SP
    A=M
    M=D         // STACK| argument n

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
    @ARG
    A=M+D
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
*/