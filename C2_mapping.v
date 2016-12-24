`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:47:43 12/02/2016 
// Design Name: 
// Module Name:    C2_mapping 
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
module C2_mapping(input[6:0] hindi,					
						input clock,
						output reg[6:0] r5
    );
	 reg a,B,v_c_h,on;						//vowel_~consonant_half
	 reg[6:0]  english,r1,r2,r3,r4;
	 always@(posedge clock)
begin
			$display("r1=%b",r1[6]);
		  v_c_h=~hindi[6];
		  a<=v_c_h;
		  B<=a;
        case(hindi)
                7'b0000000 : english = 7'b0000000;
                7'b0000001 : english = 7'b0010101;
                7'b0000010 : english = 7'b0000010;
                7'b0000011 : english = 7'b0010110;
                7'b0000100 : english = 7'b0000100;
                7'b0000101 : english = 7'b0010111;
                7'b0000110 : english = 7'b0000001;
                7'b0000111 : english = 7'b0011000;
                7'b0001000 : english = 7'b0000011;
                7'b0001001 : english = 7'b0011001;
                7'b0001010 : english = 7'b0011010;
                7'b0001011 : english = 7'b0011011;
                7'b0001100 : english = 7'b0011100;//
                7'b1000000 : english = 7'b1000111;
                7'b1000001 : english = 7'b1011101;
                7'b1000010 : english = 7'b1000100;
                7'b1000011 : english = 7'b1011110;	
                7'b1000100 : english = 7'b1011111;
                7'b1000101 : english = 7'b1100000;
                7'b1000110 : english = 7'b1100001;
                7'b1000111 : english = 7'b1000110;
                7'b1001000 : english = 7'b1100010;
                7'b1001001 : english = 7'b1100011;
                7'b1001010 : english = 7'b1001111;
                7'b1001011 : english = 7'b1100100;
                7'b1001100 : english = 7'b1000010;
                7'b1001101 : english = 7'b1100101;
                7'b1001110 : english = 7'b1001010;
                7'b1001111 : english = 7'b1000010;
                7'b1010000 : english = 7'b1100110;
                7'b1010001 : english = 7'b1001111;
                7'b1010010 : english = 7'b1100111;
                7'b1010011 : english = 7'b1000010;
                7'b1010100 : english = 7'b1101000;
                7'b1010101 : english = 7'b1001010;        
                7'b1010110 : english = 7'b1001011;
                7'b1010111 : english = 7'b1101001;
                7'b1011000 : english = 7'b1000000;
                7'b1011001 : english = 7'b1101010;
                7'b1011010 : english = 7'b1001001;
                7'b1011011 : english = 7'b1010011;
                7'b1011100 : english = 7'b1001101;
                7'b1011101 : english = 7'b1001000;
                7'b1011110 : english = 7'b1010000;
                7'b1011111 : english = 7'b1101011;
                7'b1100000 : english = 7'b1101011;
                7'b1100001 : english = 7'b1001110;
                7'b1100010 : english = 7'b1000101;
                7'b1100011 : english = 7'b1101101;
                7'b1100100 : english = 7'b1101110;
                7'b1100101 : english = 7'b1101111;
                7'b0110000 : english = (B|a?7'b1110000:7'b1110001 );
					 7'bxxxxxxx : english = 7'bzzzzzzz;
				
        endcase
		  $display("%d %d %d %d %d %d   on=%d",english[6],r1[6],r2[6],r3[6],r4[6],r5[6],on);
		  
		  if((r1[6])&(~r2[6])&(r3[6])&(~r4[6])&(~english[6]))
		  
			begin
					on=1;
				if(r2==7'b0000000)begin
				r1<=english;
				r3<=r1;
				r4<=r3;
				r5<=r4;
				
				end
			end
			else if(on) begin
				r1<=english;
				r3<=r1;
				r4<=r3;
				r5<=r4;
			end
		  else begin 
				r1<=english;
				r2<=r1;
				r3<=r2;
				r4<=r3;
				r5<=r4;
		  end
			
end
endmodule
