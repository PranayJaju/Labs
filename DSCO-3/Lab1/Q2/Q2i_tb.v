`timescale 1ns/1ns
`include "Q2i.v"

module Q2i_tb();
reg a, b, c, d;
wire f, g;

Q2i q2i(a, b, c, d, f, g);
initial
begin

    $dumpfile("Q2i_tb.vcd");
    $dumpvars(0, Q2i_tb);

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