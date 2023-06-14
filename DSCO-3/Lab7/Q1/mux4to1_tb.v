`timescale 1ns/1ns
`include "mux4to1.v"

module mux4to1_tb();
reg [3:0]w;
reg [1:0]s;
wire f;
integer i;

mux4to1 Mux4to1(w, s, f);
initial
begin

    $dumpfile("mux4to1_tb.vcd");
    $dumpvars(0, mux4to1_tb);

    assign w=4'b1011;
    for(i=0; i<4; i=i+1) begin
        s = i; #10;
    end
    $display("Test complete.");
end
endmodule    