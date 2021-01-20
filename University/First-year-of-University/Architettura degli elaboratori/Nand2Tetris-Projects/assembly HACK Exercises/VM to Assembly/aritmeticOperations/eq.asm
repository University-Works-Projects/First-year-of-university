/*
Assuming this --> STACK| x  y

VM HACK code:
eq: if x == y is true puts true in stack, else false

ASSEMBLY HACK code:
If RAM[x] == RAM[y] is true --> RAM[x] = 1, else RAM[x] = 0

(We just need change the jump condition of gt or lt instructions)
*/

// Commented code

    // Move to RAM[y]
    @SP
    A=M         // Go to RAM[y]
    D=M         // D = y
    
    // Move to RAM[x]
    @SP
    AM=M-1      // Now SP point to RAM[x] and we move to it
    
    // D = y - x and SP--
    D=D-M       // y -= x

    // if case
    @TRUE
    D;JEQ       // Jump if D == 0, so only if x == y

    // else case
    M=0         // Set RAM[x] false --> RAM[x] = 0
    @CONTINUE
    0;JMP

 (TRUE)
    M=1         // Set RAM[x] true --> RAM[x] = 1

 (CONTINUE)
    @SP
    M=M+1

    // Others instructions

 (END)
    @END
    0;JMP

/* // Code for project 6
    @SP
    A=M
    D=M
    @SP
    AM=M-1
    D=D-M
    @TRUE
    D;JEQ
    M=0
    @CONTINUE
    0;JMP
 (TRUE)
    M=1
 (CONTINUE)
    @SP
    M=M+1
*/