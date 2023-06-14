`timescale 1ns/1ns
`include "Q1ii.v"

module Q1ii_tb();
reg a, b, c, d;
wire f;

Q1ii q1ii(a, b, c, d, f);
initial
begin

    $dumpfile("Q1ii_tb.vcd");
    $dumpvars(0, Q1ii_tb);

    a=1'b0; b=1'b0; c=1'b0; d=1'b0;
    #20;

    a=1'b0; b=1'b0; c=1'b0; d=1'b1;
    #20;
    
    a=1'b0; b=1'b0; c=1'b1; d=1'b0;
    #20;
    
    a=1'b0; b=1'b0; c=1'b1; d=1'b1;
    #20;
    
    a=1'b0; b=1'b1; c=1'b0; d=1'b0;
    #20;
    
    a=1'b0; b=1'b1; c=1'b0; d=1'b1;
    #20;
    
    a=1'b0; b=1'b1; c=1'b1; d=1'b0;
    #20;
    
    a=1'b0; b=1'b1; c=1'b1; d=1'b1;
    #20;
    
    a=1'b1; b=1'b0; c=1'b0; d=1'b0;
    #20;
    
    a=1'b1; b=1'b0; c=1'b0; d=1'b1;
    #20;
    
    a=1'b1; b=1'b0; c=1'b1; d=1'b0;
    #20;
    
    a=1'b1; b=1'b0; c=1'b1; d=1'b1;
    #20;
    
    a=1'b1; b=1'b1; c=1'b0; d=1'b0;
    #20;
    
    a=1'b1; b=1'b1; c=1'b0; d=1'b1;
    #20;
    
    a=1'b1; b=1'b1; c=1'b1; d=1'b0;
    #20;
    
    a=1'b1; b=1'b1; c=1'b1; d=1'b1;
    #20;
    
    $display("Test complete");
end

endmodule    