@20
D=A
@SP
M=D
// push constant
@7
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
// add
@SP
M=M-1
@SP
A=M
D=M
@SP
AM=M-1
D=D+M
M=D
@SP
AM=M+1
M=0
// end program
(END)
@END
0;JMP
