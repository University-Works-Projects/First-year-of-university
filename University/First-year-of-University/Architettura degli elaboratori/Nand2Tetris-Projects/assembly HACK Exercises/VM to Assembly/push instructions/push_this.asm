/*
VM HACK code:
push this n

ASSEMBLY HACK code:
RAM[m] = n
*/

// Commented code

    @n          // n is defined previously, so it must be a number
    D=A
    @THIS
    A=M+D       // Now we're in RAM[this n]

    D=M         // D = this n

    @SP
    A=M
    M=D         // STACK| this n

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
    @THIS
    A=M+D
    D=M
    @SP
    A=M
    M=D
    @SP
    M=M+1
*/