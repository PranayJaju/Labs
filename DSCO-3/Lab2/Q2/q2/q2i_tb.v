`timescale 1ns/1ns
`include "q2i.v"

module q2i_tb();
reg x, y, z;
wire F;

q2i Q2i(x, y, z, F);
initial
begin

    $dumpfile("q2i_tb.vcd");
    $dumpvars(0, q2i_tb);

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