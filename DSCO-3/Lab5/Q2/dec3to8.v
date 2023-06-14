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