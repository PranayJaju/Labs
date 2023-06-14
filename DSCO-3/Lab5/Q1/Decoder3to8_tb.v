`timescale 1ns/1ns
`include "decoder3to8.v"

module decoder3to8_tb();
reg [2:0]W;
reg En;
wire [0:7]Y;

decoder3to8 Decoder3to8(W, Y);
initial
begin

    $dumpfile("Decoder3to8_tb.vcd");
    $dumpvars(0, decoder3to8_tb);

    W=3'b000; #20;
    W=3'b001; #20;
    W=3'b010; #20;
    W=3'b011; #20;
    W=3'b100; #20;
    W=3'b101; #20;
    W=3'b110; #20;
    W=3'b111; #20;

    $display("Test Complete");
end

endmodule  
