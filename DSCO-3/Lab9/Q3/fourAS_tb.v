`timescale 1ns/1ns
`include "fourAS.v"

module fourAS_tb();
reg [3:0]a;reg [3:0]b; reg k;
wire [3:0]s;
wire c;

fourAS AS4(a,b,k,s,c);
initial
begin

	$dumpfile("fourAS.vcd");
	$dumpvars(0, fourAS_tb);

	assign k=1'b1;
	assign a=4'b1010;
	assign b=4'b0111; 
	#20;

	$display("Test Complete.");
end
endmodule