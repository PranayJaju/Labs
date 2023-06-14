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