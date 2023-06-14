`timescale 1ns/1ns
`include "DecomFA.v"

module DecomFA_tb();
reg x,y,z;
wire s,c;

DecomFA ha(x,y,z,s,c);
initial
begin

	$dumpfile("DecomFA.vcd");
	$dumpvars(0, DecomFA_tb);

	x=1'b0; y=1'b0; z=1'b0; #20;
	x=1'b0; y=1'b0; z=1'b1; #20;
	x=1'b0; y=1'b1; z=1'b0; #20;
	x=1'b0; y=1'b1; z=1'b1; #20;	
	x=1'b1; y=1'b0; z=1'b0; #20;
	x=1'b1; y=1'b0; z=1'b1; #20;
	x=1'b1; y=1'b1; z=1'b0; #20;
	x=1'b1; y=1'b1; z=1'b1; #20;

	$display("Test complete.");
end
endmodule