module Q2A(A, B, C, D, f);
    input A, B, C, D;
    output f;
    assign f=(B|C)&(~B|D);
endmodule 