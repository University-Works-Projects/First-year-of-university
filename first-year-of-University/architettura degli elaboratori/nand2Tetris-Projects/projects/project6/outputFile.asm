@10
D=A
@SP
M=D
// push constant
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt
@SP
M=M-1
@SP
A=M
D=M
@SP
AM=M-1
D=M-D
@TRUE
D;JGT
@SP
A=M
M=0
@CONTINUE
0;JMP
(TRUE)
@SP
A=M
M=1
(CONTINUE)
@SP
AM=M+1
M=0
// end program
(END)
@END
0;JMP
