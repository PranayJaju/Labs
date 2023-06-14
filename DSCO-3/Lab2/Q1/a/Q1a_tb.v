`timescale 1ns/1ns
`include "Q1a.v"

module Q1a_tb();
reg A;
wire lhs;

Q1a q1a(A,lhs);
initial
begin

    $dumpfile("Q1a_tb.vcd");
    $dumpvars(0, Q1a_tb);

    A=1'b0; #20;

    A=1'b1; #20;

    $display("Test complete");
end

endmodule    
