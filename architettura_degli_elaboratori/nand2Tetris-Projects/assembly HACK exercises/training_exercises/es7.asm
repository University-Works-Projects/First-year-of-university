// RAM[2] = RAM[0] - RAM[1] - 2

	@2
	M=0

	@0
	D=M
	@1
	D=D-M
	@2
	M=D

	M=M-1
	M=M-1

 (END)
	@END
	0;JMP
