`timescale 1ns/1ns
`include "dec2to4.v"

module decoder2to4_tb();
reg [1:0]A;
reg En;
wire [3:0]D;

dec2to4 Decoder2to4(A, En, D);
initial
begin

    $dumpfile("Decoder2to4_tb.vcd");
    $dumpvars(0, decoder2to4_tb);

    A=2'b00; En=1'b0;  #20;
    A=2'b01; En=1'b0;  #20;
    A=2'b10; En=1'b0;  #20;
    A=2'b11; En=1'b0;  #20;
    A=2'b00; En=1'b1;  #20;
    A=2'b01; En=1'b1;  #20;
    A=2'b10; En=1'b1;  #20;
    A=2'b11; En=1'b1;  #20;

    $display("Test Complete");
end

endmodule  