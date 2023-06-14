`timescale 1ns/1ns
`include "dec3to8.v"

module dec3to8_tb();
reg [3:0]W;
reg En;
wire [7:0]Y;

dec3to8 Dec3to8(W, En, Y);
initial
begin

    $dumpfile("Dec3to8_tb.vcd");
    $dumpvars(0, dec3to8_tb);

    W=3'b000; En=1'b1; #20;
    W=3'b001; En=1'b1; #20;
    W=3'b010; En=1'b1; #20;
    W=3'b011; En=1'b1; #20;
    W=3'b100; En=1'b1; #20;
    W=3'b101; En=1'b1; #20;
    W=3'b110; En=1'b1; #20;
    W=3'b111; En=1'b1; #20;

    $display("Test Complete");
end

endmodule