`timescale 1ns/1ns
`include "Q2.v"

module Q2_tb();
reg A, B, C, D;
wire f;

Q2 q2(A, B, C, D, f);
initial
begin
    
    $dumpfile("Q2_tb.vcd");
    $dumpvars(0, Q2_tb);

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