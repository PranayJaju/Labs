module dec4to16(W, Y);
input [3:0]W;
output [15:0]Y;

dec3to8 s1(W[2:0], ~W[3], Y[7:0]);
dec3to8 s2(W[2:0], W[3], Y[15:8]);

endmodule

module dec3to8(W, En, Y);
    input [2:0]W;
    input En;
    output reg [7:0]Y;
    integer i;
    always @(W or En) begin
        if(En==0)
        Y=0;
        else
        for(i=0; i<8; i=i+1)
        if(W==i) Y[i]=1;
        else Y[i]=0;
    end
endmodule   