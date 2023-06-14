`timescale 1ns/1ns
`include "Q1c.v"

module Q1c_tb();
reg X, Y, Z;
wire lhs, rhs;

Q1c q1c(X, Y, Z, lhs, rhs);
initial
begin

    $dumpfile("Q1c_tb.vcd");
    $dumpvars(0, Q1c_tb);

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