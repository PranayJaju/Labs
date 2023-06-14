`timescale 1ns/1ns
`include "q3ii.v"

module q3ii_tb();
reg x1, x2, x3;
wire f;

q3ii Q3ii(x1, x2, x3, f);
initial
begin

    $dumpfile("q3ii_tb.vcd");
    $dumpvars(0, q3ii_tb);

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