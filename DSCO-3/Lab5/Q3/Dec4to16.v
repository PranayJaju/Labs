module Dec4to16(W, Y);
input [3:0]W;
output [15:0]Y;
wire[3:0]e;

dec2to4 s0(W[3:2], 1'b1, e[3:0]);

dec2to4 s1(W[1:0], ~e[0], Y[3:0]);
dec2to4 s2(W[1:0], ~e[1], Y[7:4]);
dec2to4 s3(W[1:0], ~e[2], Y[11:8]);
dec2to4 s4(W[1:0], ~e[3], Y[15:12]);

endmodule

module dec2to4(A, En, D);
    input [1:0]A;
    input En;
    output [3:0]D;
    reg [3:0]D;
    always@(A or En)
    begin
        if(En==0)D=15;
        else
        case(A)
        0: D=4'b1110;
        1: D=4'b1101;
        2: D=4'b1011;
        3: D=4'b0111;
        endcase
    end
endmodule    