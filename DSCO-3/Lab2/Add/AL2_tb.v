`timescale 1ns/1ns
`include "AL2.v"

module AL2_tb();
reg x1, x2, x3;
wire f;

AL2 al2(x1, x2, x3, f);
initial
begin

    $dumpfile("AL2_tb.vcd");
    $dumpvars(0, AL2_tb);

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