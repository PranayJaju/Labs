

module decoder3to8(W, Y);
input [2:0]W;
output [0:7]Y;

decoder2to4 s1(W[1:0], ~W[2], Y[0:3]);
decoder2to4 s2(W[1:0], W[2], Y[4:7]);

endmodule

module decoder2to4(A, En, D);
    input [1:0]A;
    input En;
    output [0:3]D;
    reg [0:3]D;
    always@(A or En)
    begin
        if(En==0)D=0;
        else if(A==0)D=8;
        else if (A==1)D=4;
        else if(A==2)D=2;
        else D=1;
    end
endmodule    
