module 	Q1(A, B, C, D, f);
    input A, B, C, D;
    output f;
    nand(b, B, B);
    nand(d, D, D);
    nand(Ab, A, b);
    nand(Cd, C, d);
    nand(F, Ab, Cd);
    nand(f, F, F);
endmodule