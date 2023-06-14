module Q1B(A, B, C, D, f);
    input A, B, C, D;
    output f;
    assign f=(~B&C)|(~B&D)|(B&~C&~D);
endmodule 