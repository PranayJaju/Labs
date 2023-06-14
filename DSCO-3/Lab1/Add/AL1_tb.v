`timescale 1ns/1ns
`include "AL1.v"

module AL1_tb();
reg a, b, c;
wire f1, f2;

AL1 al1(a, b, c, f1, f2);
initial
begin

    $dumpfile("AL1_tb.vcd");
    $dumpvars(0, AL1_tb);

    a=1'b0; b=1'b0; c=1'b0; 
    #20;

    a=1'b0; b=1'b0; c=1'b1; 
    #20;
    
    a=1'b0; b=1'b1; c=1'b0; 
    #20;
    
    a=1'b0; b=1'b1; c=1'b1; 
    #20;
    
    a=1'b1; b=1'b0; c=1'b0; 
    #20;
    
    a=1'b1; b=1'b0; c=1'b1; 
    #20;
    
    a=1'b1; b=1'b1; c=1'b0; 
    #20;
    
    a=1'b1; b=1'b1; c=1'b1; 
    #20;
    
    
    $display("Test complete");
end

endmodule    