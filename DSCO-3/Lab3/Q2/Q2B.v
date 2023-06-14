module Q2B(A, B, C, D, f);
    input A, B, C, D;
    output f;
    assign f=(A|~B|D)&(~A|~B|C)&(~A|B|~C)&(~A|C|~D);
endmodule 