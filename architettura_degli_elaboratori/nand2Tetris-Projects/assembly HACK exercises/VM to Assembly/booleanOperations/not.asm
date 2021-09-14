/*
Assuming this --> STACK| x 

VM HACK code:
not: !x

ASSEMBLY HACK code:
RAM[x] = !RAM[x]

*/

// Commented code

    // Move to RAM[x]
    @SP
    A=M         // Go to RAM[x]

    // !RAM[x]
    M=!M         // D = x
    
    // SP++
    @SP
    M=M+1

 (END)
    @END
    0;JMP

/* // Code for project 6
    @SP
    A=M
    M=!M
    @SP
    M=M+1
*/