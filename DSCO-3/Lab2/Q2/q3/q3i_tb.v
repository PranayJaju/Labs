`timescale 1ns/1ns
`include "q3i.v"

module q3i_tb();
reg x1, x2, x3;
wire f;

q3i Q3i(x1, x2, x3, f);
initial
begin

    $dumpfile("q3i_tb.vcd");
    $dumpvars(0, q3i_tb);

    x1=1'b0; x2=1'b0; x3=1'b0;
    #20;

    x1=1'b0; x2=1'b0; x3=1'b1;
    #20;

    x1=1'b0; x2=1'b1; x3=1'b0;
    #20;

    x1=1'b0; x2=1'b1; x3=1'b1;
    #20;

    x1=1'b1; x2=1'b0; x3=1'b0;
    #20;

    x1=1'b1; x2=1'b0; x3=1'b1;
    #20;

    x1=1'b1; x2=1'b1; x3=1'b0;
    #20;

    x1=1'b1; x2=1'b1; x3=1'b1;
    #20;

    $display("Test complete");
end

endmodule