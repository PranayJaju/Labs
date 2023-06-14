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
