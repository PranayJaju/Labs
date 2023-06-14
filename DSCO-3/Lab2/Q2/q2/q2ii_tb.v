`timescale 1ns/1ns
`include "q2ii.v"

module q2ii_tb();
reg x, y, z;
wire F;

q2ii Q2ii(x, y, z, F);
initial
begin

    $dumpfile("q2ii_tb.vcd");
    $dumpvars(0, q2ii_tb);

    x=1'b0; y=1'b0; z=1'b0;
    #20;

    x=1'b0; y=1'b0; z=1'b1;
    #20;

    x=1'b0; y=1'b1; z=1'b0;
    #20;

    x=1'b0; y=1'b1; z=1'b1;
    #20;

    x=1'b1; y=1'b0; z=1'b0;
    #20;

    x=1'b1; y=1'b0; z=1'b1;
    #20;

    x=1'b1; y=1'b1; z=1'b0;
    #20;

    x=1'b1; y=1'b1; z=1'b1;
    #20;

    $display("Test complete");
end

endmodule