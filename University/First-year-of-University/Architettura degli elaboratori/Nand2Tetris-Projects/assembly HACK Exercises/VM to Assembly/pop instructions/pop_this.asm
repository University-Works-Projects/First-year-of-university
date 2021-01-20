/*
VM HACK code:
pop this n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @THIS
    D=M+D

    @13
    M=D         // Now in RAM[13] we saved the address "this n"

    @SP
    A=M         // Move to last stack element
    D=M

    @13
    A=M         // Move to RAM[this n]
    M=D         // RAM[this n] = last stack element

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
    @THIS
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