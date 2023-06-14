`timescale 1ns/1ns
`include "fourFA.v"

module fourFA_tb();
reg [3:0]a;reg [3:0]b;
wire [3:0]s;
wire c;

fourFA FA4(a,b,s,c);
initial
begin

	$dumpfile("fourFA.vcd");
	$dumpvars(0, fourFA_tb);

	assign a=4'b1010;
	assign b=4'b0111; 
	#20;

	$display("Test Complete.");
end
endmodule