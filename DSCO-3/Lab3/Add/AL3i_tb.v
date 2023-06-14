`timescale 1ns/1ns
`include "AL3i.v"

module AL3i_tb();
reg A, B, C, D, E;
wire f;

AL3i al3i(A, B, C, D, E, f);
initial
begin
    
    $dumpfile("AL3i_tb.vcd");
    $dumpvars(0, AL3i_tb);

    A=1'b0; B=1'b0; C=1'b0; D=1'b0; E=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b0; D=1'b0; E=1'b1; #20;

    A=1'b0; B=1'b0; C=1'b0; D=1'b1; E=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b0; D=1'b1; E=1'b1; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b0; E=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b0; E=1'b1; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b1; E=1'b0; #20;

    A=1'b0; B=1'b0; C=1'b1; D=1'b1; E=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b0; E=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b0; E=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b1; E=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b0; D=1'b1; E=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b0; E=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b0; E=1'b1; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b1; E=1'b0; #20;

    A=1'b0; B=1'b1; C=1'b1; D=1'b1; E=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b0; E=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b0; E=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b1; E=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b0; D=1'b1; E=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b0; E=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b0; E=1'b1; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b1; E=1'b0; #20;

    A=1'b1; B=1'b0; C=1'b1; D=1'b1; E=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b0; E=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b0; E=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b1; E=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b0; D=1'b1; E=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b0; E=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b0; E=1'b1; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b1; E=1'b0; #20;

    A=1'b1; B=1'b1; C=1'b1; D=1'b1; E=1'b1; #20;


    $display("Test Complete");
end

endmodule    