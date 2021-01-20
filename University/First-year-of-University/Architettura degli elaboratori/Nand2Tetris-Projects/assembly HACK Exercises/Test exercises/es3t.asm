// es2 test
// Assembly HACK code:
// Exercise: Write a assembly HACK code that writes the number 10 from RAM[40] to RAM[50].
// WORK

    // RAM[52] used for take the memory address
    // RAM[51] used for counting how any times the loop will be executed
    @10
    D=A
    @51
    M=D     // RAM[51]=10

    @40
    D=A
    @52
    M=D     // RAM[52]=40

 (LOOP)
    @10
    D=A     // D=10
    @52
    A=M
    M=D     // RAM[A]=10

    @52
    M=M+1   // RAM[52]++
    @51
    MD=M-1  // RAM[51]-- (M=M-- and D=M--)
    @LOOP
    D;JGE

    @52
    M=0     // Clear RAM[52]=0
    @51
    M=0     // Clear RAM[51]=0
 (END)
    @END
    0;JMP
