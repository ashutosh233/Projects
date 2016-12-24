`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:19:25 12/04/2016 
// Design Name: 
// Module Name:    Encoder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Encoder(
    input clock,
    input [6:0] in,
	 input half,
	 input trig,
    output reg[6:0] out
    );
	 wire clock2;
	 TFF tf(clock,1,trig,clock2);
	
	reg r1h,r2h;
	reg[6:0] r1,r2,r3,a=7'b0000000;
	always@(posedge clock2 or negedge clock2)
		begin
			if( clock2)begin
				r1<=in;
				out<=r1;
				r3<=r1;
				r1h<=half;
				r2h<=r1h;
			end
			
			else 
				begin
					if((~r2h)&r3[6]&(r1[6]|(r1[5]&r1[4]))) 
						begin 
							out<=a;
							r3<=a;
						end
			
					else 
						begin
							r3<=r2;
							out <= r2;
						end
			//$display("negedge r1 = %b out= %b",r1,out);
				end
			
			//$display("posedge r1 = %b  out = %b",r1,out);
		end
	
	/*always@(negedge clock2)
	begin
			if((~r2h)&r3[6]&(r1[6]|(r1[5]&r1[4]))) 
			begin 
				out<=a;
				r3<=a;
			end
			
			else begin
			 	r3<=r2;
				out <= r2;
			end
			//$display("negedge r1 = %b out= %b",r1,out);
	end*/


endmodule
module TFF(input clk,
				input t,
				input trig,
				output reg clk2);
always@(posedge clk)
begin
	if(trig)
		clk2=0;
	else begin 
		clk2=t?~clk2:clk2;
	end
end
endmodule
