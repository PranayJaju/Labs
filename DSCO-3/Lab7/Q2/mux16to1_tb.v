`timescale 1ns/1ns
`include "mux16to1.v"

module mux16to1_tb();
reg[15:0]w;
reg[3:0]s;
wire f;
integer i;

mux16to1 Mux16to1(w,s,f);
initial
begin

    $dumpfile("mux16to1.vcd");
    $dumpvars(0, mux16to1_tb);

    assign w=16'b1011011010100101;
    for(i=0; i<16; i=i+1) begin
        s = i; #10;
    end
    $display("Test complete.");
end
endmodule   
