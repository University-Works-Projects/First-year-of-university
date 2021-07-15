// RAM[0..9] = [10,9,..,1] = RAM[0]=10, RAM[1]=9,..., RAM[9]=1

	@10
	D=A		// D=10
	M=D		// RAM[10]=10
	@0
	D=A		// D=0
	@11
	M=D		// RAM[11]=0
 (LOOP)
	@10
	D=M		// D=RAM[10]
	@11
	A=M		// @A=@RAM[11]
	M=D		// RAM[A]=D

	@11
	MD=M+1  // D=RAM[0]-- , M=RAM[0]--
	@10
	MD=M-1  // D=RAM[0]-- , M=RAM[0]--
	@LOOP
	D;JGT

	@0
	D=A
	@11
	M=D
 (END)
	@END
	0;JMP
