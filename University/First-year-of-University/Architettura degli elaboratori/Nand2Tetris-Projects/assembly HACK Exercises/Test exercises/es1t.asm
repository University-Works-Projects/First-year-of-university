// es1 test
// Assembly HACK code:
// Exercise: Translate a C program (see INDEX.txt)
// WORK

    @2
    M=0     // Clear RAM[2]=0
    @3
    M=0     // Clear RAM[3]=0

    @3
    D=A		// D=3
    @0
    M=M-D
    D=M		// D = RAM[0] - 3
    @IF
    D;JEQ	// if (RAM[0]-3) == 0  jump

    @2
    D=A
    M=D		// RAM[2] = 2 <-- We set counter var at j-1 cuz if u ve: 3*4 --> 3+3+3+3 and the first 3 is just in RAM[1]=j

    @1
    D=M
    @3
    M=D     // RAM[3] = j

 (LOOP)
    @3
    D=M		// D = j
    @1
    M=M+D	// RAM[1] += j

    @2
    M=M-1	// Multiplication counter--
    D=M
    @LOOP
    D;JGT

    @2
    M=0
    @3
    M=0

    @END
    0;JMP

 (IF)
    @1
    M=M-1

    @2
    M=0
    @3
    M=0

 (END)
    @END
    0;JMP
