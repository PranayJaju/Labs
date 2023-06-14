`timescale 1ns/1ns
`include "AL3ii.v"

module AL3ii_tb();
reg A, B, C, D;
wire f;

AL3ii al3ii(A, B, C, D, f);
initial
begin
    
    $dumpfile("AL3ii_tb.vcd");
    $dumpvars(0, AL3ii_tb);

    A=1'b0; B=1'b0; C=1'b0; D=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b0; D=1'b1; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b1; #20;

    $display("Test Complete");
end

endmodule    