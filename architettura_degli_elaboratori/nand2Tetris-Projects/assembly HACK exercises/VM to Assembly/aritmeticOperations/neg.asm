/*
    Assuming this --> STACK| x

    VM HACK code:
    neg --> x = -x

    ASSEMBLY HACK code:
    If RAM[x] = -RAM[x]

*/

// Commented code

    @SP
    A=M         // Go to RAM[x]

    M=-M        // RAM[x] = -RAM[x]

    @SP
    M=M+1       // SP++
    
    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @SP
    A=M
    M=-M
    @SP
    M=M+1
*/