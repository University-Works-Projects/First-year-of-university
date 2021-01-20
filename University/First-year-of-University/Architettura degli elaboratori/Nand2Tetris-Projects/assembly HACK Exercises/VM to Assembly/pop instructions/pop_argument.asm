/*
VM HACK code:
pop argument n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @ARG
    D=M+D

    @13
    M=D         // Now in RAM[13] we saved the address "argument n"

    @SP
    A=M         // Move to last stack element
    D=M

    @13
    A=M         // Move to RAM[argument n]
    M=D         // RAM[argument n] = last stack element

    @13
    M=0         // Clear RAM[13]

    @SP
    M=M+1       // SP++
    
    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @n
    D=A
    @ARG
    D=M+D
    @13
    M=D
    @SP
    A=M
    D=M
    @13
    A=M
    M=D
    @13
    M=0
    @SP
    M=M+1
*/