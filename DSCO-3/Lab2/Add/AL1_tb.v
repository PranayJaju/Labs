`timescale 1ns/1ns
`include "AL1.v"

module AL1_tb();
reg x1, x2, x3;
wire f;

AL1 al1(x1, x2, x3, f);
initial
begin

    $dumpfile("AL1_tb.vcd");
    $dumpvars(0, AL1_tb);

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