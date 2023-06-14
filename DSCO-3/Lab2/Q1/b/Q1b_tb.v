`timescale 1ns/1ns
`include "Q1b.v"

module Q1b_tb();
reg X, Y, Z;
wire lhs, rhs;

Q1b q1b(X, Y, Z, lhs, rhs);
initial
begin

    $dumpfile("Q1b_tb.vcd");
    $dumpvars(0, Q1b_tb);

    X=1'b0; Y=1'b0; Z=1'b0;
    #20;

    X=1'b0; Y=1'b0; Z=1'b1;
    #20;

    X=1'b0; Y=1'b1; Z=1'b0;
    #20;

    X=1'b0; Y=1'b1; Z=1'b1;
    #20;

    X=1'b1; Y=1'b0; Z=1'b0;
    #20;

    X=1'b1; Y=1'b0; Z=1'b1;
    #20;

    X=1'b1; Y=1'b1; Z=1'b0;
    #20;

    X=1'b1; Y=1'b1; Z=1'b1;
    #20;

    $display("Test complete");
end

endmodule