`timescale 1ns/1ns
`include "mux2to1.v"

module mux2to1_tb();
reg [1:0]w;
reg s;
wire f;

mux2to1 Mux2to1(w, s, f);
initial
begin
    
    $dumpfile("mux2to1.vcd");
    $dumpvars(0, mux2to1_tb);

    w=2'b00; s=1'b0; #20;
    w=2'b01; s=1'b0; #20;
    w=2'b10; s=1'b0; #20;
    w=2'b11; s=1'b0; #20;
    w=2'b00; s=1'b1; #20;
    w=2'b01; s=1'b1; #20;
    w=2'b10; s=1'b1; #20;
    w=2'b11; s=1'b1; #20;

    $display("Test complete.");
end
endmodule