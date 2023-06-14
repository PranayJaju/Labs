`timescale 1ns/1ns
`include "q1ii.v"

module q1ii_tb();
reg A, B, C;
wire Y;

q1ii Q1ii(A, B, C, Y);
initial
begin

    $dumpfile("q1ii_tb.vcd");
    $dumpvars(0, q1ii_tb);

    A=1'b0; B=1'b0; C=1'b0;
    #20;

    A=1'b0; B=1'b0; C=1'b1;
    #20;

    A=1'b0; B=1'b1; C=1'b0;
    #20;

    A=1'b0; B=1'b1; C=1'b1;
    #20;

    A=1'b1; B=1'b0; C=1'b0;
    #20;

    A=1'b1; B=1'b0; C=1'b1;
    #20;

    A=1'b1; B=1'b1; C=1'b0;
    #20;

    A=1'b1; B=1'b1; C=1'b1;
    #20;

    $display("Test complete");
end

endmodule