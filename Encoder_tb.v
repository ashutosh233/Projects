`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:54:47 12/04/2016
// Design Name:   Encoder
// Module Name:   E:/Translation/Encoder_tb.v
// Project Name:  Translation
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Encoder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Encoder_tb;

	// Inputs
	reg clock;
	reg [6:0] in;
	reg half;
	reg trig;
	// Outputs
	wire [6:0] out;
	// Instantiate the Unit Under Test (UUT)
	Encoder uut (
		.clock(clock), 
		.in(in), 
		.half(half),
		.trig(trig),
		.out(out)
	);
	/*
	v van				1011110	*
	y yagy			1011011
	k kabutar		1000000	*
	t 					1010001
	i imli			0000010
	' '				0110000
	
	v van				1011110	*
	y yagy			1011011
	a					0000000
	k kabutar		1000000	*
	t 					1010001
	i imli			0000010
	' '				0110000
	*/
	initial begin
		// Initialize Inputs
		clock = 0;
		in = 7'b1011110;
		half = 1;
		trig=1;
		// Wait 100 ns for global reset to finish
		#60 trig=0;
		#100;
		half=0;
      in = 7'b1011011; 
		#100;
		half=1;
      in = 7'b1000000;
		#100;
		half=0;
      in = 7'b1010001;
		#100;
      in = 7'b0000010;
		#100;
      in = 7'b0110000;
		// Add stimulus here

	end
	
	always
	#25 clock=~clock;
      
endmodule

