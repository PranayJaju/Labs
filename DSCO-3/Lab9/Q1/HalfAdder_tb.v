`timescale 1ns/1ns
`include "HalfAdder.v"

module HalfAdder_tb();
reg x,y;
wire s,c;

HalfAdder ha(x,y,s,c);
initial
begin

	$dumpfile("HalfAdder.vcd");
	$dumpvars(0, HalfAdder_tb);

	x=1'b0; y=1'b0; #20;
	x=1'b0; y=1'b1; #20;
	x=1'b1; y=1'b0; #20;
	x=1'b1; y=1'b1; #20;

	$display("Test complete.");
end
endmodule